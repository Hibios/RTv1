# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstench <sstench@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 17:29:23 by sstench           #+#    #+#              #
#    Updated: 2020/11/26 15:42:14 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libvec.a

SRC_DIR = src

SRC = vec_new.c \
      vec_scale.c \
      vec_add.c \
      vec_sub.c \
      vec_magn.c \
      vec_norm.c \
      vec_dot.c \
      vec_cross.c \
      vec_rot_x.c \
      vec_rot_y.c \
      vec_rot_z.c \
      vec_cpy.c \
      vec_rot_xyz.c \
      vec_rot_zyx.c

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
