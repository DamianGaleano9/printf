NAME = libftprintf.a
# LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft 

SCRCS = ft_printf.c \
				ft_print_poin.c \
				ft_print_unsigned.c \
				ft_print_string.c \
				ft_print_int.c \
				ft_print_char.c \
				ft_print_hexa.c \

OBJS = $(SCRCS:.c=.o)


all : $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .


clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all
