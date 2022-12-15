#include <stdio.h>
#include <string.h>

int main()
{
    int hour, minutes, seconds;

    if(scanf("%2d:%2d:%2d", &hour, &minutes, &seconds) == 3)
    {
        printf("The finishing time is: %d %d %d\n", hour, minutes, seconds);
    }

    return 0;
}
