#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
typedef struct s_art {
	char name;
	int price;
} t_art;


void swap(t_art *a, t_art *b)
{
    t_art *t = malloc(sizeof(t_art));

	t->name = a->name;
	t->price = a->price;
    *a = *b;
	printf("t.name: %c, t.price: %d\n", t->name, t->price);
    *b = *t;
}


int main() {
	struct s_art stack[10];
	int i = 0;
	char *s1="INTERIOR - WHITE MOUNTAINS";
	char *s2="Headpiece (page 110) from LE MONDE MERVEILLEUX DES INSECTES";


	while(i < 10)
	{
		stack[i].name = 'a' + i;
		stack[i].price = i;
		i++;
	}
	i = 0;
	swap(&stack[0], &stack[1]);
	printf("strcmp: %d\n", strcmp(s1, s2));
	while(i <10)
	{
		printf("%c, %d\n", stack[i].name, stack[i].price);
		i++;
	}
//	stack[0]->name = "a";
//	stack[0]->price = 0;

//	printf("%s, %d\n", stack[0]->name, stack[0]->price);

	return 0;
}
