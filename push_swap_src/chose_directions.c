/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:17:23 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/11 19:17:26 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(int *tab, int size)
{
	int		i;
	int		max;
	int		pos;

	i = 0;
	max = tab[i];
	pos = i;
	while (i < size)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int			chose_direction_a(int *tab, int size, int middle)
{
	int		head;
	int		tail;

	head = 0;
	tail = size - 1;
	while (head <= tail)
	{
		if (tab[head] <= middle)
			return (1);
		if (tab[tail] <= middle)
			return (-1);
		head++;
		tail--;
	}
	return (0);
}

int			chose_direction_b(int *b, int size_b)
{
	int		i;

	i = find_max_pos(b, size_b);
	if (i == size_b - 1)
		return (0);
	if (size_b % 2 == 0)
	{
		if (i < size_b / 2)
			return (1);
		return (-1);
	}
	else
	{
		if (i <= size_b / 2)
			return (1);
		return (-1);
	}
}
