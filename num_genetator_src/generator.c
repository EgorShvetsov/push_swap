/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:04:07 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/16 17:17:02 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../libft/libft.h"

int g_max = 100;

static int	find_doubling(int *tab, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (tab[i++] == tab[index])
			return (1);
	}
	return (0);
}

static void	print_tab(int *tab, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		ft_putnbr(tab[i++]);
		if (i < num)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

static int	generator(int num)
{
	int		random;
	int		*tab;
	int		i;

	i = 0;
	srand(time(NULL));
	if (num <= 0 || num > g_max)
		return (0);
	tab = malloc(sizeof(int) * num);
	while (i < num)
	{
		random = rand() % g_max;
		tab[i] = random;
		if (!find_doubling(tab, i))
			i++;
	}
	print_tab(tab, num);
	return (1);
}

int			main(int ac, char **av)
{
	if (ac == 1)
		ft_putstr("Too few arguments\n");
	else if (ac == 2)
	{
		if (!generator(ft_atoi(av[1])))
			ft_putstr("Bad argument\n");
	}
	else
		ft_putstr("Too many arguments\n");
	return (0);
}
