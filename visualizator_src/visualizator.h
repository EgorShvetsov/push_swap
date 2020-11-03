/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:03:54 by dorphan           #+#    #+#             */
/*   Updated: 2020/01/16 17:45:53 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATOR_H
# define VISUALIZATOR_H

# include "../libft/libft.h"

# define DELAY 90000

typedef struct			s_struct
{
	int					*a;
	int					*b;
	int					size_a;
	int					size_b;
	int					*start_a;
	int					*start_b;
	int					num_of_commands;
	char				command[4];
}						t_st;

int						check_line(char *line, t_st *tab);
void					f_swap_b(t_st *tab);
void					f_swap_a(t_st *tab);
void					r_rotate(int *tab, int size);
void					rotate(int *tab, int size);
void					print_stacks(t_st *tab);
int						is_sorted_min_max(int *a, int size);

#endif
