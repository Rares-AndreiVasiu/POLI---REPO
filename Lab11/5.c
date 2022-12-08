#include <stdio.h>

int main(int arg, char *argv[])
{
    for (int i = 1; i < arg; i++)
    {
        for(int j = i + 1; j < arg; ++ j)
        {
            while (argv[i][0] != '-' && argv[j][0] == '-')
            {
                //we rearrange the strings args

                char *temp = argv[i];

                argv[i] = argv[j];

                argv[j] = temp;
            }
        }

        printf("your arg at position %d is %s\n", i, argv[i]);
    }
    
    return 0;
    
    //commnad line arguments
    /*
    we need a new prototype for main
    one arguments is: arg -> nums of elements
    second one is the actual array: char *argv[]
    its an array to pointers to characters
    where each pointer is a pointer to different string

    how to run: ./a.out ana are mere
    */
}
