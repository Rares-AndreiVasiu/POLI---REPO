#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000
#define MAXROWS 1000

typedef struct _point
{
    int x;
    int y;

} point;

char M[MAXLINES][MAXROWS];

int main(int argc, char *argv[])
{
    FILE *f;

    if (argc <= 1)
    {
        printf("there aren't enough arguments to run the programm!");

        exit(EXIT_FAILURE);
    }

    f = fopen(argv[1], "r");

    if (!f)
    {
        printf("Error while opening the input file!");

        exit(EXIT_FAILURE);
    }

    point start, end;

    int cols = 0, rows = 0;

    char firstLine[MAXLINES], buffer[MAXLINES];

    fgets(firstLine, MAXLINES - 1, f);

    cols = strrchr(firstLine, '#') - firstLine + 1;

    printf("Cols: %d\n", cols);

    strncpy(M[rows++], firstLine, cols);

    // printf("%s\n\n", M[1]);

    while (!feof(f))
    {
        if (fgets(buffer, cols, f) != NULL)
        {
            strncpy(M[rows++], buffer, cols);

            if(strchr(M[rows - 1], 'E'))
            {
                puts("We have found the end pos!");

                printf("At line: %d\n", rows - 1);
            }
        }
        else
        {
            printf("Error while reading the file!");

            exit(EXIT_FAILURE);
        }
    }

    printf("Rows: %d\n", rows);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%c", M[i][j]);

            if(M[i][j] == 'S')
            {
                start.x = i;
                start.y = j;
            }

            if (M[i][j] == 'E')
            {
                end.x = i;

                end.y = j;

                printf("\n%d %d\n", end.x, end.y);
                return 0;
            }
        }
    }

    printf("%s\n", M[start.x]);

    printf("\nStart: %d %d, End: %d %d\n", start.x, start.y, end.x, end.y);

    return 0;
}