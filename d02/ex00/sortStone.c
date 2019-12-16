#include "header.h"

 void swap(t_stone **a, t_stone **b)
{
	int tmp = (*a)->size;
	(*a)->size = (*b)->size;	
	(*b)->size = tmp;	
}

void sortStones(struct s_stone **stone)
{
    t_stone *ini = *stone;    
    int sorted = 0;
    while(!sorted)
    {
        sorted = 1;
        while(ini->next)
        {
            if(ini->size > ini->next->size)
            {
                swap(&ini, &ini->next);                    
                sorted = 0;
            }            
            ini = ini->next;
        }
        ini = *stone;
    }
}