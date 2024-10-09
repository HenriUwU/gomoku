# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 14:32:27 by hsebille          #+#    #+#              #
#    Updated: 2024/10/09 17:03:48 by hsebille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= Gomoku

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

SRC				:=	src/main.cpp									\
					src/AI/AI.cpp									\
					src/AI/heuristic.cpp							\
					src/Graphics/GIF/AnimatedGIF.cpp				\
					src/Graphics/Game/Bitboard_captures.cpp			\
					src/Graphics/Game/Bitboard_double-three.cpp		\
					src/Graphics/Game/Bitboard_patterns.cpp			\
					src/Graphics/Game/Bitboard_utils.cpp			\
					src/Graphics/Game/Bitboard_victory.cpp			\
					src/Graphics/Game/Bitboard.cpp					\
					src/Graphics/Game/Gameplay.cpp					\
					src/Graphics/Menu/CustomMenu.cpp				\
					src/Graphics/Menu/HelpMenu.cpp					\
					src/Graphics/Menu/MainMenu.cpp					\
					src/Graphics/Menu/SettingsMenu.cpp				\
					src/Graphics/Utils.cpp							\
					src/Music/Music.cpp								\
					src/AI/AI_utils.cpp								\
					src/Graphics/Game/Bitboard_generate_moves.cpp	\
				
SRC_OBJS		:=	$(SRC:%.cpp=.build/%.o)
DEPS			:=	$(SRC_OBJS:%.o=%.d)

COMPILER		:=	g++
DEBUG_FLAGS		:=	-Wall -Wextra -Werror -g3 -Ofast -fopenmp -Wpedantic -lpthread
INCLUDE_FLAGS	:=	-Ilib/SFML/include -Iinclude -Iinclude/Graphics -Iinclude/Graphics/Game -Iinclude/Graphics/Menu -Iinclude/AI -Iinclude/Music -Ilib/stb -I$(HOME)/local/include
SFML_FLAGS		:=	-L$(HOME)/local/lib -Llib/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -latomic
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
	$(COMPILER) $(SRC_OBJS) $(DEBUG_FLAGS) $(INCLUDE_FLAGS) $(SFML_FLAGS) $(RPATH_FLAGS) -o $(NAME)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

.build/%.o: %.cpp
	mkdir -p $(@D)
	$(COMPILER) $(DEBUG_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@
	@printf "%b" "$(BLUE)CREATED $(CYAN)$@\n"

-include $(DEPS)

# deps: fclean
	# SFML
	# cd lib \
	# && wget -c https://www.sfml-dev.org/files/SFML-2.6.1-linux-gcc-64-bit.tar.gz \
	# && tar -xf SFML-2.6.1-linux-gcc-64-bit.tar.gz \
	# && mv SFML-2.6.1 SFML \
	# && rm -rf SFML-2.6.1-linux-gcc-64-bit.tar.gz
	# # FLAC
	# cd lib \
	# && wget -c https://github.com/xiph/flac/releases/download/1.4.3/flac-1.4.3.tar.xz \
	# && tar -xf flac-1.4.3.tar.xz \
	# && mv flac-1.4.3 FLAC \
	# && rm -rf flac-1.4.3.tar.xz \
	# && cd FLAC \
	# && mkdir build \
	# && cd build \
	# && cmake .. -DWITH_OGG=OFF \
	# && make \
	# && make install
	# # TBB
	# cd lib \
	# && wget -c https://github.com/oneapi-src/oneTBB/archive/refs/tags/v2021.13.0.tar.gz \
	# && tar -xf v2021.13.0.tar.gz \
	# && mv oneTBB-2021.13.0 oneTBB \
	# && rm -rf v2021.13.0.tar.gz \
	# && cd oneTBB \
	# && mkdir build \
	# && cd build \
	# && cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DTBB_TEST=OFF .. \
	# && cmake --build . \
	# && cmake --install .
	# # BENCHMARK
	# cd lib \
	# && wget -c https://github.com/google/benchmark/archive/refs/tags/v1.8.4.tar.gz \
	# && tar -xf v1.8.4.tar.gz \
	# && mv benchmark-1.8.4 benchmark \
	# && rm -rf v1.8.4.tar.gz \
	# && cd benchmark \
	# && mkdir build \
	# && cd build \
	# && cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON .. \
	# && cmake --build . \
	# && cmake --install .
	# # openal
	# cd lib \
	# && wget -c https://github.com/kcat/openal-soft/archive/refs/tags/1.23.1.tar.gz \
	# && tar -xf 1.23.1.tar.gz \
	# && mv openal-soft-1.23.1 openal \
	# && rm -rf 1.23.1.tar.gz \
	# && cd openal \
	# && cd build \
	# && cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. \
	# && cmake --build . \
	# && cmake --install .make LDFLAGS="-L/usr/lib/x86_64-linux-gnu/"

# depsclean:
# 	rm -rf ./lib/SFML
# 	rm -rf ./lib/FLAC
# 	rm -rf ./lib/oneTBB
# 	rm -rf ./lib/benchmark

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
