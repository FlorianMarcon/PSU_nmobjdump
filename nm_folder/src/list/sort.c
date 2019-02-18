/*
** EPITECH PROJECT, 2019
** nm_folder
** File description:
** sort
*/

#include <stdlib.h>
#include "my.h"
#include "nm.h"

// void	swap_node(linked_list_t **head, linked_list_t *one, linked_list_t *two)
// {
// 	linked_list_t *a = *head;
// 	linked_list_t *b = *head;

// 	if (one == NULL || two == NULL)
// 		return;
// 	while(a != one && a->next != one)
// 		a = a->next;
// 	while(b != two && b->next != two)
// 		b = b->next;
// 	// printf("%d  %d\n", *((int *)a->data), *((int*)b->data));
	
// 	b->next = b->next->next;
// 	// if (a->next )
// 	two->next = one;

// 	if (a == one) {
// 		*head = two;
// 	} else {
// 		a->next = two;
// 	}
// }

void	swap_node(linked_list_t *one, linked_list_t *two)
{
	void *tmp;

	if (one == NULL || two == NULL)
		return;
	tmp = one->data;
	one->data = two->data;
	two->data = tmp;
}
int	compare_name(char *a, char *b)
{
	char vala;
	char valb;

	while(*a != 0 || *b != 0) {
		while(isAscii(*a) == 0)
			a++;
		while(isAscii(*b) == 0)
			b++;
		vala = *a;
		valb = *b;
		if (vala == 0 && valb == 0)
			return (1);
		if (vala >= 'a' && vala <= 'z')
			vala -= ('a' - 'A');
		if (valb >= 'a' && valb <= 'z')
			valb -= ('a' - 'A');
		if (vala > valb)
			return (1);
		else if (valb > vala)
			return (-1);
		a++;
		b++;
	}
	return (0);
}
int	compare_item(linked_list_t *one, linked_list_t *two)
{
	symbole_item_t *a;
	symbole_item_t *b;
	int val = 0;

	if (one == NULL || one->data == NULL || two == NULL || two->data == NULL)
		return (-1);
	a = one->data;
	b = two->data;
	val = compare_name(a->name_addr, b->name_addr);
	return (val);
}
linked_list_t	*sort_list(linked_list_t *head)
{
	// linked_list_t *a = head;
	linked_list_t *new = NULL;
	linked_list_t *f;

	while (head != NULL) {
		f = head;
		for (linked_list_t *tmp = head; tmp != NULL; tmp = tmp->next) {
			int comp = compare_item(f, tmp);
			if (comp == 0 || comp == 1)
				f = tmp;
		}
		if (f == head)
			head = head->next;
		if (new == NULL)
			new = create_list(f->data);
		else
			create_node(new, f->data);
		f->data = NULL;
	}
	return (new);
}