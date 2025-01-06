# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 14:32:27 by hsebille          #+#    #+#              #
#    Updated: 2024/11/11 19:31:48 by hsebille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= Gomoku

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

SRC				:=	src/main.cpp								\
					src/AI/AI.cpp								\
					src/AI/heuristic.cpp						\
					src/AI/AIUtils.cpp							\
					src/Graphics/GIF/AnimatedGIF.cpp			\
					src/Bitboard/BitboardCaptures.cpp			\
					src/Bitboard/BitboardPatterns.cpp			\
					src/Bitboard/BitboardUtils.cpp				\
					src/Bitboard/BitboardRules.cpp				\
					src/Bitboard/BitboardGenerateMoves.cpp		\
					src/Bitboard/Bitboard.cpp					\
					src/Game/Gameplay.cpp						\
					src/Game/GameplayUtils.cpp					\
					src/Graphics/Menu/CustomMenu.cpp			\
					src/Graphics/Menu/HelpMenu.cpp				\
					src/Graphics/Menu/MainMenu.cpp				\
					src/Graphics/Menu/SettingsMenu.cpp			\
					src/Graphics/Utils.cpp						\
					src/Music/Music.cpp							\
				
SRC_OBJS		:=	$(SRC:%.cpp=.build/%.o)
DEPS			:=	$(SRC_OBJS:%.o=%.d)

COMPILER		:=	g++
DEBUG_FLAGS		:=	-Wall -Wextra -Werror -Ofast -fopenmp -Wpedantic -lpthread
INCLUDE_FLAGS	:=	-Ilib/SFML/include -Iinclude -Iinclude/Game -Iinclude/Graphics -Iinclude/Graphics/Menu -Iinclude/AI -Iinclude/Music -Iinclude/Bitboard -Ilib/stb -I$(HOME)/local/include
SFML_FLAGS		:=	-L$(HOME)/local/lib -Llib/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -latomic
RPATH_FLAGS		:=	-Wl,-rpath,'$$ORIGIN/lib/SFML/lib'

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory -j8

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: header $(NAME)

$(NAME): $(SRC_OBJS)
	$(COMPILER) $(SRC_OBJS) $(DEBUG_FLAGS) $(INCLUDE_FLAGS) $(SFML_FLAGS) $(RPATH_FLAGS) -o $(NAME)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.cpp
	mkdir -p $(@D)
	$(COMPILER) $(DEBUG_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@
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
	@printf "%b" "$(GREEN)"
	@echo "																"
	@echo "    ██████╗  ██████╗ ███╗   ███╗ ██████╗ ██╗  ██╗██╗   ██╗	"
	@echo "   ██╔════╝ ██╔═══██╗████╗ ████║██╔═══██╗██║ ██╔╝██║   ██║	"
	@echo "   ██║  ███╗██║   ██║██╔████╔██║██║   ██║█████╔╝ ██║   ██║	"
	@echo "   ██║   ██║██║   ██║██║╚██╔╝██║██║   ██║██╔═██╗ ██║   ██║	"
	@echo "   ╚██████╔╝╚██████╔╝██║ ╚═╝ ██║╚██████╔╝██║  ██╗╚██████╔╝	"
	@echo "    ╚═════╝  ╚═════╝ ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝ ╚═════╝	"
	@echo "    by hsebille and laprieur									"
	@echo
	@printf "%b" "$(CYAN)COMPILER:	$(YELLOW)$(COMPILER)\n"
	@printf "%b" "$(CYAN)DEBUG_FLAGS:	$(YELLOW)$(DEBUG_FLAGS)\n"
	@printf "%b" "$(CYAN)INCLUDE_FLAGS:	$(YELLOW)$(INCLUDE_FLAGS)\n"
	@printf "%b" "$(CYAN)SFML_FLAGS:	$(YELLOW)$(SFML_FLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
