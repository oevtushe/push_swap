# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Checker.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 13:27:07 by oevtushe          #+#    #+#              #
#    Updated: 2018/06/08 10:10:59 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CH_NAME			:= ../checker

CH_DIR			?= .
CH_DEPS_DIR		:= $(CH_DIR)/includes
CH_SRCS_DIR		:= $(CH_DIR)/srcs
CH_OBJS_DIR		:= $(CH_DIR)/objs

# Var for relative path. Simply run this make with
# RPTH=<relative path> to correct output directories.
RPTH			?= $(CH_DIR)

UT_DIR			?= ../utils

include			$(UT_DIR)/Utils.mk
include			$(FT_DIR)/Pretty.mk

CH_DEPF			:= checker.h
CH_SRCF			:= checker.c		\
				isvldops.c			\
				print_row.c			\
				op_executor.c		\
				new_pformat.c		\
				init_format.c		\
				op_read_and_exec.c	\
				verdict.c			\
				pfmt_utils.c		\
				init_odata.c		\
				stat.c				\
				read_operations.c	\
				str_join_number.c	\
				pretty_error.c		\
				print_info.c

CH_SRCS			:= $(addprefix $(CH_SRCS_DIR)/,$(CH_SRCF))
CH_DEPS			:= $(addprefix $(CH_DEPS_DIR)/,$(CH_DEPF))
CH_OBJS			:= $(CH_SRCS:$(CH_SRCS_DIR)/%.c=$(CH_OBJS_DIR)/%.o)
