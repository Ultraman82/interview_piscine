#include "header.h"

 void swap(t_player **a, t_player **b)
{
	t_player *t = *a;
	*a = *b;	
	*b = t;	
}
  
//if string t1 is earlier than t2, return 1
int cmp_t(char *t1, char *t2)
{       
	struct tm tm1, tm2;
	strptime(t1, "%Y:%M:%D %H:%M:%S", &tm1);
	strptime(t2, "%Y:%M:%D %H:%M:%S", &tm2);
	time_t t_1 = mktime(&tm1);
	time_t t_2 = mktime(&tm2);	
	return difftime(t_1, t_2) ? 1 : 0;    
}

// Merges two subarrays of players[]. 
// First subarray is players[l..m] 
// Second subarray is players[m+1..r] 
void merge(t_player **players, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    t_player *L[n1], *R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = players[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = players[m + 1+ j]; 
  
    /* Merge the temp arrays back into players[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i]->score > R[j]->score) 
            players[k] = L[i++]; 
        else if (L[i]->score == R[j]->score && cmp_t(L[i]->timeStamp, R[j]->timeStamp))
            players[k] = L[i++];
        else
            players[k] = R[j++];
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)     
        players[k++] = L[i++]; 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
        players[k++] = R[j++];     
} 
  
/* l is for left index and r is right index of the 
   sub-array of players to be sorted */
void ft_mergesort(t_player **players, int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        ft_mergesort(players, l, m); 
        ft_mergesort(players, m+1, r); 
  
        merge(players, l, m, r); 
    } 
}

struct s_player **mergeSort(struct s_player **players)
{
	int len = 0;
	while (players[len])
		len++;	
	ft_mergesort(players, 0, len - 1);
    return players;
}