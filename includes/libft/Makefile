# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 12:31:57 by ilhannou          #+#    #+#              #
#    Updated: 2025/01/19 20:30:40 by ilhannou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_atoi.c ft_split.c ft_strchr.c ft_strdup.c ft_strlen.c ft_strncmp.c

OBJ = obj/ft_atoi.o obj/ft_split.o obj/ft_strchr.o obj/ft_strdup.o obj/ft_strlen.o obj/ft_strncmp.o

OBJDIR = obj

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c libft.h | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
