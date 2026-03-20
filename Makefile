# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 14:39:24 by jdiaz-ec          #+#    #+#              #
#    Updated: 2026/03/18 14:39:26 by jdiaz-ec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = alg_data.c algorithm_complex.c bench_utils.c check_errors.c \
		chunks_sort.c free_functions.c ft_ftoa.c ft_itoa.c ft_printf.c \
		list_functions.c medium_alg.c operations_rotate.c operations.c \
		parse_args.c parse_flags.c print_letters.c print_nums.c push_swap.c \
		safe_split.c selection_sort.c simple_alg.c utils_alg.c utils.c utils2.c

OBJS := $(SRC:%.c=%.o)

NAME = push_swap

CC = cc

CCFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I.

RM = rm -f

ARNAME = ar rcs $(NAME)

RANNAME = ranlib $(NAME)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all