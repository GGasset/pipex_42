# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 13:31:00 by ggasset-          #+#    #+#              #
#    Updated: 2025/01/27 12:52:16 by ggasset-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PIPEX_O_FILES = utils.o args.o dealloc.o envp.o functionality.o io.o pipex.o main.o

NAME = pipex
LIBFT_NAME = libft/libft.a
#\n ▗▄▄▖       ▗▄▄▖\n▐▌         ▐▌   \n▐▌▝▜▌      ▐▌▝▜▌\n▝▚▄▞▘ermán ▝▚▄▞▘asset\n        \n          \n

LOGO=_▗▄▄▄▖    ▗▄▄▄▖\n▐▌       ▐▌   \n▐▌▌▝▜▌   ▐▌▌▝▜▌\n▝▚▄▄▞▘   ▝▚▄▄▞▘     \n        
LOGO=\n ▗▄▄▄▄▖    ▗▄▄▄▄▖\n▐▌        ▐▌ \n▐▌ ▝▝▜▌   ▐▌ ▝▝▜▌\n▝▚▄▄▄▞▘   ▝▚▄▄▄▞▘     \n        


all: logo libft ${NAME}

${NAME}: ${PIPEX_O_FILES} ${LIBFT_NAME}
	cc -lc -o ${NAME} ${PIPEX_O_FILES} ${LIBFT_NAME}

%.o: %.c
	cc -g -Wall -Wextra -Werror -c $?

re: fclean all

fclean: clean
	@rm -f ${NAME}

clean: libft-fclean
	@rm -f ${PIPEX_O_FILES}

test:
	cc -lc -g libft/*.c ./*.c


# LIBFT

libft:
	make --directory=./libft/ all

libft-re: libft-fclean libft

libft-clean:
	make --directory=./libft/ clean

libft-fclean:
	make --directory=./libft/ fclean

logo:
	@echo "${LOGO}"
	@echo "\n       _              _       \n   _  /\\ \\          /\\ \\      \n  /\\_\\\\ \\ \\        /  \\ \\     \n / / / \\ \\ \\      / /\\ \\ \\    \n/ / /   \\ \\ \\     \\/_/\\ \\ \\   \n\\ \\ \\____\\ \\ \\        / / /   \n \\ \\________\\ \\      / / /    \n  \\/________/\\ \\    / / /  _  \n            \\ \\ \\  / / /_/\\_\\ \n             \\ \\_\\/ /_____/ / \n              \\/_/\\________/  \n                              \n"
	@sleep .5

.PHONY: all test re fclean clean  libft libft-re libft-clean libft-fclean