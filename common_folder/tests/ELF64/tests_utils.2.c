/*
** EPITECH PROJECT, 2019
** objdump_folder
** File description:
** tests_utils.1
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "common.h"

Test(ELF_verification_magic, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");

	cr_assert_eq(ELF_verification_magic(elf), 0);
	((char *)elf)[0] = 0x89;
	cr_assert_eq(ELF_verification_magic(elf), 1);
}