# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:54:54 by biphuyal          #+#    #+#              #
#    Updated: 2026/01/19 17:02:50 by biphuyal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include -I /opt/homebrew/opt/readline/includes
SRCS = core/philosophers.c core/checks.c core/start.c

OBJ_DIR = .obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(INCLUDES)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

val: re
	@valgrind --show-leak-kinds=all --leak-check=full --track-fds=all ./philo

test: re
	@git clone https://github.com/dantonik/42-philosophers-tester.git
	@cd 42-philosophers-tester && (./test.sh || true) && cd ..
	@rm -rf 42-philosophers-tester

.PHONY: all re clean fclean val readline.supp