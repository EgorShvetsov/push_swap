/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:06:46 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/07 16:06:49 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			concat_arrays(t_st *tab)
{
	int			*tmp;
	int			final;
	int			current;

	final = 0;
	current = 0;
	tmp = malloc(sizeof(int) * (tab->size_a + tab->size_one_arg));
	while (current < tab->size_a && tab->a)
		tmp[final++] = tab->a[current++];
	current = 0;
	while (current < tab->size_one_arg)
		tmp[final++] = tab->one_arg[current++];
	if (tab->a)
		free(tab->a);
	free(tab->one_arg);
	tab->a = tmp;
	tab->size_a = final;
	tab->size_one_arg = 0;
}
