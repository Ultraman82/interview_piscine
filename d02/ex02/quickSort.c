#include "header.h"

 void swap(t_player **a, t_player **b)
{
	t_player *t = *a;
	*a = *b;	
	*b = t;	
}

int partition(t_player **players, int low, int high)
{
	
	t_player *pivot = players[high];			// selecting last element as pivot	
	int i = low-1;
	
	for (int j = low; j <= high - 1; j++)
	{
		// If the current element is smaller than or equal to pivot
		if (players[j]->score > pivot->score)		
		{	
			i++; // increment index of smaller element
			swap(&players[i], &players[j]);
		}
	}
	
	swap(&players[i + 1], &players[high]);
	return (i + 1);
}

void quicksort(t_player **players, int first, int last)
{
	//printf("quicksort\n");
	if (first < last)
	{
		int pivot;
		pivot = partition(players, first, last);
		quicksort(players, first, pivot - 1);
		quicksort(players, pivot + 1, last);
	}
}

void quickSort(t_player **players)
{
	int len = 0;
	while (players[len])
		len++;	
	quicksort(players, 0, len - 1);
}