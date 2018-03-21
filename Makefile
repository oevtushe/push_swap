# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 16:23:33 by oevtushe          #+#    #+#              #
#    Updated: 2018/03/14 17:11:05 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEPS_DIR		:= includes
SRCS_DIR		:= srcs
OBJS_DIR		:= objs

FTM_DIR			:= $(SRCS_DIR)/libftmulti
FT_DIR			:= $(FTM_DIR)/libft
GNL_DIR			:= $(FTM_DIR)/gnl
FTP_DIR			:= $(FTM_DIR)/ft_printf

include	$(FTM_DIR)/Libftmulti.mk
include $(FT_DIR)/Pretty.mk

NAME			:= push_swap

DEPS			:= push_swap.h
SRCF			:= isvldarg.c \
					ps_error.c \
					read_args_stack.c \
					push_swap.c

DEPS			:= $(addprefix $(DEPS_DIR)/,$(DEPF))
SRCS			:= $(addprefix $(SRCS_DIR)/,$(SRCF))
OBJS			:= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC				:= gcc
RM				:= rm -rf
CFLAGS			:= -Wall -Werror -Wextra
MFLAGS			:= --no-print-directory -C
IFLAGS			:= -I$(DEPS_DIR) -I$(FT_DEPS_DIR) -I$(FTP_DEPS_DIR) -I$(GNL_DIR)

all: $(NAME)

$(NAME): $(FTM_NAME) $(OBJS)
	@$(call EXEC_P,$@)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(FTM_NAME) $(IFLAGS)

$(FTM_NAME): $(FTM_SRCS) $(FTM_DEPS)
	@$(MAKE) RPTH=$(FTM_DIR) $(MFLAGS) $(FTM_DIR)

$(OBJS): |$(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(DEPS) $(FTM_DEPS)
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
