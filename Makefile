# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 16:23:33 by oevtushe          #+#    #+#              #
#    Updated: 2018/05/07 14:57:53 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include			Push_Swap.mk

CH_NAME			:= checker_e

CC				:= gcc
RM				:= rm -rf
CFLAGS			:= -Wall -Werror -Wextra
MFLAGS			:= --no-print-directory -C
IFLAGS			:= -I$(PS_DEPS_DIR) -I$(FT_DEPS_DIR) -I$(FTP_DEPS_DIR) -I$(GNL_DIR) -I$(UT_DEPS_DIR)

all: $(UT_NAME) $(CH_NAME) $(PS_NAME)

$(UT_NAME): $(UT_SRCS) $(UT_DEPS)
	@$(MAKE) RPTH=$(UT_DIR) $(MFLAGS) $(UT_DIR)

$(CH_NAME): $(CH_SRCS) $(CH_DEPS)
	@$(call SUBMAKE_P,Checker)
	@$(MAKE) RPTH=$(CH_DIR) CH_ENAME=checker $(MFLAGS) $(CH_DIR)

$(PS_NAME): $(PS_OBJS)
	@$(call EXEC_P,$@)
	@$(CC) $(CFLAGS) -o $@ $(PS_OBJS) $(UT_NAME) $(IFLAGS)

$(PS_OBJS): |$(PS_OBJS_DIR)

$(PS_OBJS_DIR)/%.o: $(PS_SRCS_DIR)/%.c $(PS_DEPS) $(UT_DEPS)
	@$(call COMPILE_P,$@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(PS_OBJS_DIR):
	@$(call DIR_CREATE_P,$(PS_OBJS_DIR))
	@mkdir $(PS_OBJS_DIR)

clean:
	@$(MAKE) clean $(MFLAGS) $(UT_DIR)
	@$(MAKE) clean $(MFLAGS) $(CH_DIR)
	@$(RM) $(PS_OBJS_DIR)

fclean: clean
	@$(MAKE) fclean $(MFLAGS) $(CH_DIR)
	@$(MAKE) fclean $(MFLAGS) $(UT_DIR)
	@$(RM) $(PS_NAME)

re: fclean
	@$(MAKE)
