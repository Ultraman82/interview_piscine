#include "header.h"

int is_sorted(int *rocks, int left, int right)
{
    return rocks[left] < rocks[right];
}

int is_in_possible_range(int *rocks, int left, int right, int value)
{
    
    if(is_sorted(rocks, left, right))
        return (value >= rocks[left] && value <= rocks[right]);
    else 
        return (rocks[left] >= value || rocks[right] <= value);        
}

int binary_search(int *rocks, int left, int right, int value)
{
	int mid, cmp;
    int ret = -1;
        
    if (!is_in_possible_range(rocks, left, right, value))
        return -1;

	mid = (left + right) / 2;
	cmp = rocks[mid] - value;    
    
    if(rocks[left] == value)
        return left;
	else if (cmp == 0)    
        return (mid);
    else if(rocks[right] == value)
        return right;
    else if (left >= right)
        return -1;        

    if(is_sorted(rocks, left, right))
    {
        if (cmp < 0)
            left = mid + 1;
        else if (cmp > 0)
            right = mid - 1;
        return binary_search(rocks, left, right, value);    
    } else {
        ret = binary_search(rocks, left, mid - 1, value);
        if (ret != -1)
            return ret;        
        ret = binary_search(rocks, mid + 1 , right, value);    
        if (ret != -1)
            return ret;        
    }
    return -1;
}    

int	searchShifted(int *rocks, int length, int value)
{
    int i = binary_search(rocks, 0, length -1, value); 

    if(i != -1)
        while(rocks[i - 1] == value)
            i--;              
    return i;
}