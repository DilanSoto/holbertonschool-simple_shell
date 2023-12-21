#include "main.h"

/**
 * tokenization - Extracts tokens from the command line
 * @line: String of the command line
 * @delimiter: Delimiter to tokenize the string
 * Return: Array of tokens
 */
char **tokenization(char *line, char *delimiter)
{
    char *token = NULL, **tokens = NULL;
    int index = 0;

    tokens = malloc(sizeof(char *) * 10);
    if (!tokens)
        return (NULL);

    token = strtok(line, delimiter);

    while (token)
    {
        tokens[index] = malloc(sizeof(char) * _strlen(token) + 1);
        if (tokens[index] == NULL)
        {
            free_array(tokens);
            return (NULL);
        }
        _strcpy(tokens[index], token);
        index++;
        token = strtok(NULL, delimiter);
    }
    tokens[index] = NULL;

    return (tokens);
}

/**
 * execution - Executes a command
 * @cmd_tokens: Tokenized command
 * @env: Environment variables
 * Return: 1 if command executed, 0 otherwise
 */
int execution(char **cmd_tokens, char **env)
{
    pid_t child_pid;
    int status;
    char *path_tokens, **path_parts;
    struct stat buffer;

    if (stat(cmd_tokens[0], &buffer) != 0)
    {
        path_tokens = path(env);
        path_parts = tokenization(path_tokens, ":");
        free(path_tokens);
        cmd_tokens[0] = add_path(cmd_tokens, path_parts);
        if (stat(cmd_tokens[0], &buffer) != 0)
        {
            free_array(path_parts);
            free_array(cmd_tokens);
            perror("Command not found");
            return (0);
        }
    }
    child_pid = fork();
    if (child_pid == -1)
        perror("Child process failed");
    else if (child_pid == 0)
    {
        if (execve(cmd_tokens[0], cmd_tokens, env) == -1)
            perror("Execution error");
    }
    else
        wait(&status);
    free_array(cmd_tokens);

    return (1);
}

/**
 * input_control - Checks if the first token is 'exit'
 * @tokens: Array of tokens
 * Return: 1 if not exit, 0 if exit
 */
int input_control(char **tokens)
{
    if (_strcmp(tokens[0], "exit") == 0)
    {
        free_array(tokens);
        exit(0);
    }
    return (1);
}