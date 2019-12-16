
#include "header.h"

size_t hash(char *input, size_t len)
{
	size_t hash = 0;
	size_t i = 0;
	while (input[i] != '\0' && i < len)
	{
		hash += (hash << 5) + input[i];
		hash -= (hash >> 2) - input[i];
		i++;
	}
	return (hash);
}

struct s_dict *dictInit(int capacity)
{
	t_dict *dict;

	dict = (t_dict *)malloc(sizeof(t_dict));
	dict->capacity = capacity;
	if (!(dict->items = (t_item **)malloc(sizeof(t_item *) * capacity)))
		return (NULL);
	for (int i = 0; i < capacity; i++)
		dict->items[i] = NULL;
	return (dict);
}

int dictInsert(struct s_dict *dict, char *key, int value)
{
	size_t index;
	t_item *cursor;

	index = hash(key, strlen(key)) % dict->capacity;
	if (!(dict->items[index]))
	{
		if (!(dict->items[index] = (t_item *)malloc(sizeof(t_item))))
			return (0);
		cursor = dict->items[index];
	}
	else
	{
		cursor = dict->items[index];
		while (cursor->next)
		{
			if (!strcmp(cursor->key, key))
			{
				cursor->value = value;
				return (1);
			}
			cursor = cursor->next;
		}
		if (!(cursor->next = (t_item *)malloc(sizeof(t_item))))
			return (0);
		cursor = cursor->next;
	}
	cursor->key = strdup(key);
	cursor->value = value;
	//printf("key %s was put with value: %d, index: %zu\n", cursor->key, cursor->value, index);
	cursor->next = NULL;
	return (1);
}

int dictSearch(struct s_dict *dict, char *key)
{
	size_t index;
	t_item *cursor;

	index = hash(key, strlen(key)) % dict->capacity;
	if (!(cursor = dict->items[index]))
		return (-1);
	while (cursor)
	{
		if (!strcmp(cursor->key, key))
			return (cursor->value);
		cursor = cursor->next;
	}
	return (-1);
}

int is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char *compress(char *book, struct s_dict *dict)
{
	t_item *item;
	char *s;

	size_t i = 0;
	size_t j = 0;
	size_t loc;

	s = malloc(strlen(book));

	while (book[i])
	{
		loc = 0;
		while (!is_letter(book[i]))
			s[j++] = book[i++];
		while (is_letter(book[i]))
		{
			loc++;
			i++;
		}
		//dictSearch
		item = dict->items[hash(&book[i - loc], loc) % dict->capacity];
		//item = dictSearch(dict, hash(&book[i - loc], loc) % dict->capacity];

		while (item)
		{
			if (strncmp(item->key, &book[i - loc], loc) == 0)
				break;
			else
				item = item->next;
		}
		if (item)
		{
			s[j++] = '@';
			if (item->value < 32 && item->value > 9)
			{
				s[j++] = (item->value / 10) + '0';
				s[j++] = (item->value % 10) + '0';
			}
			else if (item->value < 10)
			{
				s[j++] = '^';
				s[j++] = item->value + '0';
			}
			else
			{
				s[j++] = item->value;
			}
		}
		else
		{
			while (loc > 0)
				s[j++] = book[i - (loc--)];
		}
	}
	s[j] = 0;
	return (s);
}