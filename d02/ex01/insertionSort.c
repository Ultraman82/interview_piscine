#include "header.h"

 void swap(t_player **a, t_player **b)
{
	t_player *t = *a;
	*a = *b;	
	*b = t;	
}

void insertionSort(struct s_player **players) 
{     
    int i, j; 
    for (i = 1; players[i]; i++) {                 
        for(j = i-1;j >= 0 && players[j]->score < players[j+1]->score;j--)                
            swap(&players[j], &players[j+1]);
    } 
}