/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:42:10 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/07 15:42:12 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
