/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:34:20 by laprieur          #+#    #+#             */
/*   Updated: 2024/12/21 16:39:46 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <bitset>
#include <limits.h>
#include <unordered_set>
#include <atomic>
#include <thread>
#include <memory>
#include <unordered_map>
#include <chrono>
#include <future>
#include <iomanip>
#include <queue>
#include <random>

struct PatternInfo {
	uint32_t	pattern;
	uint32_t	opponentPattern;
	int			patternSize;
	int			playerType;
	int			multiplier;
};

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &pair) const {
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

#include "AI/AI.hpp"
#include "Graphics/GIF/AnimatedGIF.hpp"
#include "Bitboard/Bitboard.hpp"
#include "Game/Gameplay.hpp"
#include "Graphics/Menu/MainMenu.hpp"
#include "Graphics/Menu/CustomMenu.hpp"
#include "Graphics/Menu/SettingsMenu.hpp"
#include "Graphics/Menu/HelpMenu.hpp"
#include "Music/Music.hpp"

enum AIMode {
	IMPOSSIBLE,
	CHALLENGING,
	CRAZY,
	EASY
};

enum Avatar {
	TOMMY,
	LAURE,
	ALEX,
	HERIC,
	MOUSSE,
	GUNTHER,
	NOAVATAR
};

enum BoardColor {
	AZURE,
	YELLOW,
	RED,
	ORANGE,
	PINK,
	GREEN,
	GRAY,
	BLACK,
	NOBOARD
};

enum GameState {
	MENU,
	GAME,
	AIVERSUS,
	CUSTOM,
	HELP,
	SETTINGS,
	NONE
};

enum HelpMenuState {
	RULES,
	CAPTURES,
	DOUBLETHREE
};

enum StonesColors {
	BLACK_WHITE,
	GREEN_RED,
	SALMON_CORAL,
	PINK_FLUOYELLOW,
	BLACK_YELLOW,
	ORANGE_VIOLET,
	DARKGREEN_LIGHTGREEN,
	TURQUOISEGREEN_INDIGO,
	NOSTONESCOLORS
};

enum ForbiddenMoves {
	DOUBLE_THREE,
	NOFORBIDDENMOVE
};

enum EndGameState {
	P1VICTORY,
	P2VICTORY,
	AIVICTORY,
	SEEGAMESTATE,
	NOVICTORY
};

extern int										musicVolume;
extern int										playersCaptures[2];
extern bool										aiPlaying;
extern bool										startTimer;
extern bool										moveSuggestionEnabled;
extern AIMode									aiMode;
extern Avatar									playerOneAvatar;
extern GameState								gameState;
extern BoardColor								boardColor;
extern EndGameState								endGameState;
extern StonesColors								stonesColors;
extern HelpMenuState							helpMenuState;
extern ForbiddenMoves							forbiddenMoves;
extern std::chrono::steady_clock::time_point	gameStartTime;

void	loadTextures(int nbTextures, const std::string pathStart, const std::string prefixes[], std::vector<sf::Texture>& textures);
void	setTextures(int nbTextures, const std::vector<sf::Texture>& textures, std::vector<sf::Sprite>& sprites);
void	setPosition(int nbSprites, std::vector<sf::Sprite>& sprites, int x, int y, int offset);
void	setPosition(sf::Sprite& sprite, int x, int y);
void	setStatistics(std::vector<sf::Text>& stats, sf::Font& font, int player);