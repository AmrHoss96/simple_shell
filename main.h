#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void execmd(char **argv);
char *get_location(char *command);
char* read_line(void);
char** tokenize_line(char* line);
int execute_command(char** args);
void free_tokens(char** tokens);

#endif