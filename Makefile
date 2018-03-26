# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 10:42:51 by bpodlesn          #+#    #+#              #
#    Updated: 2018/03/26 17:14:38 by bpodlesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c \
	fracs.c \
	zoom.c \
	draw.c \
	threads.c \
	ft_thread.c \
	fill_pic_thread.c \
	keys.c \
	complex_thread.c \
	math.c \

OBJ = main.o \
	fracs.o \
	zoom.o \
	draw.o \
	threads.o \
	ft_thread.o \
	fill_pic_thread.o \
	keys.o \
	complex_thread.o \
	math.o \

MLX = -lmlx -framework OpenGL -framework AppKit

FLAGS = -c -Wall -Werror -Wextra

HEADER = fractol.h

all: $(NAME)

all: lib $(NAME)

$(NAME): $(OBJ) $(HEADER) libft/libft.a
		gcc $(FLAGS) $(SRCS)
		gcc -g -o $(NAME) $(OBJ) libft/libft.a $(MLX)
		@afplay ./surprise-motherfucker.mp3

libft/libft.a: lib

lib:
	make -C libft

$(OBJ): %.o : %.c $(HEADER)
	gcc $(FLAGS) $< -o $@

clean:
		@ /bin/rm -f $(OBJ) ./fractol.h.gch
		@ make -C libft/ clean

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean

re: fclean all
