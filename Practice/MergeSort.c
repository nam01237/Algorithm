#include <stdio.h>
#include <stdlib.h>

void Merge(int * arr, int left, int mid, int right)
{
	int lidx = left;
	int ridx = mid + 1;
	int bidx = 0;
	int * buff = (int*)malloc(sizeof(int) * ((right - left)+ 1));

	while ((lidx <= mid) && (ridx <= right))
	{
		if (arr[lidx] > arr[ridx])
			buff[bidx++] = arr[ridx++];
		else
			buff[bidx++] = arr[lidx++];
	}

	if (lidx > mid)
	{
		while (ridx <= right)
			buff[bidx++] = arr[ridx++];
	}
	else
	{
		while (lidx <= mid)
			buff[bidx++] = arr[lidx++];
	}
	bidx = 0;

	for (int i = left; i <= right; i++)
	{
		arr[i] = buff[bidx++];
	}

	free(buff);
}

void MergeSort(int * arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}
/*
int main()
{
	int arr[7] = { 3, 5, 6, 2, 4, 1, 7 };
	MergeSort(arr, 0, 6);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
*/