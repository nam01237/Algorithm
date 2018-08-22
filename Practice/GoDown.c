#define MAX_COUNT 100000
#include <stdio.h>

int GetMax(int* temp, int n)
{
	int index = 0;

	for (int i = 1; i < n; i++)
	{
		if (temp[i] > temp[index])
		{
			index = i;
		}
	}

	return temp[index];
}

int GetMin(int* temp, int n)
{
	int index = 0;

	for (int i = 1; i < n; i++)
	{
		if (temp[i] < temp[index])
		{
			index = i;
		}
	}

	return temp[index];
}


int main()
{

	int n;
	scanf("%d", &n);
	int input[3] = { 0, 0, 0 };
	int dpMin[3] = {0, 0, 0};
	int dpMax[3] = { 0, 0, 0 };
	int temp[3] = { 0, 0, 0 };

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &input[j]);
			temp[j] = 0;
		}

		temp[0] += ( (dpMax[0] > dpMax[1] ? dpMax[0] : dpMax[1]) + input[0] );
		temp[2] += ( (dpMax[1] > dpMax[2] ? dpMax[1] : dpMax[2]) + input[2] );
		temp[1] += ( GetMax(dpMax, 3) + input[1] );

		for (int j = 0; j < 3; j++)
		{
			dpMax[j] = temp[j];
			temp[j] = 0;
		}

		temp[0] += ( (dpMin[0] < dpMin[1] ? dpMin[0] : dpMin[1]) + input[0]);
		temp[2] += ( (dpMin[1] < dpMin[2] ? dpMin[1] : dpMin[2]) + input[2]);
		temp[1] += ( GetMin(dpMin, 3) + input[1] );

		for (int j = 0; j < 3; j++)
		{
			dpMin[j] = temp[j];
		}

	}

	printf("%d %d", GetMax(dpMax, 3), GetMin(dpMin, 3));

	return 0;
}

