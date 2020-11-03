/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:13:29 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/27 16:13:31 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		f_swap_ss(t_st *tab)
{
	f_swap_b(tab->b, tab->size_b);
	f_swap_a(tab->a);
	ft_putstr("ss\n");
}

void		f_swap_b(int *tab, int size)
{
	int		swap;

	swap = tab[size - 1];
	tab[size - 1] = tab[size - 2];
	tab[size - 2] = swap;
}

void		f_swap_a(int *tab)
{
	int		swap;

	swap = tab[0];
	tab[0] = tab[1];
	tab[1] = swap;
}

void		r_rotate(int *tab, int size)
{
	int		i;
	int		swap;

	i = size - 1;
	swap = tab[i];
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[i] = swap;
}

void		rotate(int *tab, int size)
{
	int		i;
	int		swap;

	i = 0;
	swap = tab[i];
	while (i != size - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = swap;
}
