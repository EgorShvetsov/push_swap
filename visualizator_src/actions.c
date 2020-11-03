/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:03:21 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/14 20:03:24 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

int			is_sorted_min_max(int *a, int size)
{
	int		i;

	i = 1;
	while (i < size)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void		f_swap_b(t_st *tab)
{
	int		swap;

	if (tab->size_b > 1)
	{
		swap = tab->b[tab->size_b - 1];
		tab->b[tab->size_b - 1] = tab->b[tab->size_b - 2];
		tab->b[tab->size_b - 2] = swap;
	}
}

void		f_swap_a(t_st *tab)
{
	int		swap;

	if (tab->size_a > 1)
	{
		swap = tab->a[0];
		tab->a[0] = tab->a[1];
		tab->a[1] = swap;
	}
}

void		r_rotate(int *tab, int size)
{
	int		i;
	int		swap;

	if (size > 1)
	{
		i = size - 1;
		swap = tab[i];
		while (i > 0)
		{
			tab[i] = tab[i - 1];
			i--;
		}
		tab[i] = swap;
	}
}

void		rotate(int *tab, int size)
{
	int		i;
	int		swap;

	i = 0;
	swap = tab[i];
	if (size > 1)
	{
		while (i != size - 1)
		{
			tab[i] = tab[i + 1];
			i++;
		}
		tab[i] = swap;
	}
}
