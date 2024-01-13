CC=cc
CFLAGS=-Wall -Wextra -Werror 
HEADER=ft_printf.h
NAME=libftprintf.a
SRCS=   ./ft_putchar_fd.c \
	./ft_putnbr_fd.c \
	./ft_putstr_fd.c \
	./ft_strlen.c \
	./ft_printhexpointer.c \
	./ft_putnbr_unsigned.c \
	./ft_printf.c \
	./ft_putnbr_base.c \

OBJS= $(SRCS:.c=.o)
HEADER_DIR= .

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

