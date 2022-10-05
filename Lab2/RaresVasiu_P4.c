#include <stdio.h>

int equalNumbers(int a, int b)
{
    return a == b ? 1 : 0;
}

void numberOfDistinctValues(int x, int y, int z)
{
    int equalXY = equalNumbers(x, y);
    int equalXZ = equalNumbers(x, z);
    int equalYZ = equalNumbers(y, z);

    if (equalXY + equalXZ + equalYZ == 3)
    {
        printf("all arguments are equal\n");

        return;
    }
    else
    {
        if (equalXY)
        {
            printf("arguments 1 and 2 are equal\n");
        }
        else
        {
            if(equalXZ)
            {
                printf("arguments 1 and 3 are equal\n");
            }
            else
            {
                if(equalYZ)
                {
                    printf("arguments 2 and 3 are equal\n");
                }
                else
                {
                    printf("all arguments are distinct\n");
                }
            }
        }
    }
}

int main()
{

    numberOfDistinctValues(1, 0, 3);
    
    numberOfDistinctValues(1, 2, 2);
    
    numberOfDistinctValues(1, 0, 1);
    
    numberOfDistinctValues(1, 1, 3);

    numberOfDistinctValues(1, 1, 1);
}