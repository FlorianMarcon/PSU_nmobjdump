/*
** EPITECH PROJECT, 2019
** nm_folder
** File description:
** tests_utils.1
*/

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include "nm.h"

Test(swap, test)
{
	int a = 1;
	int b = 2;
	int c = 3;
	linked_list_t *list = create_list(&c);

	create_node(list, &a);
	create_node(list, &b);

	cr_assert_eq(len_list(list), 3);
	cr_assert_eq(list->data, &c);
	cr_assert_eq(list->next->data, &a);
	cr_assert_eq(list->next->next->data, &b);
	
	swap_node(&list, list, list->next->next);
	// swap_node(&list, list, list->next);
	// cr_assert_eq(len_list(list), 3);
	
	// cr_assert_eq(list->data, &a);
	// cr_assert_eq(list->next->data, &b);
	// cr_assert_eq(list->next->next->data, &c);
}
Test(compare_name, test)
{
	cr_assert_eq(compare_name("___abCd", "__aBcd"), 0);
	cr_assert_eq(compare_name("___aBd", "__aBCd"), 1);
	cr_assert_eq(compare_name("_abCd", "__abd"), -1);
}
// Test(compare_name, test2)
// {
// 	cr_assert_eq(compare_name("concat", "concat_dec_part"), 0);
// 	cr_assert_eq(compare_name("concat_dec_part", "concat"), -1);
// }