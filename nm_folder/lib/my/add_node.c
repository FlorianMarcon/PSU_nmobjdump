/*
** EPITECH PROJECT, 2017
** add_node.c
** File description:
** mettre les int dans une listes
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void	add_node(struct linked_list *precedent, struct linked_list *new)
{
	new->next = precedent->next;
	precedent->next = new;
}
