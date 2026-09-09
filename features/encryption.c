#include "encryption.h"


int XOR(Encryptor* enc) {
        for (int i = 0; i < enc->payload_length; i++)
                enc->encrypted[i] = enc->payload[i] ^ enc->key[i % enc->key_length];
        return 0; // always returns 0, not much to fail
}

// add stuff here
int (*enc_fgptr[])(Encryptor*) = {XOR};


int output(const unsigned char* encrypted, int payload_length) {
        FILE* fptr = fopen("output.bin", "wb");
        if (!fptr) {
                printf("[ERROR] bad fopen\n");
                return -1;
        }

        if (fwrite(encrypted, 1, payload_length, fptr) != (size_t)payload_length) {
                printf("[ERROR] bad fwrite\n");
                return -2;
        }

        fclose(fptr);
        printf("[INFO] output.bin created, shellcode stored\n");

        return 0;
}

// returns Encryptor type struct, which contains all that is needed for encryption,
Encryptor* encrypt(const unsigned char* payload, int payload_length, const unsigned char* key, int key_length, _Bool positional, int cypher) {
        if (key_length < 1) {
                printf("[Warning] key length less than 1, presuming 1 byte key\n");
                key_length = 1;
        }
        
        Encryptor* enc = (Encryptor*) calloc(1, sizeof(Encryptor));
        if (!enc) {
                printf("[ERROR] bad calloc on Encryptor struct\n");
                return NULL;
        }

        enc->payload = payload;
        enc->payload_length = payload_length;
        enc->key = key;
        enc->key_length = key_length;
        enc->positional = positional;
        enc->encrypted_length = positional == 1 ? enc->payload_length : enc->payload_length + key_length;
        enc->encrypted = (unsigned char*) malloc(enc->encrypted_length * sizeof(unsigned char) + 1);
        if (!enc->encrypted) {
                printf("[ERROR] bad malloc on encrypted char array\n");
                free(enc);
                return NULL;
        }
        
        enc_fgptr[cypher < 0 ? 0 : cypher % ARRAY_LEN(enc_fgptr)](enc);
        if (positional == 0) memcpy(enc->encrypted + enc->payload_length, enc->key, enc->key_length);
        printf("[INFO] shellcode encrypted\n");

        output(enc->encrypted, enc->encrypted_length);
        
        return enc;
}