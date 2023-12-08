NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

PRINTF = ft_printf.h

SRCS =  ft_decimal_to_hexa.c\
		ft_evaluate_one.c\
		ft_evaluate_two.c\
		ft_printf.c\
		ft_itoa.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_strdup.c\
		ft_strlen.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar -crs $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re
