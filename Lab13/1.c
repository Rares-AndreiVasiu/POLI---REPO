#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** split_into_words(char *str)
{
    char *s = malloc(sizeof(char) * (strlen(str) + 1));

    strcpy(s, str);

    int words = 0;

    char** result = malloc((words + 1) * sizeof(char*));

    if(!result)
    {
        printf("Error while allocating memory\n");

        return NULL;
    }

    result[words] = NULL;

    char *token = strtok(s, " ");

    while(token)
    {
        words++;

        char **aux = realloc(result, (words + 1) * sizeof(char*));

        if(!aux)
        {
            printf("Error while reallocating memory\n");

            free(result);

            return NULL;
        }
        
        result = aux;
        
        result[words - 1] = malloc(strlen(token));

        if(!result[words - 1])
        {
            printf("Error while reallocating memory\n");

            return NULL;
        }
        
        strcpy(result[words - 1], token);

        result[words] = NULL;

        token = strtok(NULL, " ");
    }

    return result;
}

int main()
{
    char** words = split_into_words("anna has apples");

    for(int i = 0; words[i]; ++i)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}
