#include "main.h"

/**
 * main - Entry point of the shell
 * @ac: Unused argument count
 * @av: Unused argument vector
 * @env: Environment variables
 * Return: Always 0
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
    char *line = NULL, **tokens = NULL;
    size_t n = 0;
    int i;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "AraOS$ ", 8);
        if (getline(&line, &n, stdin) == EOF)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        tokens = tokenization(line, " \n");
        free(line);
        if (tokens[0] != NULL)
        {
            if (_strcmp(tokens[0], "env") == 0)
            {
                for (i = 0; env[i]; i++)
                {
                    write(STDOUT_FILENO, env[i], _strlen(env[i]));
                    write(STDOUT_FILENO, "\n", 1);
                }
                free_array(tokens);
                continue;
            }
            if (input_control(tokens) == 1)
                execution(tokens, env);
        }
        else
            free(tokens);
    }
    free_array(tokens);
    free(line);

    return (0);
}
