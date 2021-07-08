/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** str_wordarray
*/

#include <stdlib.h>
#include <stddef.h>
#include "../../include/my.h"

char **malloc_word_array(char *str, char L)
{
    char **word_array;
    int len = 0;
    int word_len = 0;
    int word = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == L)
            len++;
    if (str[my_strlen(str) - 1] != L)
        len++;
    if ((word_array = malloc(sizeof(char *) * (len + 1))) == NULL)
        return (NULL);
    for (int j = 0; str[j] != '\0'; j++, word++, word_len = 0) {
        for (; str[j] != L && str[j] != '\0'; j++, word_len++);
        if ((word_array[word] = malloc(sizeof(char) * (word_len + 1))) == NULL)
            return (NULL);
        if (str[j] == '\0')
            break;
    }
    word_array[word + 1] = NULL;
    return (word_array);
}

char **my_str_to_word_array(char *str, char L)
{
    char **word_array;
    int word_len = 0;
    int word = 0;
    int j = 0;
    int k = 0;

    if (str == NULL)
        return (NULL);
    if ((word_array = malloc_word_array(str, L)) == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++, j++){
        for (k = 0; str[i] != L && str[i] != '\0'; i++, k++)
            word_array[j][k] = str[i];
        word_array[j][k] = '\0';
        if (str[i] == '\0')
            return (word_array);
    }
    return (word_array);
}