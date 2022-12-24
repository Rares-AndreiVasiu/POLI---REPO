#include <stdio.h>
#include <stdlib.h>

void fatal(const char *msg)
{
    fputs(msg, stderr);

    exit(EXIT_FAILURE);
}

void fillArrayNegatives(int* v, int capacity)
{
    int position = 0, x;

    while(scanf("%d", &x) == 1)
    {   
        if(x == 0)
        {
            return;
        }
        else
        {
            if(x < 0 && position < capacity)
            {
                v[position++] = x;
            }
        }
    }
}


int main()
{
    int capacity = 5;
    
    int *p = malloc((capacity + 1) * sizeof(int));

    if(!p)
    {
        fatal("Error while allocating memory");
        return 0;
    }

    p[capacity] = 0;

    fillArrayNegatives(p, capacity);

    for(int i = 0; i < capacity; ++ i)
    {
        printf("%d ", p[i]);
    }

    return 0;
}
