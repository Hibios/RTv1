# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstench <sstench@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 19:05:18 by sstench           #+#    #+#              #
#    Updated: 2020/11/26 15:57:59 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a

SRC_DIR = src

SRC = ft_isdigit.c ft_lstmap.c ft_memdel.c ft_putnbr.c ft_strcmp.c ft_strjoin.c \
	ft_strncpy.c ft_strsub.c ft_isprint.c ft_lstnew.c ft_memmove.c ft_putnbr_fd.c \
	ft_strcpy.c ft_strlcat.c ft_strnequ.c ft_strtrim.c ft_atoi.c ft_itoa.c \
	ft_memalloc.c ft_memset.c ft_putstr.c ft_strdel.c ft_strlen.c ft_strnew.c \
	ft_tolower.c ft_bzero.c ft_lstadd.c ft_memccpy.c ft_putchar.c ft_putstr_fd.c \
	ft_strdup.c ft_strmap.c ft_strnstr.c ft_toupper.c ft_isalnum.c ft_lstdel.c \
	ft_memchr.c ft_putchar_fd.c ft_strcat.c ft_strequ.c ft_strmapi.c ft_strrchr.c \
	ft_isalpha.c ft_lstdelone.c ft_memcmp.c ft_putendl.c ft_strchr.c ft_striter.c \
	ft_strncat.c ft_strsplit.c ft_isascii.c ft_lstiter.c ft_memcpy.c ft_putendl_fd.c \
	ft_strclr.c ft_striteri.c ft_strncmp.c ft_strstr.c ft_elemcounter.c get_next_line.c \
	ft_atod.c ft_atoi_base.c

INC_DIR = include

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.d))

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	CC = clang
endif

ifeq ($(UNAME_S), Linux)
	CC = gcc
endif

CFLAGS += -Wall -Wextra -Werror \
          $(addprefix -I , $(INC_DIR)) \
          -MD \
          -march=native -O2 -pipe

RESET = \033[0;0m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

.PHONY: all clean flcean re

all: $(LIB)

$(LIB): $(OBJ)
	@printf "$(BLUE)"
	ar -cr $@ $?
	ranlib $@
	@printf "$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

include $(wildcard $(DEP))

clean:
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	@printf "$(RESET)"

fclean: clean
	@printf "$(RED)"
	rm -f $(LIB)
	@printf "$(RESET)"

re: fclean all

.PHONY: clean fclean all re
