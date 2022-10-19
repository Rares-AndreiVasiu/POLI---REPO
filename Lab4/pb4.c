#include <stdio.h>
#include <ctype.h>

void inputError()
{
    printf("Error: input has incorrect position of commas. Try again!\n");
}

int noCommaPrinting()
{
    int c, countDigitsBeforeComma = 0;
    int flagFirstGroup = 0, falgFormat = 1;
    int newNumber = 0;

    while((c = getchar()) != '\n' && falgFormat)
    {
        if(isdigit(c))
        {
            newNumber = newNumber * 10 + (c - '0');

            countDigitsBeforeComma ++;
        }
        else
        {
            if(!flagFirstGroup)
            {
                if(countDigitsBeforeComma > 3)
                {
                    // inputError();
                    falgFormat = 0;
                }
                flagFirstGroup = 1;
            }
            else
            {
                if(countDigitsBeforeComma != 3)
                {
                    // inputError();
                    falgFormat = 0;
                }
            }
            countDigitsBeforeComma = 0;
        }
    }

    if(falgFormat && countDigitsBeforeComma == 3)
    {
        return newNumber;
    }
    else
    {
        return -1;
    }
    // return falgFormat ? newNumber : countDigitsBeforeComma == 3 ? newNumber : -1;
}

int main()
{
    int number =  noCommaPrinting();

    if(number != -1)
    {
        printf("%d", number);
    }
    else
    {
        inputError();
    }

    return 0;
}
