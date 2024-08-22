# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 15:17:27 by gwagner           #+#    #+#              #
#    Updated: 2024/08/22 12:09:19 by hzakharc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			=	srcs/
INC_DIR			=	includes/
LIBFT_DIR		=	includes/libft/

LIBFT			=	$(LIBFT_DIR)libft.a

PARSE_DIR		=	$(SRC_DIR)parsing/
EXEC_DIR		=	$(SRC_DIR)execution/

MAIN_SRC		=	$(SRC_DIR)minishell.c
PARSE_SRC		=
EXEC_SRC		=

PARSE_SRCS		=	$(patsubst %.c,$(PARSE_DIR)%.c,$(PARSE_SRC))
EXEC_SRCS		=	$(patsubst %.c,$(EXEC_DIR)%.c,$(EXEC_SRC))

PARSE_OBJS		=	$(PARSE_SRCS:.c=.o)
EXEC_OBJS		=	$(EXEC_SRCS:.c=.o)
OBJS			=	$(MAIN_SRC:.c=.o) $(PARSE_OBJS) $(EXEC_OBJS)

BLUE		=	\033[0;94m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\e[0;33m
CYAN		=	\033[0;96m
COLOR		=	\033[0m

CC				=	@cc -Wall -Werror -Wextra
RM				=	@rm -f

NAME			=	lainshell

%.o:			%.c
					$(CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
					@make -sC $(LIBFT_DIR)
					@$(CC) $(OBJS) ${LIBFT} -o $(NAME) -lreadline
					@./lain.sh

clean:
					@make -sC $(LIBFT_DIR) clean
					$(RM) $(OBJS)

fclean:			clean
					@make -sC $(LIBFT_DIR) fclean
					$(RM) $(NAME)

re:				fclean all

lain:			
				@firefox https://www.youtube.com/watch?v=MM8RufZr5lw

.PHONY:			all clean fclean re
