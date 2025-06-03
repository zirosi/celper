#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeProject(char projectName[50]) {
    char projectType[50];
    
    char srcPath[75];
    strcpy(srcPath, projectName);
    strcat(srcPath, "/src");
    char buildPath[75];
    strcpy(srcPath, projectName);
    strcat(srcPath, "/build");

    printf("What project type do you want (basic, raylib)\n");
    printf("> "); scanf("%49s", projectType);
    
    if (strcmp(projectType, "basic") == 0) {
        char command[80];
        char command2[80];
        char command3[80];

        strcpy(command, "mkdir ");
        strcat(command, projectName);
        system(command);

        strcpy(command3, "mkdir ");
        strcat(command3, srcPath);
        system(command3);

        strcpy(command2, "mkdir ");
        strcat(command2, buildPath);
        system(command2);
    }
}

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
            return 0;
        } else if (strcmp(argv[i], "--help") == 0) {
            helpPromt();
            return 0;
        } else if (strcmp(argv[i], "-m") == 0) {
            makeProject(&*argv[i+1]);
            return 0;
        }
    }

    return 0;
}