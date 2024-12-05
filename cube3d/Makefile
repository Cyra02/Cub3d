# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 12:03:47 by ciestrad          #+#    #+#              #
#    Updated: 2024/12/05 11:46:29 by aszamora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = CUB3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
MLXFLAGS = -lXext -lX11 -lm #-g3 -fsanitize=address #-L . -lmlx -framework OpenGL -framework AppKit

FILES = get_next_line/get_next_line \
		src/main \
		src/errors \
		src/parseo/ft_parseo \
		src/parseo/parse_struct \
		src/parseo/parsing_check \
		src/utils/utils_parse \
		src/utils/utils_parse02 \

SRCS = $(addsuffix .c,$(FILES))
OBJS = $(addsuffix .o,$(FILES))

all: $(NAME)

.c.o: $(SRCS)
	@$(CC) -I includes/ $(CFLAGS) -c $^ -o $@ >/dev/null

$(NAME):  $(OBJS)
	@printf "\e[32mObjects Compiled✅\e[0m\n"
	@printf "\e[32mCompiling minilibx and libft...⏳\e[0m\n"
	@$(MAKE) -C minilibx >/dev/null
	@$(MAKE) -C libft >/dev/null
	@mv libft/libft.a .
	@mv minilibx/libmlx.a .
	@$(CC) $(CFLAGS) $(MLXFLAGS) $^ libft.a libmlx.a -o $@
	@printf "\e[32mReady to play 🤖\e[0m\n"

sanitize: #this rule adds the sanitize flag to CFLAGS
	@printf "\e[32mAdding Sanitize to CFLAGS\e[0m\n"
	$(eval CFLAGS += -fsanitize=address -g3)

sani: sanitize all #this rule changes CFLAGS to include sanitize and then compiles the program as usual

clean:
	@make clean -C libft >/dev/null
	@make clean -C minilibx >/dev/null
	@rm -rf $(OBJS)
	@printf "\e[31m*.o=>🗑️\e[0m\n"

fclean: clean
	@rm -rf $(NAME) >/dev/null
	@rm -rf libft.a >/dev/null
	@rm -rf libmlx.a >/dev/null
	@printf "\e[31m(so_long && libmlx.a && libftprintf.a)=>🗑️\e[0m\n"

re: fclean all

.PHONY: all clean fclean re