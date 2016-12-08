# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dye <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 02:57:41 by dye               #+#    #+#              #
#    Updated: 2016/12/05 03:14:04 by dye              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fillit
LIBFT 		= libft.a
GCC_FLAGS 	= -Wall -Werror -Wextra
CC 			= gcc $(GCC_FLAGS)
RM 			= rm -rf

SRCS		= main.c \
				board.c \
				board_helper.c \
				get_next_valid_pos.c \
				init_board.c \
				read.c \
				solve_map.c \
				start.c \
				store_tetriminos.c \
				tetrimino.c

SRCDIR		= ./src
OBJDIR		= ./obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

INC_PATH	= ./include/
INC 		= $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -Llibft $(OBJS) -lft -o $(NAME)

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) $(INC) -o $@ -c $^

$(LIBFT):
	@make -C ./libft/

clean:
	@$(RM) $(OBJS)
	@make clean -C ./libft/

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@make fclean -C ./libft/

re: fclean all

n:
	norminette src/*.c
	norminette include/*.h

t:
	rm -rf test_dir
	mkdir test_dir
	git clone vogsphere@vgs.42.us.org:intra/2016/activities/fillit/dye test_dir
	sh ~/42FileChecker/42FileChecker.sh --project "fillit" --path '$(PWD)/test_dir'


.PHONY: all clean fclean re n t