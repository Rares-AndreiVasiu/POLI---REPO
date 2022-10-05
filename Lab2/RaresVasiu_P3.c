#include <stdio.h>

int medianOfThreeNumbers(int x, int y, int z)
{
    // there will be 3! - 1 cases.

    // case 1: xyz
    if (x <= y && y <= z)
        return y;

    // case 2: xzy
    if (x <= z && z <= y)
        return z;

    // case 3: yxz
    if (y <= x && x <= z)
        return x;

    // case 4: yzx
    if (y <= z && z <= x)
        return z;

    // case 5: zxy
    if (z <= x && x <= y)
        return x;

    // case 6: zyx
    return y;
}

int main()
{
    int a, b, c;

    a = 10; b = 12; c = 14;
    printf("The median value of %d, %d and %d is equal with: %d\n", a, b, c, medianOfThreeNumbers(a, b, c));

    a = 4; c = 76; b = 11;
    printf("The median value of %d, %d and %d is equal with: %d\n", a, b, c, medianOfThreeNumbers(a, b, c));

    a = 45; b = 6; c = 78;
    printf("The median value of %d, %d and %d is equal with: %d\n", a, b, c, medianOfThreeNumbers(a, b, c));
    
    a = 21; b = 10; c = 20;
    printf("The median value of %d, %d and %d is equal with: %d\n", a, b, c, medianOfThreeNumbers(a, b, c));

    a = 32; b = 2003; c = 20;
    printf("The median value of %d, %d and %d is equal with: %d\n", a, b, c, medianOfThreeNumbers(a, b, c));
    
    a = 99; b = 58; c = 30;
    printf("The median value of %d, %d and %d is equal with: %d\n", a, b, c, medianOfThreeNumbers(a, b, c));
    
    return 0;
}