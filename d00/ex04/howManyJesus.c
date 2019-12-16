
#include "header.h"

size_t hash(char *str, int len)
{
    int i = 0;
    size_t hash = 0;
    while (i < len && str[i])
    {
        hash += (hash << 5) + str[i];
        hash -= (hash >> 2) - str[i];
        i++;
    }
    return (hash);
}

int howManyJesus(char *bible, char *target_word)
{
    int sum = 0;    
    int len = strlen(target_word);
    size_t hsh = hash(target_word, len);    
    while (*bible)
    {
        if (hash(bible, len) == hsh)
            sum++;
        bible++;
        while (*bible != *target_word && *bible)
            bible++;
    }
    return (sum);
}
