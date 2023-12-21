#include "main.h"

/**
 * _strlen - Return the length of a string
 * @str: String to be evaluated
 * Return: The length of the string
 */
int _strlen(char *str)
{
    int len;

    for (len = 0; str[len] != '\0'; len++)
        ;

    return (len);
}

/**
 * _strcpy - Copies the string pointed to by src
 * @dest: Destination buffer
 * @src: Source string
 * Return: Pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
    int index;

    index = 0;

    while (src[index] != '\0')
    {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';

    return (dest);
}

/**
 * _strcmp - Compare two strings
 * @str1: First string for comparison
 * @str2: Second string for comparison
 * Return: 0 if equal, otherwise difference
 */
int _strcmp(char *str1, char *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return (0);
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

/**
 * _strncmp - Compares two strings up to n characters
 * @str1: First string
 * @str2: Second string
 * @n: Number of characters to compare
 * Return: 0 if equal, otherwise difference
 */
int _strncmp(char *str1, char *str2, size_t n)
{
    while (n && *str1 && (*str1 == *str2))
    {
        ++str1;
        ++str2;
        --n;
    }

    if (n == 0)
        return (0);
    else
        return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
    int dest_len, i;

    dest_len = _strlen(dest);
    dest[dest_len] = '/';

    for (i = 0; src[i] != '\0'; i++)
        dest[dest_len + 1 + i] = src[i];

    dest[dest_len + 1 + i] = '\0';
    return (dest);
}