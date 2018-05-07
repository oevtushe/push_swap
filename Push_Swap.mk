# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Push_Swap.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 14:12:46 by oevtushe          #+#    #+#              #
#    Updated: 2018/05/07 15:31:36 by oevtushe         ###   ########.fr        #
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
PS_SRCF			:=  arr_quickselect.c \
					new_stack.c \
					push_exec_pr.c \
					dprint_stacks.c \
					init_push.c \
					comparators.c \
					top_grp_len.c \
					sort3optimized.c \
					op_execute_swap_opt.c \
					lst_safe_swap.c \
					lsttoari.c \
					last_significant_elem.c \
					get_next_group.c \
					sort3.c \
					sort2.c \
					lstntoari.c \
					rebase_lst_data.c \
					split_group.c \
					split_nmedian.c \
					op_execute_wrp.c \
					ps_error.c \
					push_swap.c \
					find_nmedian.c

PS_DEPS			:= $(addprefix $(PS_DEPS_DIR)/,$(PS_DEPF))
PS_SRCS			:= $(addprefix $(PS_SRCS_DIR)/,$(PS_SRCF))
PS_OBJS			:= $(PS_SRCS:$(PS_SRCS_DIR)/%.c=$(PS_OBJS_DIR)/%.o)
