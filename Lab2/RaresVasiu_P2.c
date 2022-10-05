#include <stdio.h>

void addTime(unsigned h, unsigned m, unsigned dMin)
{
    unsigned seconds = (m + dMin) * 60 + 3600 * h;

    h = (seconds / 3600) % 24;

    m = (seconds / 60) % 60;

    printf("New time is %d hour and %d minutes\n", h, m); 
}

int main()
{
    addTime(22, 0, 120);

    addTime(10, 0, 61);

    addTime(9, 58, 60);

    addTime(9, 58, 72);
}