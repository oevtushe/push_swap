/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:21:40 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/05 17:41:05 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

typedef	struct	s_median
{
	int median;
	int	push_cnt;
}				t_median;

typedef struct	s_pair
{
	int first;
	int second;
}				t_pair;

typedef enum	e_comb
{
	ABC = 1,
	ACB = 2,
	BAC = 3,
	BCA = -3,
	CAB = -2,
	CBA = -1
}				t_comb;

/*
** Algorithm
*/

int			arr_quickselect(int *arr, int p, int r, int i);
int			find_nmedian(t_list *lst, int size);
t_list		*find_all_nmedians(t_list *lst, int size);
void		split_nmedian_a(t_stacks *stacks, t_list *medians, int *group_cnt);
void		split_nmedian_b(t_stacks *stacks, int median, int group_cnt);
void		split_group_a(t_stacks *stacks, int *group_cnt);
void		split_group_b(t_stacks *stacks, int *group_cnt);
int			last_bigger_elem(t_list *lst, int grp, int n);
int			last_less_elem(t_list *lst, int grp, int n);
int			is_eq_combs(t_stacks *stacks);
t_list		*create_opt_op_lst(int **map, t_pair *map_size, t_list *ops_a, t_list *ops_b);

int			**gen_map(t_list *ops_a, t_list *ops_b, t_pair *map_size);
t_list		*gen_op_sort3(t_comb comb, int order);
void		sort3_new(t_stacks *stacks);
int			get_comb_a(t_list *lst);
int			get_comb_b(t_list *lst);
void		sort3optim_b(t_stacks *stacks);
void		sort3optim_both(t_stacks *stacks);
void		sort3optimized(t_stacks *stacks);
void		sort3both(t_stacks *stacks);
void		sort3(t_stacks *stacks);
void		sort2(t_stacks *stacks);

/*
** Tools
*/

int     	*lsttoari(t_list *lst);
void		rebase_lst_data(t_list *lst);
int     	*lstntoari(t_list *lst, int size);
void		ps_error(char *message);
void		op_execute_wrp(t_stacks *stacks, t_operation op);
void		op_execute_swap_opt(t_stacks *stacks, char stack);
t_list		*get_next_group(t_list *lst);
int			top_grp_len(t_list *lst);
int			st_group_is_sorted(t_list *lst);

#endif
