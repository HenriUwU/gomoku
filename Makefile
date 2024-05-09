# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 15:50:59 by hsebille          #+#    #+#              #
#    Updated: 2024/05/08 14:34:14 by hsebille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= Gomoku

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

SRC				:=	src/main.cpp				\
					src/MainMenu.cpp			\
					
SRC_OBJS		:=	$(SRC:%.cpp=.build/%.o)
DEPS			:=	$(SRC_OBJS:%.o=%.d)

COMPILER		:=	g++
DEBUG_FLAGS		:=	-Wall -Wextra -Werror -g -MMD -Iinclude
SFML_FLAGS		:=	-lsfml-graphics -lsfml-window -lsfml-system

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: header $(NAME)

$(NAME): $(SRC_OBJS)
	$(COMPILER) $(SRC_OBJS) $(DEBUG_FLAGS) $(SFML_FLAGS) -o $(NAME)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.cpp
	mkdir -p $(@D)
	$(COMPILER) $(DEBUG_FLAGS) $(SFML_FLAGS) -c $< -o $@
	@printf "%b" "$(BLUE)CREATED $(CYAN)$@\n"

-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
CYAN			:= \033[0;36m
OFF				:= \033[m

header:
	@printf "%b" "$(GREEN))"
	@echo "██████╗  ██████╗ ███╗   ███╗ ██████╗ ██╗  ██╗██╗   ██╗"
	@echo "██╔════╝ ██╔═══██╗████╗ ████║██╔═══██╗██║ ██╔╝██║   ██║"
	@echo "██║  ███╗██║   ██║██╔████╔██║██║   ██║█████╔╝ ██║   ██║"
	@echo "██║   ██║██║   ██║██║╚██╔╝██║██║   ██║██╔═██╗ ██║   ██║"
	@echo "╚██████╔╝╚██████╔╝██║ ╚═╝ ██║╚██████╔╝██║  ██╗╚██████╔╝"
	@echo " ╚═════╝  ╚═════╝ ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ "
	@echo "                                                       "
	@echo "	by hsebille and laprieur"
	@echo
	@printf "%b" "$(CYAN)COMPILER:      $(YELLOW)$(COMPILER)\n"
	@printf "%b" "$(CYAN)DEBUG_FLAGS: $(YELLOW)$(DEBUG_FLAGS)\n"
	@printf "%b" "$(CYAN)SFML_FLAGS: $(YELLOW)$(SFML_FLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re
.DELETE_ON_ERROR: