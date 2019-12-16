#include "header.h"

struct s_stack *stackInit(void)
{
	t_stack	*s = (t_stack *)malloc(sizeof(t_stack));
	if (s)
		s->item = NULL;
	else
		return (NULL);
	return (s);
}

int pop(struct s_stack *stack)
{
	t_item  *tmp;

    tmp = stack->item;
    stack->item = tmp->next;
	return (tmp->idx);
}

void push(struct s_stack *stack, int idx)
{
	t_item *new = malloc(sizeof(t_item));

    new->idx = idx;
    new->next = stack->item;
    stack->item = new;    
}

char *console(void)
{
    char    *message = malloc(sizeof(char) * 256);
    char    in[256];
    int     idx = 0;
    int     last_word_len = 0;
    t_stack *stack = stackInit();

    bzero(message, 256);
    while (1)
    {
        bzero(in, 256);
        printf("<msg:>: ");
        fgets(in, 256, stdin);
        in[strlen(in) - 1] = '\0';
        if (!strcmp(in, "SEND"))
            break ;
        else if (!strcmp(in, "UNDO") )
        {
            if (stack->item) {
                idx = pop(stack);
                last_word_len = strlen(message) - idx;                
            }            
            bzero(message + idx, last_word_len);
        }
        else
        {
            push(stack,idx);            
            strncpy(message + idx, in, strlen(in));
            idx += strlen(in);            
        }
        printf("%s\n\n", message);
    }
    return (message);

}

