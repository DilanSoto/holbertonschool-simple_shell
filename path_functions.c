#include "main.h"

/**
 * path - Retrieves the PATH environment variable
 * @env: Environment variables
 * Return: Path variable as a string
 */
char *path(char **env)
{
    int i = 0;
    char *path_value, **path_tokens;

    while (env[i])
    {
        if (_strncmp(env[i], "PATH", 4) == 0)
        {
            path_value = _strdup(env[i]);
            path_tokens = tokenization(path_value, "=");
            free(path_value);
            path_value = _strdup(path_tokens[1]);
            free_array(path_tokens);
            return (path_value);
        }
        i++;
    }
    return (NULL);
}

/**
 * add_path - Concatenates the path with the command
 * @cmd_tokens: The command token
 * @path_tokens: Tokenized PATH
 * Return: Command with full path
 */
char *add_path(char **cmd_tokens, char **path_tokens)
{
    char *full_cmd;
    int i = 0;
    struct stat stat_buf;

    while (path_tokens[i])
    {
        full_cmd = _strcat(path_tokens[i], cmd_tokens[0]);
        if (stat(full_cmd, &stat_buf) == 0)
        {
            cmd_tokens[0] = full_cmd;
            break;
        }
        i++;
    }

    return (cmd_tokens[0]);
}