#include <stdio.h>
#include <ctype.h>

unsigned hexNum(int character)
{
    if(character == 'A')
    {
        return 10;
    }
    else
    {
        if(character == 'B')
        {
            return 11;
        }
        else
        {
            if(character == 'C')
            {
                return 12;
            }
            else
            {
                if(character == 'D')
                {
                    return 13;
                }
                else
                {
                    if(character == 'E')
                    {
                        return 14;
                    }
                    else
                    {
                        // for case F
                        return 15;
                    }
                }
            }
        }
    }

}

unsigned baseReturn()
{
    int c = getchar();

    unsigned number = 0;

    if(c == '0')
    {
        //we can be either in 8 or 16

        c = getchar();

        if(c == 'x' || c == 'X')
        {
            unsigned powerHex = 16;
            while((c = getchar()) != '\n')
            {
               if(isdigit(c))
               {
                    unsigned digitH = c - '0';

                    number = (number * powerHex) + digitH;
               }
               else
               {
                    unsigned digitH = hexNum(c);

                     number = (number * powerHex) + digitH;

               }
            }
        }
        else
        {
            ungetc(c, stdin);

            unsigned powerOctal = 8;

            while((c = getchar()) != '\n')
            {
                unsigned digitO = c - '0';

                number = (number * powerOctal) + digitO;
            }
        }
    }
    else
    {
        ungetc(c, stdin);

        unsigned powerDec = 10;

        while((c = getchar()) != '\n')
        {
            unsigned digit = c - '0';

            number = (number * powerDec) + digit;
        }
    }
    return number;
}

int main()
{
    unsigned n = baseReturn();

    printf("%d", n);

    return 0;
}
