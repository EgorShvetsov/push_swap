/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:52:37 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/07 15:52:40 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		final_addition(char *line, t_st *tab)
{
	if (!ft_strcmp(line, "pa"))
	{
		if (tab->size_b)
		{
			(tab->a)--;
			(tab->size_a)++;
			tab->a[0] = tab->b[tab->size_b - 1];
			(tab->size_b)--;
		}
	}
	else
		return (0);
	return (1);
}

static int		rotates_down(char *line, t_st *tab)
{
	if (!ft_strcmp(line, "rra"))
	{
		if (tab->size_a > 1)
			r_rotate(tab->a, tab->size_a);
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		if (tab->size_b > 1)
			rotate(tab->b, tab->size_b);
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		if (tab->size_b > 1)
			rotate(tab->b, tab->size_b);
		if (tab->size_a > 1)
			r_rotate(tab->a, tab->size_a);
	}
	else if (!final_addition(line, tab))
		return (0);
	return (1);
}

static int		rotates_up(char *line, t_st *tab)
{
	if (!ft_strcmp(line, "ra"))
	{
		if (tab->size_a > 1)
			rotate(tab->a, tab->size_a);
	}
	else if (!ft_strcmp(line, "rb"))
	{
		if (tab->size_b > 1)
			r_rotate(tab->b, tab->size_b);
	}
	else if (!ft_strcmp(line, "rr"))
	{
		if (tab->size_a > 1)
			rotate(tab->a, tab->size_a);
		if (tab->size_b > 1)
			r_rotate(tab->b, tab->size_b);
	}
	else if (!rotates_down(line, tab))
		return (0);
	return (1);
}

static int		swaps(char *line, t_st *tab)
{
	if (!ft_strcmp(line, "sb"))
	{
		if (tab->size_b > 1)
			f_swap_b(tab);
	}
	else if (!ft_strcmp(line, "ss"))
	{
		if (tab->size_b > 1)
			f_swap_b(tab);
		if (tab->size_a > 1)
			f_swap_a(tab);
	}
	else if (!ft_strcmp(line, "sa"))
	{
		if (tab->size_a > 1)
			f_swap_a(tab);
	}
	else if (!rotates_up(line, tab))
		return (0);
	return (1);
}

int				check_line(char *line, t_st *tab)
{
	if (tab->visualizator)
	{
		ft_putstr("Command used:   ");
		if (tab->colour)
			ft_putstr("\x1b[35;1m");
		ft_putstr(line);
		if (tab->colour)
			ft_putstr("\x1b[0m");
		ft_putchar('\n');
	}
	if (!ft_strcmp(line, "pb"))
	{
		if (tab->size_a)
		{
			tab->b[tab->size_b] = tab->a[0];
			(tab->size_b)++;
			(tab->size_a)--;
			(tab->a)++;
		}
	}
	else if (!swaps(line, tab))
		return (0);
	return (1);
}
