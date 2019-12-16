#include <limit.h>

struct s_node
{
    int value;
    struct s_node *right;
    struct s_node *left;
};

void kthDFS(struct s_node *node, int *k, int *value)
{
    if (!node || *k < 1)
        return;
    kthDFS(node->left, k, value);
    if (*k == 1)
        *value = node->value;
    (*k)--;
    kthDFS(node->right, k, value);
}

int kthSmallest(struct s_node *bst, int k)
{
    int value = INT_MIN;
    if (!bst || k < 1)
        return (value);
    kthDFS(bst, &k, &value);
    return (value);
}