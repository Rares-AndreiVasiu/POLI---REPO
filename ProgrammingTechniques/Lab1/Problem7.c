#include <stdio.h>
#include <string.h>


#define DBG 1

int ISBN_validity(char *s)
{
	if(strlen(s) != 13)
	{
		return 0;
	}

	int weighted_sum = 0;

	for(int i = 0; i < 13; ++ i)
	{
		int digit = s[i] - '0';

		if(i & 1)
		{
			#if DBG == 1
			printf("%d %d \n", digit * 3, i);
			#endif

			weighted_sum += digit * 3;
		}
		else
		{
			#if DBG == 1
			printf("%d %d\n", digit, i);
			#endif
			weighted_sum += digit;
		}
	}

	int last_digit = (s[strlen(s) - 1]) - '0';
	
	#if DBG == 1
	printf("Last digit: %d, weighted sum:  %d\n", last_digit, weighted_sum);
	#endif
	if(last_digit == (10 -  weighted_sum % 10))
	{
		return 1;
	}	

	return 0;
}

int main()
{

	printf("Check if this number is valid ISBN-13: 9781435704572, %d\n", ISBN_validity("9781435704572"));


	return 0;
}
