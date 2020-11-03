/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:20:26 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/26 14:20:29 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_max(int *tab, int size)
{
	int		i;
	int		max;

	i = 0;
	max = tab[i];
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int			find_min(int *tab, int size)
{
	int		i;
	int		min;

	i = 0;
	min = tab[i];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int			find_middle(int *a, int size)
{
	int		middle;
	int		max;
	int		min;

	max = find_max(a, size);
	min = find_min(a, size);
	middle = (max + min) / 2;
	return (middle);
}

int			*sort_it(int *tab, int size)
{
	int		*sorted;
	int		i;

	i = 0;
	sorted = malloc(sizeof(int) * size);
	while (i < size)
	{
		sorted[i] = tab[i];
		i++;
	}
	q_sort(sorted, size);
	return (sorted);
}

int			smaller_then_middle(int *tab, int size, int middle)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (tab[i] <= middle)
			return (1);
		i++;
	}
	return (0);
}
