#include <stdio.h>
#include <math.h>

int Diviosor(int num1, int num2)
{
	int min = num1;
	int max = num2;

	if (num1 > num2)
	{
		max = num1;
		min = num2;
	}

	int i = 0;
	int result;

	while (1)
	{
		if (i == min)
			return 0;

		i++;

		result = min / i;

		if ((min % i) == 0)
			if ((max % result) == 0)
				break;
	}

	return result;
}

int Multiple(int num1, int num2)
{
	int min = num1;
	int max = num2;

	if (num1 > num2)
	{
		max = num1;
		min = num2;
	}

	int i = 1;
	int result;

	while (1)
	{
		result = max * i;

		if ((result % min) == 0)
			break;
	}

	return result;
	
}
/*
int main()
{
	printf("%d\n", Diviosor(1250, 50));
	printf("%d\n", Multiple(5, 10));
	
}
*/