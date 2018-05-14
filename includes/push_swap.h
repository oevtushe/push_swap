/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:21:40 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 11:26:10 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

/*
** Algorithm
*/

int			arr_quickselect(int *arr, int p, int r, int i);
int			find_nmedian(t_list *lst, int size);
void		split_nmedian_a(t_list **lst1, t_list **lst2, int median, int group_cnt);
void		split_nmedian_b(t_list **lst1, t_list **lst2, int median, int group_cnt);
void		split_group_a(t_list **lst1, t_list **lst2, int *group_cnt);
void		split_group_b(t_list **lst1, t_list **lst2, int *group_cnt);
int			last_bigger_elem(t_list *lst, int grp, int n);
int			last_less_elem(t_list *lst, int grp, int n);

void		sort3optim_b(t_list **lst1, t_list **lst2);
void		sort3optimized(t_list **lst1, t_list **lst2);
void		sort3(t_list **lst1, t_list **lst2);
void		sort2(t_list **lst1, t_list **lst2);

/*
** Tools
*/

int     	*lsttoari(t_list *lst);
void		rebase_lst_data(t_list *lst);
int     	*lstntoari(t_list *lst, int size);
void		ps_error(char *message);
void		op_execute_wrp(t_list **a, t_list **b, t_operation op);
void		op_execute_swap_opt(t_list **a, t_list **b, char stack);
t_list		*get_next_group(t_list *lst);
int			top_grp_len(t_list *lst);

#endif
