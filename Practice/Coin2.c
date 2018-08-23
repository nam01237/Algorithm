#include <stdio.h>

int main()
{
	int n;
	int k;
	int coins[100];
	int dp[10001];

	for (int i = 1; i < 10001; i++)
	{
		dp[i] = -1;
	}

	dp[0] = 0;

	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coins[i]);
	}

	for (int i = 1; i <= k; i++)
	{
		int temp = -2;

		for (int j = 0; j < n; j++)
		{
			if ( (coins[j] <= i) && !(coins[j] == 0) )
			{
				if ((temp == -2) || (temp > dp[i - coins[j]]))
				{
					if( dp[i - coins[j]] != -1)
						temp = dp[i - coins[j]];
				}

			}
		}

		dp[i] = temp + 1;
	}

	printf("%d", dp[k]);
}
