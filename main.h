#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* Libraries */
#include <unistd.h>        /* Provides access to the POSIX operating system API */
#include <stdio.h>         /* Standard input/output library */
#include <string.h>        /* String handling functions */
#include <sys/types.h>     /* Definitions of data types used in system calls */
#include <stdlib.h>        /* Standard library for memory allocation, control processes, etc. */
#include <sys/wait.h>      /* Declarations for waiting for processes */
#include <sys/stat.h>      /* Declarations for file I/O and file system stat functions */

/* Main Functions */
char **tokenization(char *str, char *delim); /* Splits a string into tokens based on the delimiter */
int execution(char **tokens, char **env); /* Executes a program based on the tokens */
char *path(char **env); /* Retrieves the PATH environment variable */
char *add_path(char **tokens, char **path_tok); /* Adds PATH to the tokens for command execution */
int input_control(char **tokens); /* Controls and validates the input tokens */

/* Support Functions */
int _strlen(char *s); /* Calculates the length of a string */
char *_strcpy(char *dest, char *src); /* Copies a string from src to dest */
int _strcmp(char *comparing, char *compare); /* Compares two strings */
void free_array(char **tokens); /* Frees a 2D array of tokens */
int _strncmp(char *comparing, char *compare, size_t n); /* Compares two strings up to n bytes */
char *_strdup(char *s); /* Duplicates a string */
char *_strcat(char *dest, char *src); /* Concatenates two strings */

#endif
