#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>

#include <string>
#include <vector>

void PrintSystemVersion() {
    printf("verson 0.1 \n");
}

void HelpInfo(int argc, char* argv[]) {
    printf("hello client \n");
}

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "version") {
        PrintSystemVersion();
        return 0;
    } else if (argc > 1 && std::string(argv[1]) == "help") {
        HelpInfo(argc, argv);
        return 0;
    }
	
    if (argc == 1) {
        char* line = NULL;

        while ((line = readline("infinite > ")) != NULL) {
            char* line_copy = strdup(line);
            std::vector<char*> arg_list;
            arg_list.push_back(argv[0]);
            char* tmp = NULL;
            char* token = strtok_r(line, " \t", &tmp);
            while (token != NULL) {
                arg_list.push_back(token);
                token = strtok_r(NULL, " \t", &tmp); 
            }
            if (arg_list.size() == 2 && (strcmp(arg_list[1], "quit") == 0 || 
                                        strcmp(arg_list[1], "exit") == 0 ||
                                        strcmp(arg_list[1], "q") == 0)) {
                free(line_copy);
                free(line);
                break;
            }
            if (arg_list.size() > 1) {
                add_history(line_copy);
            //    ret = ExecuteCommand(client, arg_list.size(), &arg_list[0]);
            }
            free(line_copy);
            free(line);
        }
    } else {
            //    ret = ExecuteCommand(client, arg_list.size(), &arg_list[0]);
    }
}
