/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:03:45 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/14 20:03:46 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

static void	addition_to_make_pic(t_st *tab, char *line)
{
	tab->num_of_commands++;
	ft_strcpy(tab->command, line);
	print_stacks(tab);
	ft_bzero(tab->command, 4);
	usleep(DELAY);
}

static int	make_picture(t_st *tab)
{
	char	*line;
	int		res;

	system("clear");
	print_stacks(tab);
	usleep(DELAY);
	while ((res = get_next_line(0, &line)) > 0)
	{
		system("clear");
		if (!check_line(line, tab))
		{
			free(line);
			ft_putstr("\x1b[31;1mIncorrect instruction\x1b[0m\n");
			return (0);
		}
		addition_to_make_pic(tab, line);
		free(line);
	}
	if (!res)
		free(line);
	if (!is_sorted_min_max(tab->a, tab->size_a))
		ft_putstr("\x1b[31;1mStack A is not sorted!\x1b[0m\n");
	else
		ft_putstr("\x1b[32;1mStack A completely sorted\x1b[0m\n");
	return (0);
}

static void	make_an_array(t_st *tab, char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		tab->a[i++] = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
		if (*str == ' ')
			str++;
	}
}

static int	spaces_calc(char *str)
{
	int		spaces;

	spaces = 0;
	while (*str)
	{
		if (*str == ' ')
			spaces++;
		str++;
	}
	return (spaces);
}

int			main(int ac, char **av)
{
	t_st	tab;
	int		size;

	if (ac == 1)
		return (0);
	if (ac > 2)
	{
		ft_putstr("\x1b[31;1mToo many arguments\x1b[0m\n");
		return (0);
	}
	tab.size_a = spaces_calc(av[1]) + 1;
	tab.a = malloc(sizeof(int) * tab.size_a);
	tab.b = malloc(sizeof(int) * tab.size_a);
	tab.size_b = 0;
	make_an_array(&tab, av[1]);
	tab.start_a = tab.a;
	tab.start_b = tab.b;
	tab.num_of_commands = 0;
	ft_bzero(tab.command, 4);
	make_picture(&tab);
	free(tab.start_a);
	free(tab.start_b);
	return (0);
}
