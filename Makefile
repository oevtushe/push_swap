# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 16:23:33 by oevtushe          #+#    #+#              #
#    Updated: 2018/04/23 13:29:46 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEPS_DIR		:= includes
SRCS_DIR		:= srcs
OBJS_DIR		:= objs

UT_DIR			:= utils

include			$(UT_DIR)/Utils.mk
include 		$(FT_DIR)/Pretty.mk

NAME			:= push_swap

DEPF			:= push_swap.h
SRCF			:=  arr_quickselect.c \
					new_stack.c \
					push_exec_pr.c \
					init_push.c \
					comparators.c \
					top_grp_len.c \
					lst_safe_swap.c \
					lsttoari.c \
					lstntoari.c \
					little_sort.c \
					rebase_lst_data.c \
					sort3_fncs.c \
					split_nmedian.c \
					op_execute_wrp.c \
					ps_error.c \
					push_swap.c \
					find_nmedian.c

DEPS			:= $(addprefix $(DEPS_DIR)/,$(DEPF))
SRCS			:= $(addprefix $(SRCS_DIR)/,$(SRCF))
OBJS			:= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC				:= gcc
RM				:= rm -rf
CFLAGS			:= -Wall -Werror -Wextra
MFLAGS			:= --no-print-directory -C
IFLAGS			:= -I$(DEPS_DIR) -I$(FT_DEPS_DIR) -I$(FTP_DEPS_DIR) -I$(GNL_DIR) -I$(UT_DEPS_DIR)

all: $(NAME)

$(NAME): $(UT_NAME) $(OBJS)
	@$(call EXEC_P,$@)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(UT_NAME) $(IFLAGS)

$(UT_NAME): $(UT_SRCS) $(UT_DEPS)
	@$(MAKE) RPTH=$(UT_DIR) $(MFLAGS) $(UT_DIR)

$(OBJS): |$(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(DEPS) $(UT_DEPS)
	@$(call COMPILE_P,$@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(OBJS_DIR):
	@$(call DIR_CREATE_P,$(OBJS_DIR))
	@mkdir $(OBJS_DIR)

clean:
	@$(MAKE) clean $(MFLAGS) $(UT_DIR)
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(MAKE) fclean $(MFLAGS) $(UT_DIR)
	@$(RM) $(NAME)
re: fclean
	@$(MAKE)
