# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 12:49:41 by hsebille          #+#    #+#              #
#    Updated: 2024/07/08 17:41:44 by hsebille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= Gomoku

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

SRC				:=	src/main.cpp								\
					src/AI/AI.cpp								\
					src/AI/heuristic.cpp						\
					src/Graphics/Game/Bitboard_captures.cpp		\
					src/Graphics/Game/Bitboard_double-three.cpp	\
					src/Graphics/Game/Bitboard_patterns.cpp		\
					src/Graphics/Game/Bitboard_utils.cpp		\
					src/Graphics/Game/Bitboard_victory.cpp		\
					src/Graphics/Game/Bitboard.cpp				\
					src/Graphics/Game/Gameplay.cpp				\
					src/Graphics/Game/Goban.cpp					\
					src/Graphics/Menu/CustomMenu.cpp			\
					src/Graphics/Menu/HelpMenu.cpp				\
					src/Graphics/Menu/MainMenu.cpp				\
					src/Graphics/Menu/SettingsMenu.cpp			\
					
SRC_OBJS		:=	$(SRC:%.cpp=.build/%.o)
DEPS			:=	$(SRC_OBJS:%.o=%.d)

COMPILER		:=	g++
DEBUG_FLAGS		:=	-Wall -Wextra -Werror -g3 -Ofast -Wpedantic -pg -Ilib/SFML/include -Iinclude -Iinclude/Graphics -Iinclude/Graphics/Game -Iinclude/Graphics/Menu -Iinclude/AI -Ilib/stb -I$(HOME)/local/include
SFML_FLAGS		:=	-L$(HOME)/local/lib -Llib/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lFLAC
RPATH_FLAGS		:=	-Wl,-rpath,'$$ORIGIN/lib/SFML/lib'

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: header $(NAME)

$(NAME): $(SRC_OBJS)
	$(COMPILER) $(SRC_OBJS) $(DEBUG_FLAGS) $(SFML_FLAGS) $(RPATH_FLAGS) -o $(NAME)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.cpp
	mkdir -p $(@D)
	$(COMPILER) $(DEBUG_FLAGS) -c $< -o $@
	@printf "%b" "$(BLUE)CREATED $(CYAN)$@\n"

-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
	
flac-script:
	bash lib/flac_script.sh

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
CYAN			:= \033[0;36m
OFF				:= \033[m

header:
	@printf "%b" "$(GREEN)"
	@echo " ██████╗  ██████╗ ███╗   ███╗ ██████╗ ██╗  ██╗██╗   ██╗"
	@echo "██╔════╝ ██╔═══██╗████╗ ████║██╔═══██╗██║ ██╔╝██║   ██║"
	@echo "██║  ███╗██║   ██║██╔████╔██║██║   ██║█████╔╝ ██║   ██║"
	@echo "██║   ██║██║   ██║██║╚██╔╝██║██║   ██║██╔═██╗ ██║   ██║"
	@echo "╚██████╔╝╚██████╔╝██║ ╚═╝ ██║╚██████╔╝██║  ██╗╚██████╔╝"
	@echo " ╚═════╝  ╚═════╝ ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ "
	@echo "                                                       "
	@echo "	by hsebille and laprieur"
	@echo
	@printf "%b" "$(CYAN)COMPILER:	$(YELLOW)$(COMPILER)\n"
	@printf "%b" "$(CYAN)DEBUG_FLAGS:	$(YELLOW)$(DEBUG_FLAGS)\n"
	@printf "%b" "$(CYAN)SFML_FLAGS:	$(YELLOW)$(SFML_FLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
