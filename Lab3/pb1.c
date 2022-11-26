#include <stdio.h>
#include <string.h>

int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            while((c = getchar()) == ' ');

            if(c == '\n')
            {
                putchar(c);
            }
            else
            {
                putchar(' ');
                ungetc(c, stdin);  
            }
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}
