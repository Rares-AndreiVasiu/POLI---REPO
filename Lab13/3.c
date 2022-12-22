#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibonacci_string(unsigned n)
{
    char *s0 = malloc(2 * sizeof(char));

    char *s1 = malloc(3 * sizeof(char));

    if (s0 == NULL || s1 == NULL)
    {
        fprintf(stderr, "Error memory allocation failed\n");
    
        return NULL;
    }

    strcpy(s0, "0");

    strcpy(s1, "01");

    if(n == 0)
    {
        return s0;
    }

    if(n == 1)
    {
        return s1;
    }

    // Allocate memory for the current Fibonacci string
    char *s = malloc((n + 1) * sizeof(char));

    if (s == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");

        return NULL;
    }

    // Iterate through the Fibo strs from Sn-2 to Sn
    for (unsigned i = 2; i <= n; i++)
    {
        // concatenate S(n-1) and S(n-2)
        strcpy(s, s1);

        strcat(s, s0);

        // Free the memory used by Sn-2 and set it to Sn-1
        free(s0);

        s0 = s1;

        // Allocate memory for next Fibonacci string
        s1 = malloc((i + 2) * sizeof(char));

        if (!s1)
        {
            fprintf(stderr, "Error memory allocation fail!!\n");

            free(s);
            
            return NULL;
        }

        // Set Sn-1 to Sn
        strcpy(s1, s);
    }

    // Free the memory of Sn-1
    free(s1);

    return s;
}

int main()
{
    int n; 

    for(int i = 0; i <= n; ++ i)
    {
        printf("%s\n", fibonacci_string(i));
    }

    return 0;
}
