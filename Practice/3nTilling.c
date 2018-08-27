#include <stdio.h>
#include <math.h>

/*
int main() {

	int n = 30;
	int dp[5001];
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		if ( (int)(i % 2) == 1)
		{
			dp[i] = 0;
			continue;
		}

		dp[i] = dp[i - 2] * 3;

		for (int j = 4; j < i; j += 2)
		{
			dp[i] += dp[i - j] * 2;
		}

		dp[i] += 2;
		
	}

	printf("%d", dp[n]);

}
*/