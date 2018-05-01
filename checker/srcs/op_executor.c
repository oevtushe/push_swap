/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:48:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/01 14:01:10 by oevtushe         ###   ########.fr       */
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
	pfmt->spcs = 12 + ft_strlen(op_name) + 1;
	pfmt->stat = stat;
	init_bottom(pfmt->ba, "a", pfmt->bi_ln);
	init_bottom(pfmt->bb, "b", pfmt->bi_ln);
	ft_strcntllr(&pfmt->bb->separator, ft_strlen(pfmt->bb->separator) + pfmt->spcs, ' ', -1);
	ft_strcntllr(&pfmt->bb->name, ft_strlen(pfmt->bb->name) + pfmt->spcs, ' ', -1);
}

static void			print_extra(t_list *a_stack, t_pformat *pfmt,
						void print(t_list *, t_list *, t_opc *, t_pformat*), char *text)
{
	t_opc	*tmp;

	if (print)
	{
		tmp = new_opc(OP_NONE, text);
		init_format(pfmt, tmp->op_name, ES_NONE);
		print(a_stack, NULL, tmp, pfmt);
		free(tmp);
	}
}

void				op_executor(t_list **a_stack, t_list **b_stack,
		t_list *op_stack, void print(t_list *, t_list *, t_opc *, t_pformat*))
{
	t_excstat	stat;
	t_opc		*opc;
	t_pformat	*pfmt;
	t_opc		*dft;

	pfmt = new_pformat(*a_stack);
	dft = new_opc(OP_NONE, "finish");
	print_extra(*a_stack, pfmt, print, "init");
	while (op_stack)
	{
		opc = (t_opc *)op_stack->content;
		stat = op_execute(a_stack, b_stack, opc->abbr);
		init_format(pfmt, opc->op_name, stat);
		if (print)
			print(*a_stack, *b_stack, opc, pfmt);
		op_stack = op_stack->next;
	}
	if (print)
	{
		init_format(pfmt, dft->op_name, ES_NONE);
		print(*a_stack, *b_stack, dft, pfmt);
	}
	free(dft);
}
