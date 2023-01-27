#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define DBG 0

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Invalid usage of commandline arguments!\n");
        
        exit(1);     
    }
    char *aux = strdup(argv[1]);

    if(!aux)
    {
        perror("Error while allocating memory!");

        return errno;
    }

    char *token_str1 = strtok(aux, "-D=");
    char *str1, *str2;

    #if DBG==1
    fputs(token_str1, stdout);
    #endif
    
    if(token_str1)
    {
        str1 = token_str1;

        char *token_str2 = strtok(NULL, "-D=");

        if(token_str2)
        {
            str2 = token_str2;
        }
        else
        {
            fprintf(stderr, "Error for string formating in commandline args!\n");
        }

    #if DBG==1
        fputs(token_str2, stdout);
    #endif
    }
    else
    {
        fprintf(stderr, "Error for string formating in commandline args!\n");
    }

    FILE *file_input = fopen(argv[2], "r");

    if(!file_input)
    {
        perror("Error opening the file!\n");

        return errno;
    }

    char *output = strcat(argv[2], ".pp");

    FILE *file_output = fopen(output, "w");

    if(!file_output)
    {
        perror("Error opening the file!\n");

        return errno;  
    }

    char line[256];

    while(fgets(line, 256, file_input))
    {
        char *p = line;

        while((p = strstr(p, str1)) != NULL)
        {
            strncpy(p, str2, strlen(str2));

            memset(p + strlen(str2), ' ', strlen(str1) - strlen(str2));

            p += strlen(str2);
        } 

        fputs(line, file_output);
    }

    if(fclose(file_input))
    {
        perror("error on close");
        
        return errno;
    }

    if(fclose(file_output))
    {
        perror("error on close"); 
        
        return errno;
    }

    return 0;
}