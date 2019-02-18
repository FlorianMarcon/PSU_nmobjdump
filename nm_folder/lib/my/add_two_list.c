/*
** EPITECH PROJECT, 2017
** my_int_in_list.c
** File description:
** mettre les int dans une listes
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void	add_two_list(struct linked_list *first, struct linked_list *second)
{
	struct linked_list *tmp = first;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = second;
}
