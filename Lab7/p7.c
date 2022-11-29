#include <stdio.h>
#include <stdlib.h>

u_int32_t swapTwoHaves(u_int32_t n)
{
	return ((n & (0xFFFF0000)) >> 16) | ((n & (0xFFFF)) << 16);
}

u_int32_t rotateBits(u_int32_t n)
{
	unsigned rightmostBits = (n & (0xF)); 

	n = (n >> 4) | (rightmostBits << 28);

	return n;
}

u_int32_t swapRotAux(u_int32_t n)
{
	n = swapTwoHaves(n);

	n = rotateBits(n);

	return n;
}

u_int32_t swapRot(u_int32_t n)
{
	int nNib = sizeof(n) * 2;
	
	u_int32_t max = -999999;

	for(int i = 1; i <= nNib; ++ i)
	{
		n = swapRotAux(n);

		if(n > max)
		{
			max = n;
		}
	}
	return max;
}


int main()
{
	
	return 0;
}


