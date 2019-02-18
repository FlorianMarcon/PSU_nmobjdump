/*
** EPITECH PROJECT, 2017
** my_int_in_list.c
** File description:
** mettre les int dans une listes
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void	create_node(struct linked_list *tmp, void *dat)
{
	struct linked_list *new = malloc(sizeof(struct linked_list));

	if (new == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->data = dat;
	new->next = NULL;
}
