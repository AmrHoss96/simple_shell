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
void execmd(char **argv);
char *get_location(char *command);
ssize_t read_line(char **lineptr, size_t *n);
void run_shell(void);

#endif
