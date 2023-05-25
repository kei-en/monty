#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int num);
int get_len(unsigned int num, unsigned int base);
void fill_array(unsigned int num, unsigned int base, char *str, int len);

/**
 * get_int - gets a character pointer to new string containing integer
 * @num: integer to convert
 *
 * Return: character pointer to new string
 */
char *get_int(int num)
{
    unsigned int temp;
    int len = 0;
    long num_2 = 0;
    char *str;

    temp = abs(num);
    len = get_len(temp, 10);

    if (num < 0 || num_2 < 0)
        len++;

    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);

    fill_array(temp, 10, str, len);
    if (num < 0 || num_2 < 0)
        str[0] = '-';

    return (str);
}

/**
 * _abs - gets absolute value of integer
 * @num: integer to get absolute value of
 *
 * Return: absolute value of integer
 */
unsigned int _abs(int num)
{
    if (num < 0)
        return (-(unsigned int)num);
    return ((unsigned int)num);
}

/**
 * get_len - gets length of string
 * @num: number to get length of
 * @base: base to convert to
 *
 * Return: length of string
 */
int get_len(unsigned int num, unsigned int base)
{
    int len = 1;

    while (num > base - 1)
    {
        len++;
        num /= base;
    }

    return (len);
}

/**
 * fill_array - fills array with characters
 * @num: number to convert
 * @base: base to convert to
 * @str: string to fill
 * @len: length of string
 *
 * Return: void
 */
void fill_array(unsigned int num, unsigned int base, char *str, int len)
{
    int rem, i = len - 1;

    str[len] = '\0';
    while (i >= 0)
    {
        rem = num % base;
        if (rem > 9)
            str[i] = rem + 87;
        else
            str[i] = rem + '0';
        num /= base;
        i--;
    }
}