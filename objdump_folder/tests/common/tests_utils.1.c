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
#include "objdump.h"
#include "flags.h"

Test(flags_init, test)
{
	flags_t flag;

	flags_init(&flag);
	cr_assert_eq(flag.has_reloc, false);
	cr_assert_eq(flag.exec_p, false);
	cr_assert_eq(flag.has_lineno, false);
	cr_assert_eq(flag.has_debug, false);
	cr_assert_eq(flag.has_syms, false);
	cr_assert_eq(flag.has_locals, false);
	cr_assert_eq(flag.dynamic, false);
	cr_assert_eq(flag.wp_text, false);
	cr_assert_eq(flag.d_paged, false);
}

Test(flags_getString, test)
{
	cr_assert_str_eq("HAS_RELOC", flags_getString(HAS_RELOC));
	cr_assert_str_eq("EXEC_P", flags_getString(EXEC_P));
	cr_assert_str_eq("HAS_LINENO", flags_getString(HAS_LINENO));
	cr_assert_str_eq("HAS_DEBUG", flags_getString(HAS_DEBUG));
	cr_assert_str_eq("HAS_SYMS", flags_getString(HAS_SYMS));
	cr_assert_str_eq("HAS_LOCALS", flags_getString(HAS_LOCALS));
	cr_assert_str_eq("DYNAMIC", flags_getString(DYNAMIC));
	cr_assert_str_eq("WP_TEXT", flags_getString(WP_TEXT));
	cr_assert_str_eq("D_PAGED", flags_getString(D_PAGED));
}

Test(flags_display, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");	
	flags_t flags;

	cr_assert_neq(elf, NULL);
	ELF64_setFlags(elf, &flags);
	cr_redirect_stdout();
	flags_display(NULL);
	flags_display(&flags);
	//No flags to display no flag
	flags_init(&flags);
	flags_display(&flags);
	cr_assert_stdout_eq_str("EXEC_P, HAS_SYMS, D_PAGED\nBFD_NO_FLAGS\n");
}

Test(flags_sum, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");	
	flags_t flags;

	cr_assert_neq(elf, NULL);
	flags_init(&flags);
	cr_assert_eq(flags_sum(&flags), 0x00);
	ELF64_setFlags(elf, &flags);
	cr_assert_eq(flags_sum(&flags), 0x112);
}