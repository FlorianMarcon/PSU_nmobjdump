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

Test(ELF64_showSectionMemory, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");
	Elf64_Shdr *section = ELF64_getSectionHeader_byName(elf, ".interp");
	char output[] = "Contenu de la section .interp :\n\
 400238 2f6c6962 36342f6c 642d6c69 6e75782d /lib64/ld-linux-\n\
 400248 7838362d 36342e73 6f2e3200          x86-64.so.2.    \n";

	cr_assert_neq(section, NULL);
	cr_redirect_stdout();
	ELF64_showSectionMemory(elf, NULL);
	ELF64_showSectionMemory(NULL, section);

	ELF64_showSectionMemory(elf, section);
	cr_assert_stdout_eq_str(output);
}


Test(ELF64_setFlags, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");
	flags_t flags;

	cr_assert_neq(elf, NULL);
	ELF64_setFlags(elf, &flags);
	cr_assert_eq(flags.has_reloc, false);
	cr_assert_eq(flags.exec_p, true);
	cr_assert_eq(flags.has_lineno, false);
	cr_assert_eq(flags.has_debug, false);
	cr_assert_eq(flags.has_syms, true);
	cr_assert_eq(flags.has_locals, false);
	cr_assert_eq(flags.dynamic, false);
	cr_assert_eq(flags.wp_text, false);
	cr_assert_eq(flags.d_paged, true);
}

Test(ELF64_showHeader, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");
	char output[] = "architecture: i386:x86-64, fanions 0x00000112:\n\
EXEC_P, HAS_SYMS, D_PAGED\n\
adresse de départ 0x0000000000400430\n";

	cr_assert_neq(elf, NULL);
	cr_redirect_stdout();
	ELF64_showHeader(elf);
	cr_assert_stdout_eq_str(output);
}