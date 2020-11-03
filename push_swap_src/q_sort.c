/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:44:54 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/26 17:44:56 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted_min_max(int *a, int size)
{
	int		i;

	i = 1;
	while (i < size)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

static int	sorting_by_middle(int *a, int size, int middle)
{
	int		head;
	int		tail;
	int		swap;

	head = 0;
	tail = size - 1;
	while (head < tail)
	{
		if (a[head] <= middle)
			head++;
		if (a[tail] > middle)
			tail--;
		if (a[head] > middle && a[tail] <= middle)
		{
			swap = a[head];
			a[head] = a[tail];
			a[tail] = swap;
		}
		if (tail == head + 1 && a[tail] > middle)
			break ;
	}
	if (a[head] > middle)
		return (head);
	return (head + 1);
}

int			q_sort(int *a, int size)
{
	int		middle;
	int		swap;

	if (size == 2)
	{
		if (a[0] > a[1])
		{
			swap = a[0];
			a[0] = a[1];
			a[1] = swap;
		}
	}
	if (is_sorted_min_max(a, size))
		return (0);
	middle = find_middle(a, size);
	middle = sorting_by_middle(a, size, middle);
	if (!is_sorted_min_max(a, size))
	{
		q_sort(a, middle);
		q_sort(&a[middle], size - middle);
	}
	return (1);
}
