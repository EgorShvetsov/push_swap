/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:29:41 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/11 19:29:44 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			close_to_max(t_st *tab)
{
	int		calc;
	int		i;

	calc = 0;
	i = 0;
	while (i < tab->size_b)
	{
		if (tab->b[i] > tab->b[tab->size_b - 1])
			calc++;
		i++;
	}
	if (calc && calc < 3)
		return (1);
	return (0);
}

void		in_case_of_broken_a(t_st *tab)
{
	int		move_calc;

	move_calc = 0;
	while (tab->a[0] < tab->b[tab->size_b - 1])
	{
		rotate(tab->a, tab->size_a);
		ft_putstr("ra\n");
		move_calc++;
	}
	pa(tab);
	while (move_calc)
	{
		r_rotate(tab->a, tab->size_a);
		ft_putstr("rra\n");
		move_calc--;
	}
}
