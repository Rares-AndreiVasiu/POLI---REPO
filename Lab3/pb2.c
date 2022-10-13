#include <stdio.h>
#include <ctype.h>

int main()
{
    int c, pre = '\0';

    int next;

    int countWords = 0;
    int countParagraphs  = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            next = getchar();

            if(next == '\n')
            {
                countParagraphs ++;
                printf("%d %d\n", countWords, countParagraphs);
            }
            else ungetc(next, stdin);
        }

        if(!isspace(c) && (isspace(pre) ||  pre == '\0'))
        {
            countWords ++;
        }

        pre = c;
    }

    return 0;
}
