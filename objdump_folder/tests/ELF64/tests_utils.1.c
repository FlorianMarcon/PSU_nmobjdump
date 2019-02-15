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