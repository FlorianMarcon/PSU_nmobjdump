/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** tests_utils.1
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "stock_file.h"
#include "nm.h"

Test(find_name_section, test)
{
	void *p = stock_file("./print");
	void *tab_section;

	cr_assert_neq(p, NULL);
	tab_section = find_name_section(p);
	cr_assert_eq((long int)(tab_section - p), 0x18cb);
}

Test(find_section_header, test)
{
	void *p = stock_file("./print");
	Elf64_Ehdr *elf = p;
	Elf64_Shdr *header_section;

	header_section = find_section_header(elf, SHT_NULL);
	cr_assert_neq(header_section, NULL);
	cr_assert_eq((long int)((void *)header_section - p ), 0x19d8);
}

Test(section_str, test)
{
	// void *p = stock_file("./print");
	// Elf64_Ehdr *elf = p;
	// void *s = find_section(elf, find_section_header(elf, SHT_STRTAB));
}

Test(section_by_name, test)
{
	void *p = stock_file("./print");
	Elf64_Ehdr *elf = p;
	Elf64_Shdr *header_section;

	header_section = find_section_header_by_name(elf, ".strtab");
	cr_assert_neq(header_section, NULL);
	cr_assert_eq((long int)(header_section->sh_offset), 0x16b8);
}