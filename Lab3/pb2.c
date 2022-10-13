#include <stdio.h>
#include <ctype.h>

int main()
{
    int c, pre = '\0';

    int countWords = 0;
    int countLines  = 0;

    while((c = getchar()) != EOF)
    {
        // line counting does not work
        if(c == '\n' && isalnum(pre))
            countLines ++;

        if(c == EOF && isalnum(pre))
            countLines++;

        if(!isspace(c) && (isspace(pre) ||  pre == '\0'))
        {
            countWords ++;
        }

        pre = c;
    }

    printf("%d %d", countWords, countLines);

    return 0;
}
