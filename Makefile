# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cschabra <cschabra@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/13 18:15:02 by cschabra      #+#    #+#                  #
#    Updated: 2023/03/13 15:43:09 by cschabra      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= fractol
CFLAGS= -Wall -Wextra -Werror -Ofast $(HEADERS) #-fsanitize=address 

LIBFT= 42lib/libft
LIBMLX= 42lib/MLX42

HEADERS= -I include -I $(LIBFT)/include -I $(LIBMLX)/include
LIBS= $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a

CFILES= ./src/coloring.c \
./src/julia.c \
./src/main.c \
./src/mandelbrot.c \
./src/mouse.c \
./src/viewport.c

OBJECTS= $(CFILES:.c=.o)

all: $(NAME)

mlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@cmake --build $(LIBMLX)/build -j4

$(NAME): mlx $(OBJECTS)
	@$(MAKE) -C $(LIBFT)
	@$(CC) -o $(NAME) -lm $(CFLAGS) $(CFILES) $(LIBS) -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

clean:
	rm  -f $(OBJECTS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

debug: CFLAGS = -g
debug: re

.PHONY: all clean fclean re debug