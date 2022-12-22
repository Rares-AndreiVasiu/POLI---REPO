#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 255

char **read_text()
{
    char **lines = malloc(sizeof(char*));

    if (lines == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        
        return NULL;
    }

    // Allocate memory for the current line
    char *currentLine = malloc(MAX_LINE_LENGTH * sizeof(char));
    
    if (currentLine == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        
        free(lines);
        
        return NULL;
    }

    // Index for the current line in the array of strings
    int line_index = 0;

    // Read input until end of file
    while (fgets(currentLine, MAX_LINE_LENGTH, stdin) != NULL)
    {
        // Get the length of the current line
        int line_length = strlen(currentLine);

        // If the line is full, split it and store the first part
        if (line_length == MAX_LINE_LENGTH - 1 && currentLine[line_length - 1] != '\n')
        {
            // Allocate memory for the length-prefixed string
            char *s = malloc((MAX_LINE_LENGTH + 1) * sizeof(char));
            if (s == NULL)
            {
                fprintf(stderr, "Error: malloc failed\n");
                goto error;
            }

            // Set the length of the string
            s[0] = MAX_LINE_LENGTH - 1;

            // Copy the line to the string
            memcpy(s + 1, currentLine, MAX_LINE_LENGTH - 1);

            // Add the string to the array of strings

            lines[line_index] = s;
            
            line_index++;

            // Reallocate memory for the array of strings

            lines = realloc(lines, (line_index + 1) * sizeof(char*));

            if (lines == NULL)
            {
                fprintf(stderr, "Error: realloc failed\n");
                
                return NULL;
            }

            // Read the rest of the line
            while (fgets(currentLine, MAX_LINE_LENGTH, stdin) != NULL)
            {
                // Get the length of the current line
                line_length = strlen(currentLine);

                // If the line is full, split it and store the first part
                if (line_length == MAX_LINE_LENGTH - 1 && currentLine[line_length - 1] != '\n')
                {
                    // Allocate memory for the length-prefixed string
                    s = malloc((MAX_LINE_LENGTH + 1) * sizeof(char));
                    if (s == NULL)
                    {
                        fprintf(stderr, "Error: malloc failed\n");

                        return NULL;
                    }
            }
        }
    }

    // If the line is not full, store it
    else
    {
        // Allocate memory for the length-prefixed string
        char *s = malloc((line_length + 1) * sizeof(char));
        if (s == NULL)
        {
            fprintf(stderr, "Error: malloc failed\n");
            goto error;
        }

        // Set the length of the string
        s[0] = line_length;

        // Copy the line to the string
        memcpy(s + 1, currentLine, line_length);

        // Add the string to the array of strings
        lines[line_index] = s;

        line_index++;

        // Reallocate memory for the array of strings
        lines = realloc(lines, (line_index + 1) * sizeof(char*));
        
        if (!lines)
        {
            fprintf(stderr, "Error: realloc failed\n");

            return NULL;
        }
    }
}

// Add a null terminator to the array of strings
lines[line_index] = NULL;

// Free the memory for the current line
free(line);

// Return the array of strings
return lines;
}

