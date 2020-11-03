/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorphan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 13:28:35 by dorphan           #+#    #+#             */
/*   Updated: 2019/12/26 13:28:37 by dorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int					mid_b;
}						t_st;

int						wwa(char *str, t_st *tab);
void					ps(t_st *tab);
void					in_case_of_three(t_st *tab);
int						find_middle_2(int size, int *sorted);
int						q_sort(int *a, int size);
int						find_max(int *tab, int size);
int						find_min(int *tab, int size);
int						find_middle(int *a, int size);
void					rotate(int *tab, int size);
void					r_rotate(int *tab, int size);
void					f_swap_b(int *tab, int size);
void					f_swap_a(int *tab);
void					pa(t_st *tab);
void					pb(t_st *tab);
int						chose_direction_a(int *tab, int size, int middle);
int						is_sorted_min_max(int *a, int size);
int						chose_direction_b(int *b, int size_b);
int						is_max(int *tab, int size, int num);
int						*sort_it(int *tab, int size);
int						smaller_then_middle(int *tab, int size, int middle);
void					in_case_of_broken_a(t_st *tab);
int						close_to_max(t_st *tab);
void					f_swap_ss(t_st *tab);
int						mid_b(int *sorted, int middle);
void					in_case_of_five(t_st *tab);

#endif
