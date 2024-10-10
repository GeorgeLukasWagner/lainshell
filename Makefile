# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 15:17:27 by gwagner           #+#    #+#              #
#    Updated: 2024/10/10 16:43:19 by hzakharc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			=	srcs/
INC_DIR			=	includes/
LIBFT_DIR		=	includes/libft/

LIBFT			=	$(LIBFT_DIR)libft.a

PARSE_DIR		=	$(SRC_DIR)parsing/
EXEC_DIR		=	$(SRC_DIR)execution/
ARGS_DIR		=	$(PARSE_DIR)arguments/
ERR_DIR 		=	$(PARSE_DIR)errorcheck/
BUILT_DIR		=	$(EXEC_DIR)builtin/

MAIN_SRC		=	$(SRC_DIR)minishell.c
ARGS_SRC		=	split_args.c put_args.c parse_utils.c arglist01.c arglist02.c enviroment01.c enviroment02.c variables.c argor.c var2.c make_cmd.c clean_cmd.c redirm.c cmd_utils.c redir_utils.c some_funcs.c var_helper.c
ERR_SRC			=	syntax_error.c
EXEC_SRC		=	path.c execute.c util.c redir.c pipe.c exec_util.c pipe_util.c exec_util2.c files_util.c
BUILT_SRC		=	pwd.c env.c export.c unset.c echo.c cd.c export_util.c cd_util.c pwd_util.c

ARGS_SRCS		=	$(patsubst %.c,$(ARGS_DIR)%.c,$(ARGS_SRC))
ERR_SRCS		=	$(patsubst %.c,$(ERR_DIR)%.c,$(ERR_SRC))
EXEC_SRCS		=	$(patsubst %.c,$(EXEC_DIR)%.c,$(EXEC_SRC))
BUILT_SRCS		=	$(patsubst %.c,$(BUILT_DIR)%.c,$(BUILT_SRC))

ARGS_OBJS		=	$(ARGS_SRCS:.c=.o)
ERR_OBJS		=	$(ERR_SRCS:.c=.o)
EXEC_OBJS		=	$(EXEC_SRCS:.c=.o)
BUILT_OBJS		=	$(BUILT_SRCS:.c=.o)
OBJS			=	$(MAIN_SRC:.c=.o) $(ARGS_OBJS) $(ERR_OBJS) $(EXEC_OBJS) $(BUILT_OBJS)

BLUE		=	\033[0;94m
RED 		=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\e[0;33m
CYAN		=	\033[0;96m
COLOR		=	\033[0m

CC				=	@cc -Wall -Werror -Wextra -g
RM				=	@rm -f

NAME			=	minishell

%.o:			%.c
					$(CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
					@make -sC $(LIBFT_DIR)
					@$(CC) $(OBJS) ${LIBFT} -o $(NAME) -lreadline

clean:
					@make -sC $(LIBFT_DIR) clean
					$(RM) $(OBJS)

fclean:			clean
					@make -sC $(LIBFT_DIR) fclean
					$(RM) $(NAME)

re:				fclean all

lain:			
				@firefox https://www.youtube.com/watch?v=MM8RufZr5lw

runb: all
	valgrind --leak-check=full ./minishell

.PHONY:			all clean fclean re
