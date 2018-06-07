# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Push_Swap.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 14:12:46 by oevtushe          #+#    #+#              #
#    Updated: 2018/06/07 14:41:09 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_DEPS_DIR		:= includes
PS_SRCS_DIR		:= srcs
PS_OBJS_DIR		:= objs

UT_DIR			:= utils
CH_DIR			:= checker_dir

include			$(CH_DIR)/Checker.mk

PS_NAME			:= push_swap

PS_DEPF			:= push_swap.h
PS_SRCF			:=  arr_quickselect.c		\
					comparators.c			\
					top_grp_len.c			\
					sort3optim_b.c			\
					sort3optimized.c		\
					optimized_ops.c			\
					st_group_is_sorted.c	\
					create_opt_op_lst.c		\
					lsttoari.c				\
					gen_map.c				\
					last_significant_elem.c	\
					sort3_new.c				\
					sort3.c					\
					sort3both.c				\
					gen_op_sort3.c			\
					get_next_group.c		\
					sort2.c					\
					is_eq_combs.c			\
					lstntoari.c				\
					find_all_nmedians.c		\
					split_group.c			\
					split_nmedian.c			\
					op_execute_wrp.c		\
					push_swap.c				\
					sort3_new_utils.c		\
					find_nmedian.c

PS_DEPS			:= $(addprefix $(PS_DEPS_DIR)/,$(PS_DEPF))
PS_SRCS			:= $(addprefix $(PS_SRCS_DIR)/,$(PS_SRCF))
PS_OBJS			:= $(PS_SRCS:$(PS_SRCS_DIR)/%.c=$(PS_OBJS_DIR)/%.o)
