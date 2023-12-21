#include "main.h"

/**
 * _strdup - Duplicates a string
 * @str: String to duplicate
 * Return: Pointer to the duplicated string
 */
char *_strdup(char *str)
{
    char *dup;
    int i, len;

    if (str == NULL)
        return (NULL);

    len = _strlen(str);
    dup = malloc(sizeof(char) * (len + 1));

    if (dup == NULL)
        return (NULL);

    for (i = 0; i < len; i++)
        dup[i] = str[i];
    dup[i] = '\0';

    return (dup);
}

/**
 * free_array - Frees a 2D array
 * @array: Array to be freed
 */
void free_array(char **array)
{
    int i = 0;

    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}
