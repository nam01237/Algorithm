#include <stdio.h>

int p;
int n;
int cost[16][16];
int dp[1 << 16];

int plant(int cur, int mask)
{
	if (cur == p)
		return 0;

	if (dp[mask] != -1)
		return dp[mask];

	int temp;

	for (int i = 0; i < n; i++)
	{
		if (mask & (1 << i))
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					continue;

				if ( (mask & (1 << j)) == 0)
				{
					temp = plant(cur + 1, mask | (1 << j)) + cost[i][j];
					dp[mask] = ((dp[mask] > temp) || (dp[mask] == -1)) ? temp : dp[mask];
				}

			}
		}
	}
	return dp[mask];
}

int main()
{
	int k = 0;
	char str[17];
	int mask = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}

	scanf("%s", str);
	scanf("%d", &p);

	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'Y')
		{
			mask = mask | (1 << i);
			k++;
		}
	}

	for (int i = 0; i < (1 << 16); i++)
	{
		dp[i] = -1;
	}

	if (k == 0)
	{
		if (p == 0)
			printf("0");
		else
			printf("-1");
	}
	else if (k >= p)
		printf("0");
	else
		printf("%d", plant(k, mask));
}

