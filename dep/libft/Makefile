NAME = libft.a
BIN = $(SRCS:.c=.o)

SRCS = 	ft_isalnum.c ft_isdigit.c ft_memcpy.c ft_memcmp.c ft_strchr.c  ft_strlen.c  ft_tolower.c ft_isalpha.c \
        ft_isprint.c ft_memmove.c ft_strlcat.c ft_strncmp.c ft_toupper.c ft_bzero.c ft_isascii.c ft_memchr.c \
        ft_memset.c ft_strlcpy.c ft_strrchr.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_BIN = $(BONUS:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	cc $(FLAGS) -c $(SRCS)
	ar rcs $(NAME) $(BIN)

clean:
	rm -f $(BIN) $(BONUS_BIN)

fclean: clean
	rm -f libft.a

bonus: $(BIN) $(BONUS_BIN)
	ar rcs $(NAME) $(OBS) $(BONUS_BIN)
re: fclean all
