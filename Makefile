# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstench <sstench@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 17:55:53 by sstench           #+#    #+#              #
#    Updated: 2020/11/25 17:42:25 by sstench          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
N_LFT = libft.a
N_LVEC = libvec.a
N_SDLARCH = SDL2-2.0.12.tar.gz

D_LFT = ./libft/
D_LVEC = ./libvec/
D_SRC = ./sources/
D_INC = ./includes/
D_LVECINC = $(D_LVEC)includes/
D_SDL = ./SDL2-2.0.12/
D_SDLINC = $(D_SDL)include
D_SDLLIB = $(D_SDL)lib
D_OBJ = ./objects/

L_SDL = `$(D_SDL)sdl2-config --cflags --libs`

LFT = $(D_LFT)$(N_LFT)
LVEC = $(D_LVEC)$(N_LVEC)

HEADER_FILES = $(D_INC)rtv1.h $(D_INC)rtv1types.h $(D_INC)parser.h
LIBHEAD = $(D_LFT)libft.h $(D_LVECINC)libvec.h

C_FILES =		cone.c\
				cylinder.c\
				main.c\
				ray.c\
				plane.c\
				sphere.c\
				light.c\
				parser.c\
				utils.c\
				parse_utils.c\
				parse_light.c\
				parse_obj.c\
				valid_check.c

LIBFT_FILES = ft_isdigit.c ft_lstmap.c ft_memdel.c ft_putnbr.c ft_strcmp.c ft_strjoin.c \
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

LIBVEC_FILES =	vec_new.c\
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

SRC = $(addprefix $(D_SRC), $(C_FILES))
LFTSRC = $(addprefix $(D_LFT), $(LIBFT_FILES))
LVECSRC = $(addprefix $(D_LVEC)sources/, $(LIBVEC_FILES))
OBJ = $(addprefix $(D_OBJ), $(C_FILES:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -O1
INC = -I $(D_INC) -I $(D_LFT) -I $(D_LVECINC) -I $(D_SDLINC)

C_RED = \033[31m
C_GREEN = \033[32m
C_CYAN = \033[36m
C_NONE = \033[0m

all: $(NAME)

$(NAME): $(D_SDL) $(D_SDLLIB) $(D_OBJ) $(OBJ) $(LFTSRC) $(LVECSRC) $(LIBHEAD)
	@make -C $(D_LFT)
	@printf "RTv1:    %-24s$(C_GREEN)[done]$(C_NONE)\n" "libft.a"
	@make -C $(D_LVEC)
	@printf "RTv1:    %-24s$(C_GREEN)[done]$(C_NONE)\n" "libvec.a"
	@$(CC) $(OBJ) $(LFT) $(LVEC) $(L_SDL) -o $(NAME)
	@printf "RTv1:    %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

$(N_LFT):
	@make -C $(D_LFT)
	@printf "RTv1:    %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

$(N_LVEC):
	@make -C $(D_LVEC)
	@printf "RTv1:    %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

$(D_SDL):
	@tar -xf $(N_SDLARCH)
	@printf "RTv1:    %-24s$(C_CYAN)[extracted]$(C_NONE)\n" $@

$(D_SDLLIB):
	@mkdir $(D_SDLLIB)
	@printf "\n$(C_CYAN)[configuring SDL]$(C_NONE)\n"
	@cd $(D_SDL); ./configure --prefix=`pwd`/lib
	@printf "$(C_CYAN)[compiling SDL]$(C_NONE)\n"
	@make -C $(D_SDL)
	@make -C $(D_SDL) install >/dev/null
	@printf "RTv1:    %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

$(D_OBJ):
	@mkdir $(D_OBJ)
	@printf "RTv1:    %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

$(D_OBJ)%.o: $(D_SRC)%.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@
	@printf "RTv1:    %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

clean:
	@rm -rf $(D_OBJ)
	@make -C $(D_LFT) clean
	@make -C $(D_LVEC) clean
	@printf "RTv1:    %-24s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(D_SDL)
	@make -C $(D_LFT) fclean
	@make -C $(D_LVEC) fclean
	@printf "RTv1:    %-24s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all

norm: clean
	@norminette $(D_SRC) $(D_INC)

allnorm: norm
	@norminette $(D_LFT)
	@norminette $(D_LVEC)
