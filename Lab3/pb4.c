#include <stdio.h>

// 4. Pretty-printing

void printSpaces(int n)
{
    unsigned int spaces = 2*n;

    for (;spaces != 0; spaces--)
    {
        putchar(' ');
    }
}

void prettyPrinting()
{
    unsigned int c;
    unsigned int level = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '{')
        {
            level++;
            printf("%c\n", c);
            printSpaces(level);
        }
        else if (c == '}')
        {
            level--;

            putchar('\n');

            printSpaces(level);

            printf("%c\n", c);
            
        }
        else if (c == '\n')
        {
            putchar(c);
            printSpaces(level);
        }
        else
        {
            putchar(c);
        }
    }
}

int main()
{
    prettyPrinting();

    return 0;
}
