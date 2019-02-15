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

Test(ELF64_getSectionHeader, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");
	Elf64_Shdr *sections = NULL;

	cr_assert_neq(elf, NULL);
	sections = ELF64_getSectionHeader(NULL);
	cr_assert_eq(sections, NULL);
	sections = ELF64_getSectionHeader(elf);
	cr_assert_neq(sections, NULL);
	cr_assert_eq((void *)sections - (void *)elf, 0x19e0);
}
Test(ELF64_getSectionHeader_byType, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");

	cr_assert_eq(ELF64_getSectionHeader_byType(NULL, 0x00), NULL);
	cr_assert_eq(ELF64_getSectionHeader_byType(elf, 0xFF), NULL);
	cr_assert_neq(ELF64_getSectionHeader_byType(elf, SHT_SYMTAB), NULL);
}
Test(ELF64_getSectionHeader_byName, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");

	cr_assert_eq(ELF64_getSectionHeader_byName(NULL, NULL), NULL);
	cr_assert_eq(ELF64_getSectionHeader_byName(elf, NULL), NULL);
	cr_assert_neq(ELF64_getSectionHeader_byName(elf, ".strtab"), NULL);
}
Test(ELF64_getSectionContent_byType, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");

	cr_assert_eq(ELF64_getSectionHeader_byType(NULL, 0x00), NULL);
	cr_assert_eq(ELF64_getSectionHeader_byType(elf, 0xFF), NULL);
	cr_assert_neq(ELF64_getSectionHeader_byType(elf, SHT_SYMTAB), NULL);
}
Test(ELF64_getSectionContent_byName, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");

	cr_assert_eq(ELF64_getSectionContent_byName(NULL, NULL), NULL);
	cr_assert_eq(ELF64_getSectionContent_byName(elf, NULL), NULL);
	cr_assert_neq(ELF64_getSectionContent_byName(elf, ".strtab"), NULL);
}
Test(ELF64_getSection, test)
{
	Elf64_Ehdr *elf = stock_file("./print/print");

	cr_assert_eq(ELF64_getTableString(NULL), NULL);
	cr_assert_eq(ELF64_getTableString(elf), 0x18cd + (void *)elf);
}