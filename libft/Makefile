NAME = libft.a

SRCS =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strdup.c ft_strlen.c \
		ft_toupper.c ft_tolower.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_strnstr.c ft_memset.c ft_bzero.c ft_memccpy.c ft_memcpy.c ft_memmove.c ft_memcmp.c \
		ft_atoi.c ft_calloc.c ft_strjoin.c ft_split.c ft_itoa.c ft_substr.c ft_strtrim.c \
		ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c  ft_strmapi.c ft_memchr.c ft_putnbr_fd.c \
		ft_putchar_bonus.c ft_putnbr_bonus.c ft_putstr_bonus.c ft_strncat_bonus.c ft_strcat_bonus.c \
		ft_strncpy_bonus.c ft_strcmp_bonus.c ft_strstr_bonus.c \

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -I.

RM = rm -f

LIB = ar rc ${NAME}

.c.o =  ${CC} ${CFLAGS} -c $< -o ${$<.c=.o}

${NAME}: ${OBJS}
		${LIB} ${OBJS}

all: ${NAME}

bonus: ${OBJS} ${OBJS_BONUS}
	${LIB} ${OBJS} ${OBJS_BONUS}

clean: 
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re
