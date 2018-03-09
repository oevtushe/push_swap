# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 08:03:18 by oevtushe          #+#    #+#              #
#    Updated: 2018/03/09 15:55:22 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_DIR			:= libft
NAME			:= checker
DEPS			:= checker.h
CKEYS			:= -Wall -Werror -Wextra

SRCS			:= checker.c \
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

OBJS_DIR		:= objs
OBJS			:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

include $(FT_DIR)/Libft.mk
include $(FT_DIR)/Gnl.mk

all: $(NAME)

$(NAME): $(FT_NAME) $(OBJS) $(DEPS)
	gcc $(CKEYS) -o $@ $(OBJS) $(FT_NAME) -I$(FT_DEPS_DIR)

$(OBJS): |$(OBJS_DIR)

$(FT_NAME): $(FT_SRCS) $(FT_DEPS) $(GNL_DEPS)
	@$(MAKE) GNL=on -C $(FT_DIR) 

$(OBJS_DIR)/%.o: %.c $(DEPS)
	gcc $(CKEYS) -o $@ -c $< -I$(FT_DEPS_DIR) -I$(FT_DIR)/$(GNL_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	@$(MAKE) clean -C $(FT_DIR)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) fclean -C $(FT_DIR)
	@rm -rf $(NAME)
