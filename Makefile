NAME = libftprintf.a

SRCS =  ft_char.c ft_id.c ft_num.c ft_p.c ft_str.c ft_x.c type_convert.c \
		check_convert.c ft_get_tags.c ft_itoa_base.c ft_pars2.c ft_printf.c ft_putnbr_unsigned.c \
		ft_u.c ft_xmaj.c ft_modulo.c ft_id_neg.c ft_p_neg.c ft_write.c \
		type_convert2.c \

LIBFT =  libft/

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

LIB = ar -rc ${NAME}

.c.o = ${CC} ${CFLAGS} -c $< -o ${$<.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	${LIB} $@ $^

clean:
	@make clean -C libft/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
