#include <stdio.h>
#include <ctype.h>

int main()
{
    int c, pre = '\0';

    int countWords = 0;
    int countLines = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '\n' && isalnum(pre))
        {
            int next = getchar();

            ungetc(next, stdin);

            countLines++;

            if(next == '\n' || next == EOF)
            {
                printf("Words: %d, Lines: %d\n", countWords, countLines);

                countLines = 0;
                countWords = 0;
            }
        }

        if(!isspace(c) && (isspace(pre) || pre == '\0'))
        {
            countWords++;
        }

        pre = c;
        // if(c != '\n')
        //     printf("%d", c);
        // else
        // {
        //     printf("\nNew line %d", c);
        // }
    }

    if(countWords > 0)
    {
        countLines++;
        
        printf("Words: %d, Lines: %d\n", countWords, countLines);
    }
    return 0;
}
