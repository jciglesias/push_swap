#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 12:55:34 by jiglesia          #+#    #+#              #
#    Updated: 2021/11/20 22:29:50 by jiglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	push_swap
CHNAME		=	checker

#****************** INC *******************#
# General
INC			=	./include/

# Libft
SUB_MAKE	=	./libft/
INCFT		=	./libft/

INCLUDE		=	-I $(INCFT) -I $(INC)

INC_LIB		=	$(INCFT)/libft.a


#***************** SRC* *******************#

DIRSRC		=	./src/
DIRCHEC		=	$(DIRSRC)/checker/
DIRMV		=	$(DIRSRC)/moves/
DIRINPUT	=	$(DIRSRC)/input/
DIRLIST		=	$(DIRSRC)/list/
DIRQ_SORT	=	$(DIRSRC)/q_sort/
DIRLASER	=	$(DIRSRC)

SRC			=	push_swap.c
CHECKER		=	checker.c
MOVES		=	ft_sab.c pushpop.c
INPUT		=	valid_input.c
LIST		=	fill_list.c free_listi.c stats.c sizes.c check_list.c
Q_SORT		=	q_sort.c
LOADING		=

PSRC		=	$(SRC) $(MOVES) $(INPUT) $(LIST) $(Q_SORT)
CSRC		=	$(CHECKER) $(MOVES) $(INPUT) $(LIST)

#***************** DEPS ******************#

DIROBJ		=	./depo/

OAUX		=	$(PSRC:%=$(DIROBJ)%)
CAUX		=	$(CSRC:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.c=.d)
OBJS		=	$(OAUX:.c=.o)
CDEPS		=	$(CAUX:.c=.d)
COBJS		=	$(CAUX:.c=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror
endif

CC			=	/usr/bin/clang
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRSRC)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRCHEC)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRMV)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRINPUT)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRLIST)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRQ_SORT)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRLASER)/%.c
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		ftlib $(OBJS)
				@$(CC)  $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_LIB)
				@$(ECHO) '> Compiled'

checker	:		ftlib $(COBJS)
				$(CC)  $(INCLUDE) $(CFLAGS) -o $(CHNAME) $(COBJS) $(INC_LIB)
				@$(ECHO) '> Compiled'

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(COBJS))
				@($(RM) $(DEPS))
				@($(RM) $(CDEPS))
				@(cd $(SUB_MAKE) && $(MAKE) clean)
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@$(RM) $(CHNAME)
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
				@$(ECHO) '> Remove executable'

re		:		fclean all

ftlib	:
				@(cd $(SUB_MAKE) && $(MAKE))

minilibx:
				@(cd $() && $(MAKE))

apt		:
				@(sudo apt-get install gcc make xorg libxext-dev libbsd-dev)

.PHONY	:		all clean re

-include $(DEPS)
