# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llapage <llapage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 10:54:31 by llapage           #+#    #+#              #
#    Updated: 2023/05/22 10:43:29 by llapage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

#-------------------SOURCES PATH----------------------
SOURCES     = ./src/
HEADER_PWD  = ./includes/
#-------------------COMPILATION----------------------
CC          =   cc
FLAGS       =   -Wall -Werror -Wextra
# FLAGS     =   -Wall -Werror -Wextra -g
# FLAGS     =   -Wall -Werror -Wextra -fsanitize=address
#-------------------SOURCES FILES----------------------
HEADERS     =   $(HEADER_PWD)ft_printf.h

SRCS        =	$(SOURCES)ft_printf.c \
				$(SOURCES)print_any.c \
				$(SOURCES)format.c	\
				$(SOURCES)print_dixx.c \
				$(SOURCES)itoa.c	\
				$(SOURCES)itoa_16.c

#-------------------OBJECTS----------------------
OBJS        =   $(SRCS:.c=.o)
#-------------------HEADERS----------------------
I_HEADER    =   $(addprefix( -include, $(HEADERS)))
#-------------------COLORS-----------------------
RED         =   \x1b[31m
YELLOW      =   \x1b[33m
GREEN       =   \x1b[32m
NO_COLOR    =   \x1b[0m
BOLD        =   \x1b[1m
BOLD_OFF    =   \x1b[21m
#-------------------RULES-----------------------
%.o: %.c
			@$(CC) $(FLAGS) $(I_HEADER) -c $< -o $@
$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
#			@$(CC) $(FLAGS) $(OBJS) $(LIBPF_OBJ) -o $(NAME)
			@echo "\n$(GREEN)$(BOLD)Enjoy!$(BOLD_OFF)$(NO_COLOR)"
all:	$(NAME)
# bonus:    $(NAME)
clean:
		@echo "$(RED)Deleting objects...$(NO_COLOR)"
#       @make clean -C minilibx
		@rm -rf $(OBJS)
fclean:	clean
		@echo "$(RED)Deleting executables...$(NO_COLOR)"
#       @rm -rf $(LIB_MLX)
		@rm -f $(NAME)
re:	fclean all
.PHONY: all clean fclean bonus re
