/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:15:30 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/14 20:15:36 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

static void		print_stack_a(t_st *tab)
{
	int			i;
	int			line;

	i = 0;
	while (i < tab->size_a)
	{
		line = 0;
		while (line < tab->a[i])
		{
			ft_putchar(' ');
			line++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr("\x1b[0m\n\n");
}

static void		print_stack_b(t_st *tab)
{
	int			i;
	int			line;

	i = tab->size_b - 1;
	while (i >= 0)
	{
		line = 0;
		while (line < tab->b[i])
		{
			ft_putchar(' ');
			line++;
		}
		ft_putchar('\n');
		i--;
	}
	ft_putstr("\x1b[0m");
}

void			print_stacks(t_st *tab)
{
	ft_putstr("Last instruction is: ");
	ft_putstr(tab->command);
	ft_putchar('\n');
	ft_putstr("The current number of instructions is: ");
	ft_putnbr(tab->num_of_commands);
	ft_putchar('\n');
	ft_putstr("Stack A is:\n\n");
	ft_putstr("\x1b[42m");
	print_stack_a(tab);
	ft_putstr("Stack B is:\n\n");
	ft_putstr("\x1b[44m");
	print_stack_b(tab);
}
