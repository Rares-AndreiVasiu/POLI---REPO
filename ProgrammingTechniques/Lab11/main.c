#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXSIZE 4096

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        perror("Not enough arguments from commandline!");

        exit(EXIT_FAILURE);
    }

    char buffer[MAXSIZE];

    FILE *fp = fopen(argv[1], "r");

    if (!fp)
    {
        perror("Error while opening the file!");

        exit(EXIT_FAILURE);
    }

    fgets(buffer, MAXSIZE - 1, fp);

    const char *ptr = strrchr(buffer, '#');

    // printf("%s\n", ptr);

    int columns = (ptr - buffer) + 1;

    int rows = 0;

    char maze[columns][columns]; //we define the maze

    strncpy(maze[rows++], buffer, columns);

    while(fgets(buffer, columns, fp) != EOF)
    {
        strncpy(maze[rows++], buffer, columns);
    }

    for(int i = 0; i < rows; ++ i)
    {
        printf("%s\n", maze[i]);
    }

    return 0;
}
