# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 21:49:47 by dmazo-ga          #+#    #+#              #
#    Updated: 2024/11/18 19:04:20 by dmazo-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = CC
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SCRCS = ft_printf.c \
				print_pointer.c \
				print_unsigned.c \
				print_string.c \
				print_int.c \
				print_char.c \
				print_hex.c \

OBJS = $(SCRCS:.c=.o)

all = $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all
