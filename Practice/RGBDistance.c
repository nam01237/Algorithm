#include <stdio.h>

int calc(int(*houses)[3], int n)
{
	int temp;

	for (int i = 1; i < n; i++)
	{
		houses[i][0] += houses[i - 1][1] < houses[i - 1][2] ? houses[i - 1][1] : houses[i - 1][2];
		houses[i][1] += houses[i - 1][0] < houses[i - 1][2] ? houses[i - 1][0] : houses[i - 1][2];
		houses[i][2] += houses[i - 1][0] < houses[i - 1][1] ? houses[i - 1][0] : houses[i - 1][1];

	}

	temp = houses[n - 1][0];

	for (int k = 0; k < 3; k++)
	{
		if ((houses[n - 1][k] < temp))
		{
			temp = houses[n - 1][k];
		}
	}

	return temp;
}

/*int main()
{
	
	int n = 3;
	int houses[1000][3] =
	{
	{ 26, 40, 83 },
	{ 49, 60, 57 },
	{ 13, 89, 99 }
	};

	/*
	int n;
	int houses[1000][3];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &houses[i][j]);
		}

	}
	printf("%d", calc(houses, n));

	return 0;
}*/



