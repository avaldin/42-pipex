# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:30:58 by avaldin           #+#    #+#              #
#    Updated: 2024/02/16 18:06:14 by avaldin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		##		COMPILATION			##

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -g3 -O3

		##		EXECUTABLE			##

NAME		=	pipex

		##		PATH				##

SRC_PATH	=	src
OBJ_PATH	=	obj

		##		SOURCES_FILES		##

SOURCES		=	src/command.c\
				src/pipex.c\
				src/process.c\
				src/security.c\
				src/libft/ft_putstr_fd.c\
				src/libft/ft_split.c\
				src/libft/ft_strdup.c\
				src/libft/ft_strjoin.c\
				src/libft/ft_strncmp.c\
				src/libft/ft_substr.c\
				src/libft/ft_strlen.c\

HEADER		=	header/pipex.h\

		##		OBJECTS				##

OBJS		=	$(SOURCES:.c=.o)

		##		RULES				##


all			:	$(NAME)
%.o			:	%.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
	$(CC) $(OBJS)  -o $(NAME)

clean		:
	rm -f $(OBJS)

fclean		:	clean
	rm -f $(NAME)

re        :    fclean all
.PHONY    :    all clean fclean re