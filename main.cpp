#include <stdio.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char** argv) {
    const char* helpMessage = "All program options:\n"
        "-h, --help                          - get notified about helpMessage\n"
        "-v, --version                       - get the program version\n"
        "-n, --name                          - get the name of the program\n"
        "-l[<val1>,...], --list=[<num1>,...] - print list of arguments\n";

    struct archiLook {
        bool h = false;
        bool l = false;
        bool v = false;
        bool n = false;
        
    }archiLook;

    static struct option lOpt[] = {
        {"help",    no_argument,       0, 'h'},
        {"version", no_argument,       0, 'v'},
        {"list",    required_argument, 0, 'l'},
        {"name",    no_argument,       0, 'n'},
        {0, 0, 0, 0},
    };

    const char* optionStr = "hvnl:";
    int optInd;
    int res;


    while ((res = getopt_long(argc, argv, optionStr,
        lOpt, &optInd)) != -1) {
        switch (res) {
            case 'h': {
                if (!archiLook.h) {
                    printf("%s\n", helpMessage);
                    archiLook.h = true;
                }
                break;
            }
            case 'v': {
                if (!archiLook.v) {
                    printf("Your version is: 20.7.0\n");
                    archiLook.v = true;
                }
                break;
            }
            case 'l': {
                if (!archiLook.l) {
                    printf("List of arguments: { ");
                    char* elem = strtok(optarg, ",");
                    while (elem != NULL) {
                        printf("%s ", elem);
                        elem = strtok(NULL, ",");
                    }
                    printf("}\n");
                    archiLook.l = true;
                }
                break;
            }
            case 'n': {
                if (!archiLook.n) {
                    printf("Name of program is 'AK2_Lab3'\n");
                    archiLook.n = true;
                }
                break;
            }
            default: {
                printf("Please, entered type -h to see the list of arguments\n");
                return 0;
            }
        }
    }
    return 0;
}