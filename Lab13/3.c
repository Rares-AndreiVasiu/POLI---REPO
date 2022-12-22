#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibonacci_string(unsigned n)
{
    // Allocate memory for the first two Fibonacci strings
    char *s0 = malloc(sizeof(char));

    char *s1 = malloc(2 * sizeof(char));

    if (s0 == NULL || s1 == NULL)
    {
        fprintf(stderr, "Error memory allocation failed\n");
    
        return NULL;
    }

    // Initialize the 2 Fibonacci strings
    s0[0] = '0';

    s1[0] = '0';
    s1[1] = '1';


    if (n == 0)
    {
        return s0;
    }

    if (n == 1)
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

    // Iterate through the Fibonacci strings from Sn-2 to Sn
    for (unsigned i = 2; i <= n; i++)
    {
        // Concatenate Sn-1 and Sn-2 to get Sn
        strcpy(s, s1);

        strcat(s, s0);

        // Free the memory used by Sn-2 and set it to Sn-1
        free(s0);

        s0 = s1;

        // Allocate memory for the next Fibonacci string
        s1 = malloc((i + 2) * sizeof(char));

        if (s1 == NULL)
        {
            fprintf(stderr, "Error memory allocation failed\n");

            free(s);
            
            return NULL;
        }

        // Set Sn-1 to Sn
        strcpy(s1, s);
    }

    // Free the memory used by Sn-1
    free(s1);

    // Return the nth Fibonacci string
    return s;
}

int main()
{
    printf("%s\n", fibonacci_string(1));
    printf("%s\n", fibonacci_string(3));
    printf("%s\n", fibonacci_string(2));
}
