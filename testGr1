#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_WORD 5

int extractSubstrinigs(char *substrings[], int capacity, char *s)
{
    char str[strlen(s) + 1];

    strcpy(str, s);

    substrings = malloc(sizeof(char*));

    int index = 0;

    char vowels[] = "AEIOU";

    char *token = strtok(str, " ");

    while(token && index < capacity)
    {
        if(strlen(token) == LEN_WORD && strchr(vowels, token[0]))
        {
            char *word = strdup(token);

            if(!word)
            {
                fputs("Error while allocating memory", stderr);

                return 0;
            }
            substrings[index] = &word[0];

            // printf("%p\n", &word[0]);

            printf("%p\n",substrings[index]);

            index++;

            char **aux = realloc(substrings, (index + 1) * sizeof(char*));

            if(!aux)
            {
                free(substrings);

                fputs("Error while reallocating memory", stderr);

                return 0;
            }

            substrings = aux;
        }

        token = strtok(NULL, " ");
    }

    substrings[index] = NULL;

    return index;
}

int main()
{
    char **substring = malloc(sizeof(char*)), *s = "ANNNA has very very nice Autos and cooks Egggs";

    int k = extractSubstrinigs(substring, 10, s);

    printf("%d\n", k);

    return 0;
}
