# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Utils.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 11:40:42 by oevtushe          #+#    #+#              #
#    Updated: 2018/06/02 10:05:46 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Modules:	libft,
# 			gnl,
# 			ft_printf

UT_DIR		?= .

UT_SRCS_DIR	:= $(UT_DIR)/srcs
UT_DEPS_DIR	:= $(UT_DIR)/includes
UT_OBJS_DIR	:= $(UT_DIR)/objs

# Var for relative path. Simply run this make with
# RPTH=<relative path> to correct output directories.
RPTH		?= $(UT_DIR)

FT_DIR		?= $(UT_SRCS_DIR)/libft
GNL_DIR		?= $(UT_SRCS_DIR)/gnl
FTP_DIR		?= $(UT_SRCS_DIR)/ft_printf

include		$(FT_DIR)/Libft.mk
include		$(FTP_DIR)/Libftp.mk
include		$(GNL_DIR)/Gnl.mk

UT_SRCF		:= executors1.c \
				executors2.c \
				isvldarg.c \
				get_simple_args.c \
				free_str_arr.c \
				free_opc.c \
				op_execute.c \
				del_opc.c \
				del_stack.c \
				opc_convert.c \
				new_stacks.c \
				new_opc.c \
				read_args_stack.c \
				free_stacks.c \
				del_std_content.c \
				free_int_map.c \
				st_issorted.c
UT_DEPF		:= utils.h

UT_NAME		:= $(UT_DIR)/utils.a
UT_NW_SRCS	:= $(addprefix $(UT_SRCS_DIR)/,$(UT_SRCF))
UT_NW_OBJS	:= $(UT_NW_SRCS:$(UT_SRCS_DIR)/%.c=$(UT_OBJS_DIR)/%.o)
UT_SRCS		:= $(FT_SRCS) $(FTP_SRCS) $(GNL_SRCS) $(UT_NW_SRCS)
UT_OBJS		:= $(FT_OBJS) $(GNL_OBJS) $(FTP_OBJS) $(UT_NW_OBJS)
UT_DEPS		:= $(FT_DEPS) $(FTP_DEPS) $(GNL_DEPS) $(addprefix $(UT_DEPS_DIR)/,$(UT_DEPF))
