# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 19:03:48 by ilhannou          #+#    #+#              #
#    Updated: 2025/01/07 15:05:40 by ilhannou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printchar.c ft_printhex_up.c ft_printhex.c \
	  ft_printint.c ft_printptr.c ft_printstr.c ft_printunsigned.c

OBJDIR = obj
OBJ = obj/ft_printf.o obj/ft_printchar.o obj/ft_printhex_up.o obj/ft_printhex.o \
		obj/ft_printint.o obj/ft_printptr.o obj/ft_printstr.o obj/ft_printunsigned.o

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c ft_printf.h | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
