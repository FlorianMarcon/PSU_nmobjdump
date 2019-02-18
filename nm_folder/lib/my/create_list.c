/*
** EPITECH PROJECT, 2017
** create_list
** File description:
** create_list
*/

#include "my.h"
#include <stdlib.h>

linked_list_t	*create_list(void *data)
{
	linked_list_t *list = malloc(sizeof(*list));

	if (list == NULL)
		return (NULL);
	list->next = NULL;
	list->data = data;
	return (list);
}
