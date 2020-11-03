/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 22:03:40 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/09 22:03:42 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				mid_b(int *sorted, int middle)
{
	int			mid_b;
	int			i;

	i = 0;
	while (sorted[i] != middle)
		i++;
	if (i % 2 == 0)
		mid_b = sorted[(i / 2) - 1];
	else
		mid_b = sorted[i / 2];
	return (mid_b);
}

static void		addition(int size, int *sorted, int *middle)
{
	if (size <= 215)
	{
		if (size % 3 == 0)
			*middle = sorted[(size / 3) - 1];
		else
			*middle = sorted[size / 3];
	}
	else
	{
		if (size % 5 == 0)
			*middle = sorted[(size / 5) - 1];
		else
			*middle = sorted[size / 5];
	}
}

int				find_middle_2(int size, int *sorted)
{
	int			middle;

	if (size <= 142)
	{
		if (size % 2 == 0)
			middle = sorted[(size / 2) - 1];
		else
			middle = sorted[size / 2];
	}
	else
		addition(size, sorted, &middle);
	return (middle);
}
