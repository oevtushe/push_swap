# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 12:34:24 by oevtushe          #+#    #+#              #
#    Updated: 2018/04/01 16:44:56 by oevtushe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		Utils.mk
include 	$(FT_DIR)/Pretty.mk

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
MFLAGS		:= --no-print-directory -C
RM			:= rm -rf
AR			:= ar
ARFLAGS		:= rc
IFLAGS		:= -I$(UT_DEPS_DIR) -I$(FT_DEPS_DIR) -I$(GNL_DIR) -I$(FTP_DEPS_DIR)

$(UT_NAME): $(UT_OBJS)
	@$(call MKLIB_P,$(@:%=$(RPTH)/%))
	@$(AR) $(ARFLAGS) $(UT_NAME) $?
	@$(call DONE_P)

$(UT_OBJS_DIR)/%.o: $(UT_SRCS_DIR)/%.c $(UT_DEPS)
	@$(call COMPILE_P,$(@:$(UT_DIR)/%=$(RPTH)/%))
	@$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(FT_OBJS_DIR)/%.o: $(FT_DIR)/%.c $(FT_DEPS)
	@$(call SUBMAKE_P,LibFt)
	@$(MAKE) obj RPTH=$(RPTH)/$(FT_DIR:$(UT_DIR)/%=%) $(MFLAGS) $(FT_DIR)

$(GNL_OBJS_DIR)/%.o: $(GNL_DIR)/%.c $(GNL_DEPS) $(FT_DEPS)
	@$(call SUBMAKE_P,Get_Next_Line)
	@$(MAKE) obj FT_DIR=../../$(FT_DIR) RPTH=$(RPTH)/$(GNL_DIR:$(UT_DIR)/%=%) $(MFLAGS) $(GNL_DIR)

$(FTP_OBJS_DIR)/%.o: $(FTP_SRCS_DIR)/%.c $(FTP_DEPS) $(FT_DEPS)
	@$(call SUBMAKE_P,Ft_Printf)
	@$(MAKE) obj FT_DIR=../../$(FT_DIR) RPTH=$(RPTH)/$(FTP_DIR:$(UT_DIR)/%=%) $(MFLAGS) $(FTP_DIR)

$(UT_NW_OBJS): |$(UT_OBJS_DIR)

$(UT_OBJS_DIR):
	@$(call DIR_CREATE_P,$(UT_OBJS_DIR:$(UT_DIR)/%=$(RPTH)/%))
	@mkdir $@

clean:
	@$(RM) $(UT_OBJS_DIR)
	@$(MAKE) clean FT_DIR=../../$(FT_DIR) $(MFLAGS) $(FT_DIR)
	@$(MAKE) clean FT_DIR=../../$(FT_DIR) $(MFLAGS) $(GNL_DIR)
	@$(MAKE) clean FT_DIR=../../$(FT_DIR) $(MFLAGS) $(FTP_DIR)

fclean: clean
	@$(RM) $(UT_NAME)
re: fclean
	@$(MAKE)
