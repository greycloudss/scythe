#include "main.h"



int main(int argc, const char* argv[]) {
        signal(SIGINT, signal_handler);
        signal(SIGTERM, signal_handler);
        signal(SIGQUIT, signal_handler);
        return 0;
}