# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 13:27:39 by ilhannou          #+#    #+#              #
#    Updated: 2025/01/21 13:59:45 by ilhannou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

SRCDIR = src
OBJDIR = obj
LIBFTDIR = includes/libft
PRINTFDIR = includes/printf

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/errors.c src/free.c src/main.c src/operations2.c src/operations.c src/tolist.c src/notturk.c \
	src/notturk2.c src/find.c src/size.c src/ft_lst.c src/calculate.c

CHECKER_SRC = src/checker.c src/errors.c src/free.c src/operations2.c src/operations.c src/tolist.c \
	src/notturk.c src/notturk2.c src/find.c src/size.c src/ft_lst.c src/calculate.c

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CHECKER_OBJ = $(CHECKER_SRC:$(SRCDIR)/%.c=$(OBJDIR)/checker_%.o)

LIBFT = libft.a
PRINTF = libftprinf.a

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJ)
	@echo "Compiling the main project..."
	@make -C ./includes/libft --silent
	@make -C ./includes/printf --silent
	@$(CC) $(CFLAGS) -o $@ $^ -L$(PRINTFDIR) -lftprintf -L$(LIBFTDIR) -lft
	@echo "Compilation complete!"

$(CHECKER): $(CHECKER_OBJ)
	@echo "Compiling checker..."
	@$(CC) $(CFLAGS) -o $@ $^ includes/get_next_line/get_next_line.c includes/get_next_line/get_next_line_utils.c -L$(PRINTFDIR) -lftprintf -L$(LIBFTDIR) -lft
	@echo "Checker compilation complete!"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/checker_%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)
	@make clean -C ./includes/libft --silent
	@make clean -C ./includes/printf --silent
	@echo "Cleaned object files!"

fclean: clean
	@echo "Removing executable and libraries..."
	@rm -rf $(NAME) $(CHECKER)
	@make fclean -C ./includes/libft --silent
	@make fclean -C ./includes/printf --silent
	@echo "All cleaned!"

re: fclean all

.PHONY: all bonus re clean fclean