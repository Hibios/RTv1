# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstench <sstench@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 17:29:23 by sstench           #+#    #+#              #
#    Updated: 2020/11/25 17:33:51 by sstench          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a
CFILES = \
	vec_new.c\
	vec_scale.c\
	vec_add.c\
	vec_sub.c\
	vec_magn.c\
	vec_norm.c\
	vec_dot.c\
	vec_cross.c\
	vec_rot_x.c\
	vec_rot_y.c\
	vec_rot_z.c\
	vec_cpy.c\
	vec_rot_xyz.c\
	vec_rot_zyx.c

HFILES = libvec.h

D_SRC = ./sources/
D_OBJ = ./objects/
D_INC = ./includes/

SRC = $(addprefix $(D_SRC), $(CFILES))
OBJ = $(addprefix $(D_OBJ), $(CFILES:.c=.o))
INC = $(addprefix $(D_INC), $(HFILES))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

C_RED = \033[31m
C_GREEN = \033[32m
C_NONE = \033[0m

all: $(NAME)

$(NAME): $(INC) $(D_OBJ) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "Libvec:  %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

$(D_OBJ):
	@mkdir $(D_OBJ)
	@printf "Libvec:  %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

$(D_OBJ)%.o:$(D_SRC)%.c $(INC)
	@$(CC) $(CFLAGS) -c -I $(D_INC) $< -o $@
	@printf "Libvec:  %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

clean:
	@rm -rf $(D_OBJ)
	@printf "Libvec:  %-24s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@rm -rf $(NAME)
	@printf "Libvec:  %-24s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all

norm:
	@norminette $(D_INC) $(D_SRC)
