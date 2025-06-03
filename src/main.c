#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

void makeProject(char projectName[50]) {
    char projectType[50];
    char srcPath[75];
    char buildPath[75];
    char mainPath[80];

    snprintf(srcPath, 75, "%s/src", projectName);
    snprintf(buildPath, 75, "%s/build", projectName);
    snprintf(mainPath, 80, "%s/main.c", srcPath);

    printf("What project type do you want (basic)\n");
    printf("> "); scanf("%49s", projectType);
    
    if (strcmp(projectType, "basic") == 0) {
        FILE *main;

        mkdir(projectName, 0777);
        mkdir(srcPath, 0777);
        mkdir(buildPath, 0777);

        main = fopen(mainPath, "w");
        fclose(main); 
        
    } else {
        printf("%s is not a project type\n", projectType);
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