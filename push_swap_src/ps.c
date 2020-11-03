/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:09:01 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/27 13:09:02 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_from_a_to_b(t_st *tab, int middle, int *sorted)
{
	if (tab->a[0] <= middle)
	{
		pb(tab);
		if (tab->b[tab->size_b - 1] < mid_b(sorted, middle))
		{
			r_rotate(tab->b, tab->size_b);
			ft_putstr("rb\n");
		}
	}
	else
	{
		if (chose_direction_a(tab->a, tab->size_a, middle) > 0)
		{
			rotate(tab->a, tab->size_a);
			ft_putstr("ra\n");
		}
		else if (chose_direction_a(tab->a, tab->size_a, middle) < 0)
		{
			r_rotate(tab->a, tab->size_a);
			ft_putstr("rra\n");
		}
	}
}

static void	addition_b_to_a(t_st *tab)
{
	int		d;

	d = chose_direction_b(tab->b, tab->size_b);
	if (d < 0)
	{
		r_rotate(tab->b, tab->size_b);
		ft_putstr("rb\n");
	}
	else if (d > 0)
	{
		if (tab->size_b == 2)
		{
			f_swap_b(tab->b, tab->size_b);
			ft_putstr("sb\n");
		}
		else
		{
			rotate(tab->b, tab->size_b);
			ft_putstr("rrb\n");
		}
	}
}

static void	move_from_b_to_a(t_st *tab)
{
	if (tab->size_b && close_to_max(tab))
	{
		if (tab->a[0] < tab->b[tab->size_b - 1])
			in_case_of_broken_a(tab);
		else
			pa(tab);
	}
	while (tab->size_b && is_max(tab->b, tab->size_b, tab->b[tab->size_b - 1]))
	{
		if (tab->a[0] < tab->b[tab->size_b - 1])
			in_case_of_broken_a(tab);
		else
			pa(tab);
	}
	if (!is_sorted_min_max(tab->b, tab->size_b))
		addition_b_to_a(tab);
}

void		ps(t_st *tab)
{
	int		*sorted;
	int		middle;

	if (tab->size_a <= 3 && !is_sorted_min_max(tab->a, tab->size_a))
		in_case_of_three(tab);
	if (tab->size_a > 2 && !is_sorted_min_max(tab->a, tab->size_a))
	{
		sorted = sort_it(tab->a, tab->size_a);
		middle = find_middle_2(tab->size_a, sorted);
		while (smaller_then_middle(tab->a, tab->size_a, middle))
			move_from_a_to_b(tab, middle, sorted);
		free(sorted);
		ps(tab);
	}
	if (tab->size_b)
		move_from_b_to_a(tab);
	if (!is_sorted_min_max(tab->a, tab->size_a) || tab->size_b)
		ps(tab);
}
