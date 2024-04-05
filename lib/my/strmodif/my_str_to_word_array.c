/*
** EPITECH PROJECT, 2021
** MY_STR_TO_WORD_ARRAY
** File description:
** Stores words from a str into an array
*/

#include <stdlib.h>
#include "../include/lib/strmodif.h"

static int char_isalpha(char c)
{
    if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
    || (c >= 48 && c <= 57)))
        return (0);
    return (1);
}

static void count_words(char const *str, int *words)
{
    int alphanumeric = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((char_isalpha(str[i]) || str[i] == '.') && alphanumeric == 0) {
            alphanumeric += 1;
            *words += 1;
        }
        if (!char_isalpha(str[i]) || str[i] != '.')
            alphanumeric = 0;
    }
}

static int count_char(char const *str, int *characters, int i)
{
    int first_letter = 0;
    int alphanumeric = 0;

    for (; str[i] != '\0'; i++) {
        if ((char_isalpha(str[i]) || str[i] == '.') && alphanumeric == 0) {
            alphanumeric += 1;
            first_letter = i;
        }
        if (!char_isalpha(str[i]) && char_isalpha(str[i - 1])) {
            *characters = i - first_letter;
            return (i);
        }
    }
    *characters = i - first_letter;
    return (i);
}

char **my_str_to_word_array(char const *str)
{
    char **word_array;
    int words = 0;
    int characters = 0;
    int index = 0;

    count_words(str, &words);
    word_array = malloc(sizeof(char *) * words + 1);
    for (int i = 0; i < words; i++, index++) {
        index = count_char(str, &characters, index);
        word_array[i] = malloc(sizeof(char) * (characters + 1));
        word_array[i][characters] = '\0';
        my_strncpy(word_array[i], str + index - characters, characters);
    }
    word_array[words] = 0;
    return (word_array);
}
