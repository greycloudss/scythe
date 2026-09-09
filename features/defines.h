#pragma once
#include <stdio.h>
#include <string.h>


typedef struct Encryptor {
        const unsigned char* payload;
        int payload_length;
        const unsigned char* key;
        int key_length;
        
        _Bool positional;
        
        int encrypted_length;
        unsigned char* encrypted;
} Encryptor;