/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:21:40 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/19 13:42:45 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

typedef struct		s_stack
{
	char	name;
	t_list	*lst;
}					t_stack;

/*
** Algorithm
*/

void	    lst_safe_swap(t_stack **stack, int i, int j);
int			arr_quickselect(int *arr, int p, int r, int i);
int			find_nmedian(t_list *lst, int size);
void		split_nmedian(t_stack **stack1, t_stack **stack2, int size, int ngrp);
void		init_push(t_stack **stack, t_opc *op);
void		push_exec_pr(t_stack **st1, t_stack **st2, t_opc opc);

void		sort3(t_stack **stack);
void		sort2(t_stack **stack);
void		rsort3(t_stack **stack);
void		rsort2(t_stack **stack);
void    	sort321(t_list **a, t_list **b, int which);
void    	sort312(t_list **a, t_list **b, int which);
void    	sort213(t_list **a, t_list **b, int which);
void    	sort231(t_list **a, t_list **b, int which);
void    	sort132(t_list **a, t_list **b, int which);

/*
** Tools
*/

t_stack     *new_stack(t_list *lst, char name);
int     	*lsttoari(t_list *lst);
void		rebase_lst_data(t_list *lst);
int     	*lstntoari(t_list *lst, int size);
void		ps_error(char *message);
void		op_execute_wrp(t_list **a, t_list **b, t_operation op);

#endif
