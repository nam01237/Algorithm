#include <stdio.h>

int field[50][50];
int row, col;
int mask[50][50];

void goWorm(int r, int c)
{
	mask[r][c] = 1;

	if (c < (col - 1))
		if ((field[r][c + 1] == 1) && (mask[r][c + 1] == 0) )
			goWorm(r, c + 1);

	if (r < (row - 1))
		if ((field[r + 1][c] == 1) && (mask[r + 1][c] == 0))
			goWorm(r + 1, c);

	if (c > 0)
		if ((field[r][c - 1] == 1) && (mask[r][c - 1] == 0))
			goWorm(r, c - 1);

	if (r > 0)
		if ((field[r - 1][c] == 1) && (mask[r - 1][c] == 0))
			goWorm(r - 1, c);

	field[r][c] = 0;
}

/*
int main()
{
	int t, n;
	int worm;
	int r, c;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &col, &row, &n);
		worm = 0;

		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				mask[j][k] = 0;

		for (int j = 0; j < n; j++)
		{
			scanf("%d %d", &c, &r);
			field[r][c] = 1;
		}

		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				if (field[j][k] == 1)
				{
					goWorm(j, k);
					worm++;
				}
			}
		}

		printf("%d\n", worm);
	}
}
*/