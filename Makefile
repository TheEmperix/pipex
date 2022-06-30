NAME	=	pipex
SRCS	=	pipex.c check.c	utils.c
HEADER	=	pipex.h
OBJ		=	$(SRCS:%.c=%.o)
LIB		=	libft/libft.a
INCLUDE	=	-I
СС		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		= rm -rf

all:		libft $(NAME)

libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o 	:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)
			@$(MAKE) -C libft/ clean


fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean	fclean	re	libft