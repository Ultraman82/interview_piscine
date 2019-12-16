#include "header.h"

t_node *search_value(struct s_node *root, char *t1, char *t2)
{

    if (!root)
        return 0;

    int max = 0;
    while (*root->children)
    {
        int tmp = 1 + height_tree(*root->children);
        if (max < tmp)
            max = tmp;
        root->children++;
    }
    return max;
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
}