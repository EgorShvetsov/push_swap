/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:25:33 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/11 19:25:35 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_st *tab)
{
	tab->a[-1] = tab->b[tab->size_b - 1];
	ft_putstr("pa\n");
	if (tab->a[-1] > tab->a[0])
		f_swap_a(tab->a);
	(tab->size_b)--;
	(tab->size_a)++;
	(tab->a)--;
}

void	pb(t_st *tab)
{
	tab->b[tab->size_b] = tab->a[0];
	ft_putstr("pb\n");
	(tab->size_b)++;
	(tab->size_a)--;
	(tab->a)++;
}
