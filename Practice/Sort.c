#include <stdio.h>

void SwapInt(int * num1, int * num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void BubbleSort(int * arr, int n)
{
	int temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - (i + 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				SwapInt(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void SelectionSort(int * arr, int n)
{
	int idx;

	for (int i = 0; i < n; i++)
	{
		idx = i;

		for (int j = (i + 1); j < n; j++)
		{
			if (arr[idx] > arr[j])
				idx = j;
		}

		SwapInt(&arr[idx], &arr[i]);
	}

}

void InsertionSort(int * arr, int n)
{
	int pivot;
	int idx;

	for (int i = 1; i < n; i++)
	{
		pivot = arr[i];
		idx = i;

		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] > pivot)
			{
				arr[j + 1] = arr[j];
				idx = j;
			}
		}

		arr[idx] = pivot;
	}

}
/*
int main()
{
	int arr1[6] = { 1, 5, 6, 8 ,3, 4 };
	BubbleSort(arr1, 6);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");

	int arr2[7] = { 0, 3, 7, 8, 2, 1, 5 };
	SelectionSort(arr2, 7);

	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	int arr3[5] = { 3, 1, 4, 5, 2 };
	InsertionSort(arr3, 5);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr3[i]);
	}
	printf("\n");

}*/