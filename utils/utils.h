#pragma once

#include <stdio.h>
#include <string.h>
#include <signal.h>

void print_usage(_Bool failed, const char* charPtr);
void signal_handler(int sig);