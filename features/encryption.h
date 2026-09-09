#pragma once
#include "defines.h"
#include <stdlib.h>
#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))


Encryptor* encrypt(const unsigned char* payload, int payload_length, const unsigned char* key, int key_length, _Bool positional, int cypher);