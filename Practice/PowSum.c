#include <stdio.h>
#include <math.h>

/*
int main()
{
	int n;
	scanf("%d", &n);
	int dp[100001];
	
	dp[0] = 0;

	int k;
	int temp;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;

		k = (int)sqrt(i);

		temp = -1;

		for (int j = k; j > 0; j--)
		{
			if ((temp == -1) || (temp > dp[i - (int)pow(j, 2)] ))
			{
				temp = dp[i - (int)pow(j, 2)];
			}
		}
		
		dp[i] += temp;

	}

	printf("%d", dp[n]);
}
*/