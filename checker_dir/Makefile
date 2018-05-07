# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 08:03:18 by oevtushe          #+#    #+#              #
#    Updated: 2018/05/07 15:59:53 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include			Checker.mk

CC				:= gcc
RM				:= rm -rf
CFLAGS			:= -Wall -Werror -Wextra
MFLAGS			:= --no-print-directory -C
IFLAGS			:= -I$(CH_DEPS_DIR) -I$(FT_DEPS_DIR) -I$(FTP_DEPS_DIR) -I$(GNL_DIR) -I$(UT_DEPS_DIR)

CH_ENAME		?= $(CH_NAME)

all: $(CH_NAME)

$(CH_NAME): $(UT_NAME) $(CH_OBJS)
	@$(call EXEC_P,$(CH_ENAME))
	@$(CC) $(CFLAGS) -o $@ $(CH_OBJS) $(UT_NAME) $(IFLAGS)

# Utils
$(UT_NAME): $(UT_SRCS) $(UT_DEPS)
	@$(MAKE) RPTH=$(UT_DIR) $(MFLAGS) $(UT_DIR)

$(CH_OBJS): |$(CH_OBJS_DIR)

$(CH_OBJS_DIR)/%.o: $(CH_SRCS_DIR)/%.c $(CH_DEPS) $(UT_DEPS)
	@$(call COMPILE_P,$(RPTH)/$(@))
	@$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(CH_OBJS_DIR):
	@$(call DIR_CREATE_P,$(CH_OBJS_DIR:$(CH_DIR)/%=$(RPTH)/%))
	@mkdir $(CH_OBJS_DIR)

clean:
	@$(MAKE) clean $(MFLAGS) $(UT_DIR)
	@$(RM) $(CH_OBJS_DIR)

fclean: clean
	@$(MAKE) fclean $(MFLAGS) $(UT_DIR)
	@$(RM) $(CH_NAME)
re: fclean
	@$(MAKE)
