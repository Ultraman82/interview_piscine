#include "header.h"

 void swap(t_art **a, t_art **b)
{
	t_art *t = *a;
	*a = *b;	
	*b = t;	
}

int partition(t_art **arr, int low, int high)
{
	
	t_art *pivot = arr[high];			// selecting last element as pivot	
	int i = low-1;
	
	for (int j = low; j <= high - 1; j++)
	{
		// If the current element is smaller than or equal to pivot
		if (strcmp(arr[j]->name, pivot->name) < 0)		
		{	
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quicksort(t_art **arr, int first, int last)
{
	//printf("quicksort\n");
	if (first < last)
	{
		int pivot;
		pivot = partition(arr, first, last);
		quicksort(arr, first, pivot - 1);
		quicksort(arr, pivot + 1, last);
	}
}

void sortArts(t_art **arts)
{
	int len = 0;
	while (arts[len])
		len++;	
	quicksort(arts, 0, len - 1);
}