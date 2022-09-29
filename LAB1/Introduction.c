//stdio = standard input output
#include <stdio.h>

//doesnt allow method overflow
//only main allows it
//main is directed controlled by the compiler
int main(int arguments, char* arg[])
{

    printf("Your programm name is: %s\n", arg[0]);

    if(arguments >= 1)
    {
        for(int ct = 0; ct < arguments; ++ct)
        {
            printf("Your profile is: %s\n", arg[ct]);
        }
    }
    
    printf("Hehfiktfthllo World\n");
    
    int age = 19;

    printf("%d\n",age);

    return 0;
}
