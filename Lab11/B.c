#include <stdio.h>

int checkNibble(__uint64_t nib)
{
    if((nib & 0xF) == 0)
    {
        return 1;
    }

    return 0;
}

int countAlignedAddresses(int * addr[])
{
    int counter = 0;

    for(int i = 0; addr[i]; ++ i)
    {
       __uint64_t address = (__uint64_t*)(addr + i);

        if(checkNibble(addres))
        {
            printf("%llX\n", address);
            
            counter++;
        }
    }

    u_

    return counter;
}

int main()
{
    int *a[101];

    int v[] = {1, -10, 11, 14, 15, 101};

    int n = sizeof(v) / sizeof(v[0]);

    for(int i = 0; )
    for(int i = 0; i < n; ++ i)
    {
        a[i] = &v[i];
    }

    int n = countAlignedAddresses(a);

    return 0;
}
