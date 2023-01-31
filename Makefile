# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otokluog <otokluog@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 11:00:57 by otokluog          #+#    #+#              #
#    Updated: 2022/06/27 13:16:20 by otokluog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME1 = client

SRC = server.c
SRC1 = client.c
SRCB = server_bonus.c
SRCB1 = client_bonus.c

FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)
OBJB = $(SRCB:.c=.o)
OBJB1 = $(SRCB1:.c=.o)

FLAGS = -Wall -Wextra -Werror
LINKS = -L./ft_printf/

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

$(NAME): $(OBJ) $(OBJ1) $(FT_PRINTF)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(FT_PRINTF) $(LINKS) -o $(NAME)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME1)..." $(NONE)
	@gcc $(FLAGS) $(OBJ1) $(FT_PRINTF) $(LINKS) -o $(NAME1)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ) $(OBJ1)
	$(MAKE) -C $(FT_PRINTF_PATH) clean
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(OBJ): $(SRC) $(FT_PRINTF)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)
$(OBJ1): $(SRC1) $(FT_PRINTF)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC1)

bonus: $(OBJB) $(OBJB1) $(FT_PRINTF)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJB) $(FT_PRINTF) $(LINKS) -o $(NAME)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME1)..." $(NONE)
	@gcc $(FLAGS) $(OBJB1) $(FT_PRINTF) $(LINKS) -o $(NAME1)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJB) $(OBJB1)
	$(MAKE) -C $(FT_PRINTF_PATH) clean
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"
clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ) $(OBJ1) $(OBJB) $(OBJB1)
	$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME) $(NAME1) $(NAMEB) $(NAMEB1)
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY:all clean fclean re
