# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 10:09:10 by mdoquocb          #+#    #+#              #
#    Updated: 2022/03/31 13:12:10 by mdoquocb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
PROJECT = fractol

	#  BINARY  #

BIN_PATH = Bin/

BIN_NAME = $(PROJECT)

BIN = $(addprefix $(BIN_PATH),$(BIN_NAME))

	#  INCLUDES  #

INC_PATH_1 = ../libft/includes/

INC_NAME_1 = libft.h

INC = $(addprefix $(INC_PATH),$(INC_NAME))

LIBFT = ../libft/Bin/libft.a

INC_PATH = ../minilibx_opengl_20191021/includes/

INC_NAME = mlx.h

INC = $(addprefix $(INC_PATH),$(INC_NAME))

LIBFT = ../libft/Bin/libft.a

	#  SOURCES  #

SRC_PATH = Sources/

SRC_NAME = $(notdir $(wildcard Sources/*.c))

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

	#  OBJECTS  #

OBJ_PATH = $(BIN_PATH)Objects/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

	#  FLAGS  #

CC = gcc

CC_FLAGS = -Wall# -Wextra -Werror 

INC_FLAGS = -I ./Includes -I /usr/x11/include

LIB_FLAGS = -L ../libft/Bin -lft -L ../minilibx_opengl_20191021 -lmlx -framework OpenGL -framework Appkit

CL = rm -rf


	#  COLORS  #

GREEN = "\x1b[32m""\x1b[M"

RED = "\x1b[31m""\x1b[M"

BLUE = "\x1b[34m""\x1b[M"

	#  COMPILATION  #

all: $(BIN) 
		@echo $(GREEN) Compilation $(PROJECT) is completed !!

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
		@$(CC) $(CC_FLAGS) $(INC_FLAGS) -c $< -o $@
		@echo $(BLUE) $(notdir $@) is created !!

$(BIN): title libft directory $(OBJ)
		@$(CC) $(OBJ) $(LIB_FLAGS) -o $(BIN)
		@echo $(BLUE) $(notdir $(BIN)) is created !!

title: 
		@echo $(GREEN)****************$(PROJECT)****************

libft: 
		@$(MAKE) -C ../libft

directory: 	
		@mkdir -p $(OBJ_PATH) > /dev/null 2>&1 || true
		@echo $(BLUE) Binary $(PROJECT) directory created !!

nor:
		@echo $(GREEN) "norminette fractol.c!"
		norminette Includes/
		@echo $(GREEN) "norminette fractol.h!"
		norminette Sources/
		@echo $(GREEN) "norminette libft.h!"
		norminette ../libft/includes/
		@echo $(GREEN) "norminette libft.c!"
		norminette ../libft/Sources/

clean: 
		@$(CL) $(OBJ)
		@$(MAKE) clean -C ../libft
		@echo $(RED) Object $(notdir $(OBJ)) is delete !

fclean: clean 
		@$(CL) $(BIN)
		@$(MAKE) fclean -C ../libft
		@echo $(RED) Binary $(notdir $(BIN)) is delete !

finish: 
		@$(CL) $(BIN_PATH)
		@$(MAKE) finish -C ../libft
		@echo $(RED) All $(PROJECT) is delete !

re:	fclean all

.PHONY :	all clean fclean finish re directory
