# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 13:31:00 by ggasset-          #+#    #+#              #
#    Updated: 2024/11/18 15:08:14 by ggasset-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL_C_FILES   =	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
#GNL_O_FILES	  =	get_next_line/get_next_line.o get_next_line/get_next_line_utils.o

LIBFT_C_FILES =	libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c

#LIBFT_O_FILES =	libft/ft_atoi.o libft/ft_bzero.o libft/ft_calloc.o libft/ft_isalnum.o libft/ft_isalpha.o libft/ft_isascii.o libft/ft_isdigit.o libft/ft_isprint.o libft/ft_itoa.o libft/ft_lstadd_back_bonus.o libft/ft_lstadd_front_bonus.o libft/ft_lstclear_bonus.o libft/ft_lstdelone_bonus.o libft/ft_lstiter_bonus.o libft/ft_lstlast_bonus.o libft/ft_lstmap_bonus.o libft/ft_lstnew_bonus.o libft/ft_lstsize_bonus.o libft/ft_memchr.o libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memmove.o libft/ft_memset.o libft/ft_putchar_fd.o libft/ft_putendl_fd.o libft/ft_putnbr_fd.o libft/ft_putstr_fd.o libft/ft_split.o libft/ft_strchr.o libft/ft_strdup.o libft/ft_striteri.o libft/ft_strjoin.o libft/ft_strlcat.o libft/ft_strlcpy.o libft/ft_strlen.o libft/ft_strmapi.o libft/ft_strncmp.o libft/ft_strnstr.o libft/ft_strrchr.o libft/ft_strtrim.o libft/ft_substr.o libft/ft_tolower.o libft/ft_toupper.o

PIPEX_C_FILES = 
#PIPEX_O_FILES = 

C_FILES = $(shell echo "${GNL_C_FILES} ${LIBFT_C_FILES} ${PIPEX_C_FILES} main.c")
#O_FILES = $(shell echo "${GNL_O_FILES} ${LIBFT_O_FILES} ${PIPEX_O_FILES} main.o")

TEST_C_FILES = $(shell echo "${GNL_C_FILES} ${LIBFT_C_FILES} ${PIPEX_C_FILES}")
#TEST_O_FILES = $(shell echo "${GNL_O_FILES} ${LIBFT_O_FILES} ${PIPEX_O_FILES}")

NAME = pipex
TEST_NAME = test_pipex


all: ${NAME}

test: ${TEST_NAME}

fclean: clean
	@rm -f ${NAME} ${TEST_NAME}

clean:

${NAME}: ${C_FILES}
	cc -Wall -Wextra -Werror -o ${NAME} $?

${TEST_NAME}: ${TEST_C_FILES}
	cc -o ${TEST_NAME} $? main_test.c

%.o: %.c
	echo $?
	cc -c -Wall -Werror -Wextra $?