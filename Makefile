# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstench <sstench@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 17:55:53 by sstench           #+#    #+#              #
#    Updated: 2020/11/26 16:35:37 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

FT_DIR = libft
VEC_DIR = libvec
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include \
          libft/include \
          libvec/include \
          SDL2/SDL2.framework/Headers

SRC = cone.c \
      cylinder.c \
      main.c \
      ray.c \
      plane.c \
      sphere.c \
      light.c \
      parser.c \
      utils.c \
      parse_utils.c \
      parse_light.c \
      parse_obj.c \
      valid_check.c

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

LDFLAGS += -L $(FT_DIR) \
           -L $(VEC_DIR)

LDLIBS += -lft \
          -lvec

SDL2 = -rpath @loader_path/SDL2 -framework SDL2 -F SDL2

RESET = \033[0;0m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

.PHONY: all clean fclean re

all:
	@$(MAKE) -C $(VEC_DIR)
	@$(MAKE) -C $(FT_DIR)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $^ $(LDFLAGS) $(LDLIBS) $(SDL2) -o $@
	@printf "RTv1:    %-24s$(GREEN)[done]$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@
	@printf "RTv1:    %-24s$(GREEN)[done]$(RESET)\n" $@

include $(wildcard $(DEP))

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(FT_DIR) clean
	@$(MAKE) -C $(VEC_DIR) clean
	@printf "RTv1:    %-24s$(RED)[done]$(RESET)\n"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(FT_DIR) fclean
	@$(MAKE) -C $(VEC_DIR) fclean
	@printf "RTv1:    %-24s$(RED)[done]$(RESET)\n"

re: fclean all
