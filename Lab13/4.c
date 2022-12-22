#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// Function to print a formatted string using an array of addresses of objects
int myprintf(const char *fmt, void *adrtab[])
{
    // Index for the current address in the array
    int adrtab_index = 0;

    // Loop through the format string
    for (const char *p = fmt; *p != '\0'; p++)
    {
        // If the character is not '%', print it
        if (*p != '%')
        {
            putchar(*p);
        }
        // If the character is '%', process the format specifier
        else
        {
            // Get the next character in the format string
            p++;

            // If the character is 'd', print an integer
            if (*p == 'd')
            {
                // Get the address of the integer
                int *i = adrtab[adrtab_index];
                if (i == NULL)
                {
                    fprintf(stderr, "Error: invalid address\n");
                    return -1;
                }

                // Print the integer
                printf("%d", *i);

                // Increment the index for the current address in the array
                adrtab_index++;
            }
            // If the character is 'f', print a float
            else if (*p == 'f')
            {
                // Get the address of the float
                float *f = adrtab[adrtab_index];
                if (f == NULL)
                {
                    fprintf(stderr, "Error: invalid address\n");
                    return -1;
                }

                // Print the float
                printf("%f", *f);

                // Increment the index for the current address in the array
                adrtab_index++;
            }
            // If the character is 's', print a string
            else if (*p == 's')
            {
                // Get the address of the string
                char *s = adrtab[adrtab_index];
                if (s == NULL)
                {
                    fprintf(stderr, "Error: invalid address\n");
                    return -1;
                }

                // Print the string
                printf("%s", s);

                // Increment the index for the current address in the array
                adrtab_index++;
            }
            // If the character is '%', print a '%'
            else if (*p == '%')
            {
                putchar('%');
            }
            // If the character is not a valid format specifier, terminate printing
           else
            {
                fprintf(stderr, "Error: invalid format specifier\n");
                return -1;
            }
        }
    }

    // Return the number of characters printed
    return 0;
}
