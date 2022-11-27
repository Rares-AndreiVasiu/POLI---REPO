#include <stdio.h>

long long ThousandSeparator()
{
    int c, currentGroupDigits = 0, firstGroup = 1, validFormat = 1, threeGroup = 0;
    long long newNumber = 0;

    while((c = getchar()) != '\n')
    {
        if(c != ',')
        {
            int digit = c - '0';

            threeGroup = threeGroup * 10 + digit;

            currentGroupDigits++;
        }
        else
        {
            // printf("%d\n", currentGroupDigits);

            if(firstGroup)
            {
                if(currentGroupDigits == 1 && threeGroup != 0)
                {
                    newNumber = newNumber * 10 + threeGroup;
                }
                else
                {
                    if(currentGroupDigits == 2 && threeGroup != 0)
                    {
                        newNumber = newNumber * 100 + threeGroup;
                    }
                    else
                    {
                        if (currentGroupDigits == 3 && threeGroup != 0)
                        {
                            newNumber = newNumber * 1000 + threeGroup;
                        }
                        else
                        {
                            validFormat = 0;

                            printf("\nInvalid Formatting Try Again!\n");
                            
                            break;
                        }
                    }
                }

                firstGroup = 0;
            }
            else
            {
                if(currentGroupDigits == 3)
                {
                    newNumber = newNumber * 1000 + threeGroup;
                }
                else
                {
                    
                    if(validFormat)
                    {
                        printf("\nInvalid Formatting Try Again!\n");
                    }
                    
                    validFormat = 0;  
                    break;
                }
            }
            threeGroup = 0;
            currentGroupDigits = 0;
        }
    }
    
    // printf("%d\n", currentGroupDigits);

    if(currentGroupDigits == 3)
    {
        newNumber = newNumber * 1000 + threeGroup;
    }
    else
    {
        if(validFormat)
        {
            printf("\nInvalid Formatting Try Again!\n");   
        }
        validFormat = 0;                    
    }                                  

    if(validFormat)
    {
        return newNumber;
    }

   return -1;
}

int main()
{
    long long n = ThousandSeparator();

    printf("%lld\n", n);
}
