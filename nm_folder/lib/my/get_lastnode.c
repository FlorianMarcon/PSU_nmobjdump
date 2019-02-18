/*
** EPITECH PROJECT, 2017
** my_int_in_list.c
** File description:
** mettre les int dans une listes
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

struct linked_list	*get_lastnode(struct linked_list *tmp)
{
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
