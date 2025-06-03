#include <stdio.h>
#include <string.h>

void helpPromt(void) {
    printf("celper <command>\n\n");
    printf("-h     --help - Shows the help screen\n");
    printf("       --version - shows the current version\n");
}

int main (int argc, char *argv[]) {
    char celperVersion[] = "0.0.1";

    if(argc == 1) {
        printf("Celper Version %s, please run -h or --help for help\n", celperVersion);
    } 

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {
            printf("Celper Version: %s\n", celperVersion);
            return 0;
        } else if (strcmp(argv[i], "-h") == 0) {
            helpPromt();
        } else if (strcmp(argv[i], "--help") == 0) {
            helpPromt();
        }
    }

    return 0;
}