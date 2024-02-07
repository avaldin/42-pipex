# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:11:14 by avaldin           #+#    #+#              #
#    Updated: 2024/01/31 09:56:18 by avaldin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS    =   pipex.c\
			command.c\
			process.c\
			security.c\



OBJS    =    $(SRCS:.c=.o)


HEADER    =    pipex.h

NAME    =    pipex

CC        =    cc

FLAGS    =    -Wall -Wextra -Werror -g3

# ---- Libs variables ---- #

LIBFT			=   libft/libft.a

FRAMEWORKS		=	-Llibft -lft

$(NAME)    :    $(OBJS) $(HEADER) $(LIBFT)
	$(CC) $(FLAGS) -I $(HEADER) $(OBJS) $(FRAMEWORKS) -o $(NAME)

$(LIBFT) :
			make -C libft

all			:
				make -C libft/
				make $(NAME)

%.o        :    %.c $(HEADER)
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@


clean    :
	rm -f $(OBJS)

fclean    :    clean
	rm -f $(NAME)

re        :    fclean all

.PHONY    :    all clean fclean re bonus