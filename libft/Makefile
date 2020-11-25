# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstench <sstench@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 19:05:18 by sstench           #+#    #+#              #
#    Updated: 2020/11/25 17:47:24 by sstench          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

HEADER = libft.h

SRC = *.c

OBJ = $(SRC:.c=.o)

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

OBJ = ft_isdigit.o ft_lstmap.o ft_memdel.o ft_putnbr.o ft_strcmp.o ft_strjoin.o \
	ft_strncpy.o ft_strsub.o ft_isprint.o ft_lstnew.o ft_memmove.o ft_putnbr_fd.o \
	ft_strcpy.o ft_strlcat.o ft_strnequ.o ft_strtrim.o ft_atoi.o ft_itoa.o \
	ft_memalloc.o ft_memset.o ft_putstr.o ft_strdel.o ft_strlen.o ft_strnew.o \
	ft_tolower.o ft_bzero.o ft_lstadd.o ft_memccpy.o ft_putchar.o ft_putstr_fd.o \
	ft_strdup.o ft_strmap.o ft_strnstr.o ft_toupper.o ft_isalnum.o ft_lstdel.o \
	ft_memchr.o ft_putchar_fd.o ft_strcat.o ft_strequ.o ft_strmapi.o ft_strrchr.o \
	ft_isalpha.o ft_lstdelone.o ft_memcmp.o ft_putendl.o ft_strchr.o ft_striter.o \
	ft_strncat.o ft_strsplit.o ft_isascii.o ft_lstiter.o ft_memcpy.o ft_putendl_fd.o \
	ft_strclr.o ft_striteri.o ft_strncmp.o ft_strstr.o ft_elemcounter.o get_next_line.o \
	ft_atod.o ft_atoi_base.o

C_GREEN = \033[32m
C_RED = \033[31m
C_NONE = \033[0m

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "Libft:   %-24s$(GREEN)[done]$(C_NONE)\n" $@

$(OBJ): %.o : %.c
	@gcc $(CFLAGS) -c $<
	@printf "Libft:   %-24s$(GREEN)[done]$(C_NONE)\n" $@

clean:
	@$(RM) $(OBJ)
	@printf "Libft:   %-24s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@$(RM) $(NAME)
	@printf "Libft:   %-24s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all

.PHONY: clean fclean all re
