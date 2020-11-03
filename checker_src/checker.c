/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:32:38 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/30 17:32:42 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		find_doubles(int *tab, int i)
{
	int			start;

	start = 0;
	while (start < i)
	{
		if (tab[start] == tab[i])
		{
			ft_putstr_fd("\x1b[31mError\n\x1b[0m", 2);
			free(tab);
			return (1);
		}
		start++;
	}
	return (0);
}

void			print_stacks(t_st *tab)
{
	int aa;

	aa = 0;
	if (tab->colour)
		ft_putstr("\x1b[94m");
	ft_putstr(("Stack a is: "));
	while (aa < tab->size_a)
	{
		ft_putnbr(tab->a[aa++]);
		ft_putstr("   ");
	}
	if (tab->colour)
		ft_putstr("\x1b[0m\x1b[93m");
	aa = 0;
	ft_putchar('\n');
	ft_putstr(("Stack b is: "));
	while (aa < tab->size_b)
	{
		ft_putnbr(tab->b[aa++]);
		ft_putstr("   ");
	}
	ft_putstr("\n\n");
	if (tab->colour)
		ft_putstr("\x1b[0m");
}

int				read_args(t_st *tab)
{
	int			i;
	char		sim[1];
	int			res;

	i = 0;
	while ((res = read(0, sim, 1)))
	{
		if (*sim == '\n')
		{
			tab->command[i] = '\0';
			i = 0;
			if (!check_line(tab->command, tab))
				return (0);
			if (tab->visualizator)
				print_stacks(tab);
		}
		else
			tab->command[i++] = *sim;
	}
	if (res == 0 && i != 0)
	{
		ft_putchar('\n');
		return (0);
	}
	return (1);
}

void			add_flag(t_st *tab, char *arg)
{
	if (!ft_strcmp(arg, "-vc") || !ft_strcmp(arg, "-cv"))
	{
		tab->colour = 1;
		tab->visualizator = 1;
	}
	else if (!ft_strcmp(arg, "-v"))
		tab->visualizator = 1;
	else if (!ft_strcmp(arg, "-c"))
		tab->colour = 1;
}

int				main(int ac, char **av)
{
	int			b;
	t_st		tab;

	more_nulls_for_god_of_nulls(&tab, &b);
	if (ac == 1)
		return (0);
	if (!ft_strcmp(av[b], "-vc") || !ft_strcmp(av[b], "-v") ||
				!ft_strcmp(av[b], "-c") || !ft_strcmp(av[b], "-cv"))
		add_flag(&tab, av[b++]);
	if (ac == 2 && (tab.visualizator || tab.colour))
		return (0);
	while (b < ac)
	{
		if ((!ft_isdigit(av[b][0]) && av[b][0] != '-') || !wwa(av[b], &tab))
			return (zero_addition_to_main(&tab));
		concat_arrays(&tab);
		if (find_doubles(tab.a, tab.size_a - 1))
			return (0);
		b++;
	}
	first_addition_to_main(&tab);
	if (!read_args(&tab))
		return (second_addition_to_main(&tab));
	final_addition_to_main(&tab);
	return (0);
}
