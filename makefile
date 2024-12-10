NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
LIBRARY = ar rc 

SCRCS = ft_printf.c \
				ft_print_poin.c \
				ft_print_unsigned.c \
				ft_print_string.c \
				ft_print_int.c \
				ft_print_char.c \
				ft_print_hexa.c \

OBJS = $(SRCS:.c=.o)

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(LIBRARY) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	$(REMOVE) $(OBJS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

debug:
	$(CC) -g $(FLAGS) $(SRCS)
