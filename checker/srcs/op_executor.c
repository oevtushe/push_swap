/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:48:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/01 10:56:14 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			init_bottom(t_bottom *bottom, char *st_name, int bi_ln)
{
	int		b_spaces;

	b_spaces = (bi_ln - ft_strlen(st_name)) / 2 + 1;
	bottom->name = ft_strdup(st_name);
	ft_strcntllr(&bottom->name, ft_strlen(bottom->name) + b_spaces, ' ', -1);
	ft_strcntllr(&bottom->name, ft_strlen(bottom->name) + b_spaces, ' ', 1);
	bottom->separator = ft_strnew(bi_ln + 2);
	ft_memset(bottom->separator, '_', bi_ln + 2);
	bottom->separator[0] = '|';
	bottom->separator[bi_ln + 1] = '|';
	bottom->is_sp_printed = 0;
	bottom->is_nm_printed = 0;
}

static void			init_format(t_pformat *pfmt, char *op_name, t_excstat stat)
{
	pfmt->spcs = 15 + (ft_strlen(op_name) == 3 ? 1 : 0);
	pfmt->stat = stat;
	init_bottom(pfmt->ba, "a", pfmt->bi_ln);
	init_bottom(pfmt->bb, "b", pfmt->bi_ln);
	ft_strcntllr(&pfmt->bb->separator, ft_strlen(pfmt->bb->separator) + pfmt->spcs, ' ', -1);
	ft_strcntllr(&pfmt->bb->name, ft_strlen(pfmt->bb->name) + pfmt->spcs, ' ', -1);
}

static int		stack_max_int_len(t_list *a)
{
	int		max;

	max = *(int*)a->content;
	while (a)
	{
		if (*(int*)a->content > max)
			max = *(int*)a->content;
		a = a->next;
	}
	return (ft_intln(max));
}

void				op_executor(t_list **a_stack, t_list **b_stack,
		t_list *op_stack, void print(t_list *, t_list *, t_opc *, t_pformat*))
{
	t_excstat	stat;
	t_opc		*opc;
	t_pformat	*pfmt;

	pfmt = (t_pformat*)ft_memalloc(sizeof(t_pformat));
	pfmt->ba = (t_bottom*)ft_memalloc(sizeof(t_bottom));
	pfmt->bb = (t_bottom*)ft_memalloc(sizeof(t_bottom));
	pfmt->color = RED;
	pfmt->bi_ln = stack_max_int_len(*a_stack);
	if (!(pfmt->bi_ln % 2))
		++pfmt->bi_ln;
	while (op_stack)
	{
		opc = (t_opc *)op_stack->content;
		stat = op_execute(a_stack, b_stack, opc->abbr);
		init_format(pfmt, opc->op_name, stat);
		if (print)
			print(*a_stack, *b_stack, opc, pfmt);
		op_stack = op_stack->next;
	}
}
