// use input file as an already file fform lab
#include <stdio.h>
#include <ctype.h>

void indent2N(int level)
{
    int space = ' ';

    for(int i = 1; i <= 2 * level; ++i)
        putchar(space);
}

int main()
{
    int braceLevel, character, newLine = '\n', previous;

    while((character = getchar()) != EOF)
    {
        if(character == '{')
        {
            putchar(character);
            
            braceLevel++;
            
            // new line first rule
            putchar(newLine);

            character = getchar();

            // skip usless new lines
            while(character != EOF && character == '\n')
            {   
                character = getchar();
            }
            
            if(character != EOF)
            {
                ungetc(character, stdin);
            }
            else
            {
                //we don't need to continue
                break;
            }
        }
        else
        {
            if(character == '}')
            {
                braceLevel --;

                putchar(character);
                
                putchar(newLine);
            }
            else
            {
                while(character != EOF)
                {
                    if(character == '{')
                    {
                        ungetc(character, stdin);

                        break;
                    }
                    else
                    {
                        if((previous == '}' && isalpha(character)) || previous == '\n')
                        {
                            indent2N(braceLevel);
                        }

                        putchar(character);
                    }
                    character = getchar();
                }
            }
        }
        previous = character;
    }
    return 0;
}
