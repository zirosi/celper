#include <stdio.h>

int main (int argc, char *argv[]) {
    char celperVersion[] = "0.0.1";

    if(argc == 1) {
        printf("Celper Version %s, please run -h for help\n", celperVersion);
    } 
    return 0;
}