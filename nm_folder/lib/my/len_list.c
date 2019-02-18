/*
** EPITECH PROJECT, 2017
** my_int_in_list.c
** File description:
** mettre les int dans une listes
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int	len_list(struct linked_list *tmp)
{
	int i = 1;

	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL) {
		tmp = tmp->next;
		i++;
	}
	return (i);
}
