#include <stdio.h>
#include <ctype.h>

int main()
{
    int character;

    char space = ' ';

    while((character = getchar()) != '\n')
    {
        // putchar(character);

        if(character == ' ' && character != '\n')
        {
            while((character = getchar()) != '\n')
            {
                if(character != ' ')
                    break;
            }

            if(character != '\n')
            {
                putchar(space);
                putchar(character);
            }
            else
            {
                putchar(character);
            }
        }
        else
        {
            putchar(character);
        }
    }
    
    return 0;
}
