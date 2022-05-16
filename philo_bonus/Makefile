.PHONY	:	all clean fclean re

NAME	=	philo_bonus
HEADER  =	includes/philo.h

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS	=	srcs/philo.c srcs/validation.c srcs/initialisation.c \
			srcs/utils.c
			

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror #-fsanitize=thread
RM		= rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		COLORS
#//////////////////////////////////////////////////////////////////////////////

BLUE	=	\033[1;34m
TURQUOISE =	\033[36;1m
END		=	\033[0m

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER) ${SRCS} ${HEAD}
	@echo "\n$(BLUE)Compilation of $(NAME)$(END)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(TURQUOISE)\n[ Completed $(NAME) ]\n$(END)"

%.o		:	%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
# $< - Имя первого пререквизита (подставляется первая зависимость).
# $@ - Имя файла цели обрабатываемого правила.

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(RM) $(OBJ)
			@rm -f $(OBJS)
			@echo "$(BLUE)\nCleaning done\n$(END)"

fclean	:	clean
			@echo Deleting $(NAME)
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\nDeleting done!\n$(END)"

re:			fclean all
			@echo "$(BLUE)Remake done\n$(END)"