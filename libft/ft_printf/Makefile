CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

MANDOTARY = ft_adress_printf.c	ft_char_printf.c	ft_hexa_printf.c	ft_nb_printf.c	ft_printf.c	ft_str_printf.c	ft_unb_printf.c	ft_len.c


OBJ =$(MANDOTARY:.c=.o)

.o : .c

all : $(NAME)

$(NAME) : $(OBJ) 
	@ar -rcs $(NAME) $(OBJ)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf  $(NAME)

re : fclean	all
