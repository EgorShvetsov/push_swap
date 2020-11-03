/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:34:02 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/30 17:34:06 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct			s_struct
{
	int					*a;
	int					*b;
	int					*start_a;
	int					*start_b;
	int					*one_arg;
	int					size_one_arg;
	int					size_a;
	int					size_b;
	int					colour;
	int					visualizator;
	char				command[100];
}						t_st;

void					more_nulls_for_god_of_nulls(t_st *tab, int *b);
void					final_addition_to_main(t_st *tab);
int						is_sorted_min_max(int *a, int size);
void					first_addition_to_main(t_st *tab);
int						second_addition_to_main(t_st *tab);
int						zero_addition_to_main(t_st *tab);
void					f_swap_b(t_st *tab);
void					f_swap_a(t_st *tab);
void					r_rotate(int *tab, int size);
void					rotate(int *tab, int size);
int						wwa(char *str, t_st *tab);
int						check_line(char *line, t_st *tab);
void					concat_arrays(t_st *tab);

#endif
