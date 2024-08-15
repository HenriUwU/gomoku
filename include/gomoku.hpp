/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:34:20 by laprieur          #+#    #+#             */
/*   Updated: 2024/08/15 19:34:21 by laprieur         ###   ########.fr       */
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
#include <unordered_map>
#include <chrono>
#include <future>
#include <iomanip>

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

#include "MainMenu.hpp"
#include "Gameplay.hpp"
#include "CustomMenu.hpp"
#include "SettingsMenu.hpp"
#include "HelpMenu.hpp"
#include "Bitboard.hpp"
#include "AI.hpp"
#include "Music.hpp"

enum AIMode {
	IMPOSSIBLE,
	AGGRESSIVE,
	PASSIVE,
	DEFENSIVE,
	NOAIMODE
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

enum MoveSuggestion {
	ENABLED,
	DISABLED
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
extern bool										isStonePlaceable;
extern bool										startTimer;
extern AIMode									aiMode;
extern Avatar									playerOneAvatar;
extern GameState								gameState;
extern BoardColor								boardColor;
extern EndGameState								endGameState;
extern StonesColors								stonesColors;
extern HelpMenuState							helpMenuState;
extern MoveSuggestion							moveSuggestion;
extern ForbiddenMoves							forbiddenMoves;
extern std::chrono::steady_clock::time_point	gameStartTime;

void	loadTextures(int nbTextures, const std::string pathStart, const std::string prefixes[], std::vector<sf::Texture>& textures);
void	setTextures(int nbTextures, const std::vector<sf::Texture>& textures, std::vector<sf::Sprite>& sprites);
void	setPosition(int nbSprites, std::vector<sf::Sprite>& sprites, int x, int y, int offset);
void	setPosition(sf::Sprite& sprite, int x, int y);
void	setStatistics(std::vector<sf::Text>& stats, sf::Font& font, int player);