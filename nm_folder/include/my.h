/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header my.h
*/

#include <stdbool.h>
#include <stdarg.h>

#ifndef MY_
#define MY_

void	my_putchar(char c);

int	my_isneg(int nb);

int	my_put_nbr(int nb);

void	my_put_unnbr(unsigned int);

int	my_swap(int *a, int *b);

int	my_putstr(char const *str);

int	my_strlen(char const *str);

int	my_getnbr(char const *str);

int	my_getnbr_before_letter(char const *str);

void	my_sort_int_array(int *tab, int size);

int	my_compute_power_rec(int nb, int power);

int	my_compute_square_root(int nb);

int	my_is_prime(int nb);

int	my_find_prime_sup(int nb);

char	*my_strcpy(char *dest, char const *src);

char	*my_strncpy(char *dest, char const *src, int n);

char	*my_revstr(char *str);

char	*my_strstr(char const *str, char const *to_find);

int	my_strcmp(char const *s1, char const *s2);

int	my_strncmp(char const *s1, char const *s2, int n);

char	*my_strupcase(char *str);

char	*my_strlowcase(char *str);

char	*my_strcapitalize(char *str);

int	my_str_isalpha(char const *str);

int	my_char_isalpha(char c);

int	my_char_isnum(char c);

int	my_str_isnum(char const *str);

int	my_str_islower(char const *str);

int	my_str_isupper(char const *str);

int	my_str_isprintable(char const *str);

int	my_showmem(char const *str, int size);

int	my_showstr(char const *str);

int	my_show_word_array(char *const *tab);

char	*my_strcat(char *dest, char const *src);

char	*my_strncat(char *dest, char const *src, int nb);

char	*my_strdup(char const *str);

char	*concat_params(int argc, char **argv);

int	my_show_word_array(char * const *tab);

char	**mise_en_tableau(char const *str, int nb_separateur);

int	separateur(char const *str);

char	*convert_base(char const *nbr, char const *base_from,
							char const *base_to);

char	*convert_baseten_to_n(int nb, char *base_to);

int	lenint(int nb);

int	len_unint(unsigned int);

char	*stock_int_in_str(int nb);

char    **parsing_str(char *str, char separator);

int     len_tab(char **tab);

typedef struct linked_list
{
	void *data;
	struct linked_list *next;
} linked_list_t;

linked_list_t	*create_list(void *data);

void	create_node(struct linked_list *tmp, void *dat);

void	delete_node(struct linked_list *precedent);

void	add_node(struct linked_list *precedent, struct linked_list *new);

struct linked_list	*get_lastnode(struct linked_list *tmp);

int	len_list(struct linked_list *tmp);

void	add_two_list(struct linked_list *first, struct linked_list *second);

#endif
