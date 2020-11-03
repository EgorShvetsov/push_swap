/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:04:03 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/14 17:04:06 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chose_dir(int *tab, int size)
{
	int		i;
	int		low;

	i = 1;
	low = 0;
	while (i < size)
	{
		if (tab[i] < tab[low])
			low = i;
		i++;
	}
	return (low);
}

void		in_case_of_five(t_st *tab)
{
	int		direction;
	int		low;

	while (tab->size_a > 3)
	{
		low = chose_dir(tab->a, tab->size_a);
		if (low == 3 || low == 4)
		{
			r_rotate(tab->a, tab->size_a);
			ft_putstr("rra\n");
		}
		else if (low == 2 || low == 1)
		{
			rotate(tab->a, tab->size_a);
			ft_putstr("ra\n");
		}
		else
			pb(tab);
	}
	in_case_of_three(tab);
	while (tab->size_b)
		pa(tab);
}
