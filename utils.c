#include "utils.h"

#define BOLD_ANSI "\033[1m"
#define ESC_ANSI "\033[0m"

void print_usage(_Bool failed, const char* charPtr) {


        printf(
        "This program is designed for shellcode encryption, binary metadata stripping, obfuscation \n",        
                
                
        "User-added modules requirements:\n",
        "> the functions must be housed in ", BOLD_ANSI, "enc_fgptr", ESC_ANSI, "\n",
        "> and must take in Encryptor* struct and return an integer\n"
        "The modules must be present during compilation and added correctly\n");

        if (failed == 1) printf("[ERROR] %s\n", charPtr);
}


void signal_handler(int sig) {
        (void)sig;
}