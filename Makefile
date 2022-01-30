# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 16:38:36 by vchevill          #+#    #+#              #
#    Updated: 2022/01/30 19:10:47 by vchevill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc -Wall -Werror -Wextra #-g -fsanitize=address -g3

SRCS =	ft_init.c \
		ft_utils_init.c \
		ft_ope_push_swap.c \
		ft_ope_rotatations.c \
		push_swap_utils.c \
		push_swap.c \
		quick_sort.c \
		sort_0_3.c \
		sort_4_5.c

SRCS_FILES = $(addprefix srcs/, $(SRCS))

OBJS = $(SRCS:.c=.o)

OBJS_FILES = $(addprefix objs/, $(OBJS))

LIB = libft/libft.a

all : libft $(NAME)

$(NAME)	:	$(OBJS_FILES) $(LIB) Makefile
			$(CC) $(OBJS_FILES) -o $(NAME) libft/libft.a

libft	:	
			$(MAKE) -C libft

objs/%.o:	srcs/%.c	srcs/push_swap.h libft/libft.h
			@mkdir -p objs
			$(CC) -c $< -o $@
			
clean	:
			rm -rf objs/
			rm -rf tmp/
			make clean -C libft
			
fclean	:	clean
			rm -f $(NAME)
			make fclean -C libft

re		:	fclean all

.PHONY	:	libft all clean re fclean
