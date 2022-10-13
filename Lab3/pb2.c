#include <stdio.h>
#include <ctype.h>

int main()
{
    int c, pre = '\0';

    int next;

    int countWords = 0;
    int countParagraphs  = 0;

    FILE *f;

    f = fopen("2.in", "r");

    while((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            next = getchar();

            if(next == '\n')
                countParagraphs ++;
            
            ungetc(next, f);
        }

        if(!isspace(c) && (isspace(pre) ||  pre == '\0'))
        {
            countWords ++;
        }

        pre = c;
    }

    printf("%d %d", countWords, countParagraphs);

    return 0;
}
