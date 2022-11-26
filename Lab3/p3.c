#include <stdio.h>
#include <ctype.h>

int peek()
{
    int c = getchar();

    ungetc(c, stdin);

    return c;
}

void getRidOfExtraSpaces()
{
    int character;

    while((character = getchar()) != EOF)
    {
        if(!isspace(character))
        {
            ungetc(character, stdin);

            break;
        }
    }
}

void FixedWidthPrinting(int n)
{
    int c, count = 0, current_char;

    while((c = getchar()) != EOF)
    {
        if(isspace(c))
        {
            current_char = ' ';

            if(isspace(peek()))
            {
                getRidOfExtraSpaces();
            }
            
            count ++;
        }
        else
        {
            if(isalnum(c))
            {
                current_char = c;

                count++;
            }
            else
            {
                if(c == '\n')
                {
                    int next;

                    ungetc(c, stdin);

                    while((next = getchar()) != EOF)
                    {
                        if(next != '\n')
                        {
                            ungetc(next, stdin);
                            break;
                        }
                    }
                }
                else
                {
                    current_char = c;
                    
                    count++;
                }
                
            }
        }

        if(count < n)
        {
            putchar(current_char);
        }
        else
        {
            if(count == n)
            {
                count = 0;

                if(isalnum(current_char))
                {
                    if(isalnum(peek()))
                    {
                        putchar('-');

                        ungetc(current_char, stdin);
                    }
                    else
                    {
                        putchar(current_char);
                    }
                }  
                else
                {
                    putchar(current_char);
                }

                putchar('\n');
            }
        }
    }
}

int main()
{
    FixedWidthPrinting(10);
}
