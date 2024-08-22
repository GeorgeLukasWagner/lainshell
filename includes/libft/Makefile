# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 11:56:37 by gwagner           #+#    #+#              #
#    Updated: 2024/08/18 15:16:08 by gwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
				ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memset.c \
				ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
				ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
				ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c
SRC_DIR		= srcs/
SRCS		= $(patsubst %.c,$(SRC_DIR)%.c,$(SRC))
OBJS		= $(SRCS:.c=.o)
INCL        = libft.h
CC          = @cc
RM          = @rm -f
CFLAGS      = -Wall -Werror -Wextra -I $(INCL)
NAME        = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re