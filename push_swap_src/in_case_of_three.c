/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_case_of_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:14:42 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/11 19:14:45 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_max(int *tab, int size, int num)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > num)
			return (0);
		i++;
	}
	return (1);
}

static void	add_2(t_st *tab)
{
	rotate(tab->a, tab->size_a);
	ft_putstr("ra\n");
}

static void	in_case_of_three_add(t_st *tab)
{
	if (tab->a[0] > tab->a[2])
	{
		r_rotate(tab->a, tab->size_a);
		ft_putstr("rra\n");
	}
	else
	{
		r_rotate(tab->a, tab->size_a);
		ft_putstr("rra\n");
		f_swap_a(tab->a);
		ft_putstr("sa\n");
	}
}

void		in_case_of_three(t_st *tab)
{
	if (tab->size_a == 2)
	{
		f_swap_a(tab->a);
		ft_putstr("sa\n");
	}
	else if (is_max(tab->a, tab->size_a, tab->a[0]) && tab->a[1] > tab->a[2])
	{
		f_swap_a(tab->a);
		ft_putstr("sa\n");
		r_rotate(tab->a, tab->size_a);
		ft_putstr("rra\n");
	}
	else if (is_max(tab->a, tab->size_a, tab->a[1]))
		in_case_of_three_add(tab);
	else if (is_max(tab->a, tab->size_a, tab->a[0]) && tab->a[1] < tab->a[2])
		add_2(tab);
	else if (is_max(tab->a, tab->size_a, tab->a[2]))
	{
		f_swap_a(tab->a);
		ft_putstr("sa\n");
	}
}
