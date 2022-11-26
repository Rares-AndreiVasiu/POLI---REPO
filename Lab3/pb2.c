#include <stdio.h>
#include <ctype.h>

int main()
{
    int c, words = 0, lines = 0, predecesor;

    while((c = getchar()) != EOF)
    {
        if(c == '\n' && isalpha(predecesor))
        {   
            predecesor = '\0';
            lines ++;

            int next = getchar();

            if(next == '\n')
            {
                printf("\nLines: %d, Words: %d\n", lines, words);
                lines = 0;
                words = 0;
                
                ungetc(next, stdin);

                while((next = getchar()) != EOF)
                {
                    if(next != '\n')
                    {
                        ungetc(next, stdin);
                        break;
                    }
                }
            }
        }
        if((isspace(predecesor) || predecesor == '\0') && isalpha(c))
        {
            // printf("%c ", c);
            words++;
        }

        predecesor = c;
    }

    if(words > 0)
    {
        lines++;
        printf("\nLines: %d, Words: %d", lines, words);
    }

    return 0;
}
