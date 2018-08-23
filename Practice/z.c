#include <stdio.h>
#include <math.h>

int x;
int y;

/*
int main()
{
	int n;
	n = -1;

	Traverse(4, 0, 0, 12, 8, &n);
	printf("%d", n);
}
*/
int Traverse(int d, int sx, int sy, int tx, int ty, int* n)
{

	if (tx >= sx + pow(2, d) || ty >= sy + pow(2, d))
	{
		*n += ( (int)pow(2, d) * (int)pow(2, d) );

		return 1;
	}

	if (d == 1)
	{
		if (sx == tx)
		{
			if (sy == ty)
				*n += 1;
			else
				*n += 2;
		}
		else
		{
			if (sy == ty)
				*n += 3;
			else
				*n += 4;
		}

		return 0;
	}

	while(1)
	{

		d--;

		if (!(Traverse(d, sx, sy, tx, ty, n)))
			break;
		if( !(Traverse(d, sx, (sy + pow(2, d)), tx, ty, n)) )
			break;
		if( !(Traverse(d, (sx + pow(2, d)), sy, tx, ty, n)) )
			break;
		if( !(Traverse(d, (sx + pow(2, d)), (sy + pow(2, d)), tx, ty, n)) )
			break;

	}
	
	return 0;
}