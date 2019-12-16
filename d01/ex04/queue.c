#include "header.h"

struct s_queue *queueInit(void)
{
    t_queue *qu = malloc(sizeof(t_queue));
    qu->first = NULL;
    qu->last = NULL;
    return qu;
};

void enqueue(struct s_queue *queue, char *message)
{
    t_node *new = malloc(sizeof(t_node));

    if (queue->first)
        queue->last->next = new;
    else
        queue->first = new;
    new->message = message;
    queue->last = new;
    new->next = NULL;
}

char *dequeue(struct s_queue *queue)
{
    t_node *tmp;

    if (queue->first)
    {
        tmp = queue->first;
        queue->first = queue->first->next;
        if (!queue->first)
            queue->last = 0;
        return tmp->message;
    }
    return 0;
}

char *peek(struct s_queue *queue)
{
    if (queue->first)
        return queue->first->message;
    return 0;
}

int isEmpty(struct s_queue *queue)
{
    if (queue->first)
        return 0;
    return 1;
}