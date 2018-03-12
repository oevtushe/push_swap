# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 08:03:18 by oevtushe          #+#    #+#              #
#    Updated: 2018/03/12 13:28:53 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEPS_DIR		:= includes
SRCS_DIR		:= srcs
OBJS_DIR		:= objs

FTM_DIR			:= ../srcs/libftmulti
FT_DIR			:= ../srcs/libftmulti/libft
GNL_DIR			:= ../srcs/libftmulti/gnl
FTP_DIR			:= ../srcs/libftmulti/ft_printf

include $(FT_DIR)/Pretty.mk
include	$(FTM_DIR)/Libftmulti.mk

NAME			:= checker

DEPF			:= checker.h
SRCF			:= checker.c \
				checker_readers.c \
				isvldarg.c \
				isvldops.c \
				other_executors.c \
				op_executor.c \
				stack_rotators.c \
				st_issorted.c \
				rebase_op_stack.c \
				checker_error.c \
				ft_isnumber.c 

SRCS			:= $(addprefix $(SRCS_DIR)/,$(SRCF))
DEPS			:= $(addprefix $(DEPS_DIR)/,$(DEPF))
OBJS			:= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC				:= gcc
RM				:= rm -rf
CFLAGS			:= -Wall -Werror -Wextra
MFLAGS			:= --no-print-directory -C
IFLAGS			:= -I$(DEPS_DIR) -I$(FT_DEPS_DIR) -I$(FTP_DEPS_DIR) -I$(GNL_DIR)

all: $(FTM_NAME) $(NAME)

$(NAME): $(OBJS)
	@$(call EXEC_P,$@)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(FTM_NAME) $(IFLAGS)

$(FTM_NAME): $(FTM_SRCS) $(FTM_DEPS)
	@$(MAKE) $(MFLAGS) $(FTM_DIR)

$(OBJS): |$(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(DEPS) $(FTP_DEPS)
	@$(call COMPILE_P,$@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(OBJS_DIR):
	@$(call DIR_CREATE_P,$(OBJS_DIR))
	@mkdir $(OBJS_DIR)

clean:
	@$(MAKE) clean $(MFLAGS) $(FTM_DIR)
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(MAKE) fclean $(MFLAGS) $(FTM_DIR)
	@$(RM) $(NAME)
re: fclean
	@$(MAKE)
