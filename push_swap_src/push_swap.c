/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 13:28:26 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/26 13:28:29 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		more_nulls_for_god_of_nulls(t_st *tab, int *b)
{
	tab->a = NULL;
	tab->b = NULL;
	tab->one_arg = NULL;
	tab->size_one_arg = 0;
	tab->size_a = 0;
	tab->size_b = 0;
	*b = 1;
}

static int		zero_addition_to_main(t_st *tab)
{
	ft_putstr_fd("\x1b[31mError\n\x1b[0m", 2);
	if (tab->a)
		free(tab->a);
	return (0);
}

static void		concat_arrays(t_st *tab)
{
	int			*tmp;
	int			final;
	int			current;

	final = 0;
	current = 0;
	tmp = malloc(sizeof(int) * (tab->size_a + tab->size_one_arg));
	while (current < tab->size_a && tab->a)
		tmp[final++] = tab->a[current++];
	current = 0;
	while (current < tab->size_one_arg)
		tmp[final++] = tab->one_arg[current++];
	if (tab->a)
		free(tab->a);
	free(tab->one_arg);
	tab->a = tmp;
	tab->size_a = final;
	tab->size_one_arg = 0;
}

static int		find_doubles(int *tab, int i)
{
	int			start;

	start = 0;
	while (start < i)
	{
		if (tab[start] == tab[i])
		{
			ft_putstr_fd("\x1b[31mError\n\x1b[0m", 2);
			free(tab);
			return (1);
		}
		start++;
	}
	return (0);
}

int				main(int ac, char **av)
{
	int			b;
	t_st		tab;

	more_nulls_for_god_of_nulls(&tab, &b);
	if (ac == 1)
		return (0);
	while (b < ac)
	{
		if ((!ft_isdigit(av[b][0]) && av[b][0] != '-') || !wwa(av[b], &tab))
			return (zero_addition_to_main(&tab));
		concat_arrays(&tab);
		if (find_doubles(tab.a, tab.size_a - 1))
			return (0);
		b++;
	}
	tab.b = malloc(sizeof(int) * tab.size_a);
	tab.start_a = tab.a;
	tab.start_b = tab.b;
	if (tab.size_a <= 5 && !is_sorted_min_max(tab.a, tab.size_a))
		in_case_of_five(&tab);
	else
		ps(&tab);
	free(tab.start_a);
	free(tab.start_b);
	return (0);
}
