# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 08:03:18 by oevtushe          #+#    #+#              #
#    Updated: 2018/05/03 14:25:15 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEPS_DIR		:= includes
SRCS_DIR		:= srcs
OBJS_DIR		:= objs

UT_DIR			:= ../utils

include			$(UT_DIR)/Utils.mk
include			$(FT_DIR)/Pretty.mk

NAME			:= checker

DEPF			:= checker.h
SRCF			:= checker.c \
				isvldops.c \
				print_row.c \
				new_opc.c \
				op_executor.c \
				new_pformat.c \
				init_format.c \
				op_read_and_exec.c \
				verdict.c \
				init_odata.c \
				stat.c \
				read_operations.c \
				str_join_number.c \
				print_info.c \
				rebase_op_stack.c \
				checker_error.c

SRCS			:= $(addprefix $(SRCS_DIR)/,$(SRCF))
DEPS			:= $(addprefix $(DEPS_DIR)/,$(DEPF))
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

# Utils
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
