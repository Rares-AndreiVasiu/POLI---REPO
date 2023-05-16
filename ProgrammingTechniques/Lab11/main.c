#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAXSIZE 4096
#define DBG 0

int a[MAXSIZE][MAXSIZE];

const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};

bool foundTrack = false;

bool inside(int i, int j, int rows, int cols)
{
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

void move(int i, int j, int step, int rows, int cols, int iend, int jend)
{
    for(int d = 0; d < 4 && !foundTrack; ++ d)
    {
        printf("Before=> i: %d,  j: %d, inside: %d, a[i][j]: %d\n", i, j,
        inside(i, j, rows, cols), a[i][j]);

        int newI = i + di[d];

        int newJ = j + dj[d];

        printf("i: %d,  j: %d, inside: %d, a[i][j]: %d\n", newI, newJ,
        inside(newI, newJ, rows, cols), a[newI][newJ]);

        if(inside(newI, newJ, rows, cols) && a[newI][newI] == 0)
        {
            printf("Valid coord: %d %d\n", newI, newJ);
            a[newI][newJ] = step;

            if(newI == iend && newJ == jend)
            {
                foundTrack = true;
            }
            else
            {
                move(newI, newJ, step + 1, rows, cols, iend, jend);
            }

            a[newI][newJ] = 0;
        }
    }
}

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

#if DBG == 1
    printf("Print first line: %s\n", buffer);
#endif

    const char *ptr = strrchr(buffer, '#');

    /*
        this is stricly the number of the #, ' ', 'E', 'S' max per line
        without including the '\0' at the end
    */
    int rows = 1; // because we already read a line
    int columns = 0;
    int index = 0;
    int istart, jstart;
    int iend, jend;

    columns = (ptr - buffer) + 1;

    while (!feof(fp))
    {
        if (fgets(buffer, columns + 1, fp) != NULL)
        {
            if (strchr(buffer, '#'))
            {
                rows++;

#if DBG == 1
                printf("Print lines: %s\n", buffer);
#endif
            }
        }
    }

    // we have the # of rows & cols
    char maze[rows][columns + 1];

#if DBG == 1
    printf("Rows: %d and Columns: %d\n", rows, columns);
#endif

    fseek(fp, 0, SEEK_SET); // we go back to the beginning to the file

    while (!feof(fp))
    {
        if (fgets(buffer, columns + 1, fp) != NULL)
        {
            if (strchr(buffer, '#'))
            {
                strncpy(maze[index], buffer, columns + 1);

                maze[index][columns + 1] = '\0';

#if DBG == 1
                printf("Print correct line:%s\n", maze[index]);
#endif

                index++;
            }
        }
    }

    for(int i = 0; i < rows; ++ i)
    {
        for(int j = 0; j < columns; ++ j)
        {
            switch (maze[i][j])
            {
                case ' ':
                {
                    a[i][j] = 0;
                    break;
                }

                case '#':
                {
                    a[i][j] = -1;
                    break;
                }

                case 'S':
                {
                    a[i][j] = 0;

                    istart = i;

                    jstart = j;

                    break;  
                }

                case 'E':
                {
                    a[i][j] = 0;

                    iend = i;

                    jend = j;

                    break;
                }
            }
        }
    }   

    // printf("a[istart][jstart]: %d\n", a[istart][jstart]);
    

    a[istart][jstart] = 1;

    // printf("a[istart][jstart]: %d\n", a[istart][jstart]);

    for(int i = 0; i < rows; ++ i, printf("\n"))
    {
        for(int j = 0; j < columns; ++ j)
        {
            if(a[i][j] == -1)
            {
                putchar('#');
            }
            else
            {
                printf("%d", a[i][j]);
            }
        }
    }

    printf("I start: %d, J start: %d\n", istart, jstart);

    printf("I end: %d, J end: %d\n", iend, jend);

    printf("a[1][2]: %d, a[1][0]: %d, a[2][1]: %d, a[0][1]: %d\n", a[1][2], a[1][0], a[2][1], a[0][1]);
    // printf("%d\n", inside(-1, 0, rows, columns));
    // printf("%d\n", inside(0, 0, rows, columns));
    // printf("%d\n", inside(rows + 1, 0, rows, columns));

    move(istart, jstart, 2, rows, columns, iend, jend);

    #if DBG == 1
    printf("Start position is at: %d %d\n", start.x, start.y);
    #endif

    if(foundTrack)
    {
        for(int i = 0; i < rows; ++ i, printf("\n"))
        {
            for(int j = 0; j < columns; ++ j)
            {
                if(a[i][j] == -1)
                {
                    printf("#");
                }
                else
                {
                    printf("%d", a[i][j]);
                }
            }
        }
    }

    printf("%d\n", foundTrack);

    return 0;
}
