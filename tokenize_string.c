#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char c, char *delims);
int get_word_len(char *str, char *delims);
int count_words(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - splits a string into words
 * @str: string to split
 * @delims: delimiters to split str by
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str, char *delims)
{
    char **words;
    int i = 0, word_len = 0, words_len = 0;

    if (str == NULL || *str == '\0')
        return (NULL);

    words_len = count_words(str, delims);
    if (words_len == 0)
        return (NULL);

    words = malloc(sizeof(char *) * (words_len + 1));
    if (words == NULL)
        return (NULL);

    while (*str)
    {
        if (is_delim(*str, delims))
            str++;
        else
        {
            word_len = get_word_len(str, delims);
            words[i] = get_next_word(str, delims);
            str += word_len;
            i++;
        }
    }
    words[i] = NULL;

    return (words);
}

/**
 * is_delim - checks if character is a delimiter
 * @c: character to check
 * @delims: string of delimiters
 *
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delims)
{
    while (*delims)
    {
        if (c == *delims)
            return (1);
        delims++;
    }
    return (0);
}

/**
 * get_word_len - gets the length of a word
 * @str: string to check
 * @delims: delimiters to check against
 *
 * Return: length of word
 */
int get_word_len(char *str, char *delims)
{
    int len = 0;

    while (*str && !is_delim(*str, delims))
    {
        len++;
        str++;
    }
    return (len);
}

/**
 * count_words - counts the number of words in a string
 * @str: string to check
 * @delims: delimiters to check against
 *
 * Return: number of words
 */
int count_words(char *str, char *delims)
{
    int words = 0, in_word = 0;

    while (*str)
    {
        if (is_delim(*str, delims) && in_word)
            in_word = 0;
        else if (!is_delim(*str, delims) && !in_word)
        {
            in_word = 1;
            words++;
        }
        str++;
    }
    return (words);
}

/**
 * get_next_word - gets the next word in a string
 * @str: string to check
 * @delims: delimiters to check against
 *
 * Return: pointer to the next word
 */
char *get_next_word(char *str, char *delims)
{
    char *word;
    int i = 0, word_len = 0;

    word_len = get_word_len(str, delims);
    word = malloc(sizeof(char) * (word_len + 1));
    if (word == NULL)
        return (NULL);

    while (*str && !is_delim(*str, delims))
    {
        word[i] = *str;
        str++;
        i++;
    }
    word[i] = '\0';

    return (word);
}