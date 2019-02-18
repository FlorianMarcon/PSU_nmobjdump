/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** tests_utils.1
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "stock_file.h"

Test(stock_file, test)
{
	void *p = stock_file("file which don't exist");
	
	cr_assert_eq(p, NULL);
	p = stock_file("./print");
	cr_assert_neq(p, NULL);
}