/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions_to_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:02:08 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/07 15:02:10 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			more_nulls_for_god_of_nulls(t_st *tab, int *b)
{
	tab->a = NULL;
	tab->b = NULL;
	tab->one_arg = NULL;
	tab->start_a = NULL;
	tab->start_b = NULL;
	tab->size_one_arg = 0;
	tab->size_a = 0;
	tab->size_b = 0;
	tab->colour = 0;
	tab->visualizator = 0;
	*b = 1;
}

int				zero_addition_to_main(t_st *tab)
{
	ft_putstr_fd("\x1b[31mError\n\x1b[0m", 2);
	if (tab->a)
		free(tab->a);
	return (0);
}

void			first_addition_to_main(t_st *tab)
{
	tab->b = malloc(sizeof(int) * tab->size_a);
	tab->start_a = tab->a;
	tab->start_b = tab->b;
}

int				second_addition_to_main(t_st *tab)
{
	ft_putstr_fd("\x1b[31mError\n\x1b[0m", 2);
	free(tab->start_a);
	free(tab->start_b);
	return (0);
}

void			final_addition_to_main(t_st *tab)
{
	if (!is_sorted_min_max(tab->a, tab->size_a) || tab->size_b != 0)
	{
		if (tab->colour)
			ft_putstr("\x1b[31;1m");
		ft_putstr("KO\n");
	}
	else
	{
		if (tab->colour)
			ft_putstr("\x1b[32;1m");
		ft_putstr("OK\n");
	}
	if (tab->colour)
		ft_putstr("\x1b[0m");
	free(tab->start_a);
	free(tab->start_b);
}
