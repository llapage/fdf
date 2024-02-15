# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llapage <llapage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 10:54:31 by llapage           #+#    #+#              #
#    Updated: 2023/06/30 17:08:32 by llapage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
#-------------------SOURCES PATH----------------------
SOURCES     = src/
HEADER_PWD  = ./includes/
PRINTF_PWD  = ./dep/ft_printf/
LIBFT_PWD   = ./dep/libft/
BONUS_PWD	= ./b_src/
#-------------------COMPILATION----------------------
CC          =   cc
FLAGS     	= 	-Wall -Werror -Wextra
# FLAGS     =   -Wall -Werror -Wextra -g
# FLAGS     =   -Wall -Werror -Wextra -g -fsanitize=address
#-------------------SOURCES FILES----------------------
HEADERS     =   $(HEADER_PWD)fdf.h

H_LIB       =   $(PRINT_PWD)ft_printf.h \
				$(LIBFT_PWD)libft.h

SRCS        =	$(SOURCES)main.c \
				$(SOURCES)get_next_line.c \
				$(SOURCES)get_next_line_utils.c \
				$(SOURCES)window.c \
				$(SOURCES)parsing.c \
				$(SOURCES)free.c \
				$(SOURCES)init.c \
				$(SOURCES)utils.c \
				$(SOURCES)draw_lines.c

SRC_LIBPF   =   $(PRINTF_PWD)$(SOURCES)ft_printf.c \
                $(PRINTF_PWD)$(SOURCES)format.c \
                $(PRINTF_PWD)$(SOURCES)print_any.c \
                $(PRINTF_PWD)$(SOURCES)print_dixx.c \
                $(PRINTF_PWD)$(SOURCES)itoa.c \
                $(PRINTF_PWD)$(SOURCES)itoa_16.c \
				$(LIBFT_PWD)ft_strlen.c \
				$(LIBFT_PWD)ft_atoi.c \
				$(LIBFT_PWD)ft_split.c \
				$(LIBFT_PWD)ft_strchr.c \
				$(LIBFT_PWD)ft_lstadd_back_bonus.c \
				$(LIBFT_PWD)ft_lstlast_bonus.c

# SRC_BONUS	=	$(BONUS_PWD)checker_bonus.c \

#-------------------OBJECTS----------------------
OBJS        =   $(SRCS:.c=.o)
LIBPF_OBJ	=	$(SRC_LIBPF:.c=.o)
#B_OBJS		=	$(SRC_BONUS:.c=.o)
#-------------------HEADERS----------------------
I_HEADER    =   $(addprefix( -include, $(HEADERS)))
I_H_LIB     =   $(addprefix( -include, $(H_LIB)))
I_MLX		=	-Imlx
#-------------------COLORS-----------------------
RED         =   \x1b[31m
YELLOW      =   \x1b[33m
GREEN       =   \x1b[32m
NO_COLOR    =   \x1b[0m
BOLD        =   \x1b[1m
BOLD_OFF    =   \x1b[21m
#-------------------RULES-----------------------
%.o: %.c
			@printf "$(YELLOW)Generating $(NAME) objects... %-33.33s\r$(NO_COLOR)" $@
			@$(CC) $(FLAGS) $(I_HEADER) $(I_H_LIB) $(I_MLX) -c $< -o $@
$(NAME):    $(LIBPF_OBJ) $(OBJS)
			@make -C ./dep/ft_printf/
			@make -C ./dep/libft/
			@printf "$(GREEN)Compiling $(NAME)... %33s\r$(NO_COLOR)" " "
			@$(CC) $(FLAGS) $(OBJS) $(LIBPF_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@echo "\n$(GREEN)$(BOLD)$@ done !$(BOLD_OFF)$(NO_COLOR)"
all:	$(NAME)
#bonus:	$(CHECKER)

clean:
		@echo "$(RED)Deleting objects...$(NO_COLOR)"
		@rm -rf $(OBJS)
		@rm -rf $(B_OBJS)
		@make clean -C ./dep/libft/
		@make clean -C ./dep/ft_printf/
fclean:	clean
		@echo "$(RED)Deleting executables...$(NO_COLOR)"
		@make fclean -C ./dep/ft_printf/
		@make fclean -C ./dep/libft/
		@rm -f $(NAME)
		@rm -f $(CHECKER)
re:	fclean all
.PHONY: all clean fclean bonus re
