/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:47:32 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/07 15:47:34 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		check_arg(char *str)
{
	if (*str == '-' && ft_strlen(str) == 1)
		return (0);
	if (*str == '-')
		str++;
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) == 10 &&
		((ft_strcmp(str, "2147483647") > 0 && *(str - 1) != '-') ||
			(ft_strcmp(str, "2147483648") > 0 && *(str - 1) == '-')))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int		first_addition(t_st *tab, char **tmp, char **str, int *i)
{
	if (**tmp == ' ')
	{
		**tmp = '\0';
		if (!check_arg(*str))
		{
			free(tab->one_arg);
			return (0);
		}
		tab->one_arg[(*i)++] = ft_atoi(*str);
		*str = *tmp + 1;
	}
	return (1);
}

static int		second_addition(t_st *tab, char **tmp, char **str, int *i)
{
	if (!**tmp)
	{
		if (!check_arg(*str))
		{
			free(tab->one_arg);
			return (0);
		}
		tab->one_arg[(*i)++] = ft_atoi(*str);
	}
	return (1);
}

static void		third_addition(t_st *tab, char **tmp, char **str, int i)
{
	tab->one_arg = malloc(sizeof(int) * i);
	tab->size_one_arg = i;
	*tmp = *str;
}

int				wwa(char *str, t_st *tab)
{
	char		*tmp;
	int			arg_calc;
	int			i;

	tmp = str;
	arg_calc = 1;
	i = 0;
	while (*tmp)
	{
		if (*tmp == ' ' && !ft_isdigit(*(tmp + 1)) && *(tmp + 1) != '-')
			return (0);
		else if (*tmp == ' ')
			arg_calc++;
		tmp++;
	}
	third_addition(tab, &tmp, &str, arg_calc);
	while (*tmp)
	{
		if (!first_addition(tab, &tmp, &str, &i))
			return (0);
		tmp++;
		if (!second_addition(tab, &tmp, &str, &i))
			return (0);
	}
	return (1);
}
