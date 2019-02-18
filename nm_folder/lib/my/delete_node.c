/*
** EPITECH PROJECT, 2017
** my_int_in_list.c
** File description:
** mettre les int dans une listes
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void	delete_node(struct linked_list *precedent)
{
	struct linked_list *actual = precedent->next;

	precedent->next = precedent->next->next;
	free(actual);
}
