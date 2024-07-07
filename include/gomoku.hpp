/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:37:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/07 17:51:23 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <bitset>
#include <limits.h>
#include <unordered_set>

#include "MainMenu.hpp"
#include "Gameplay.hpp"
#include "Goban.hpp"
#include "CustomMenu.hpp"
#include "SettingsMenu.hpp"
#include "HelpMenu.hpp"
#include "Bitboard.hpp"
#include "AI.hpp"

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
	VS_IA,
	CUSTOM,
	HELP,
	SETTINGS
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
	BLACKANDWHITE,
	GREENANDRED,
	SALMONANDCORAL,
	PINKANDFLUOYELLOW,
	BLACKANDYELLOW,
	ORANGEANDVIOLET,
	DARKGREENANDLIGHTGREEN,
	TURQUOISEGREENANDINDIGO,
	NOSTONESCOLORS
};

extern sf::Sound		sound;
extern int				musicVolume;
extern AIMode			aiMode;
extern Avatar			playerOneAvatar;
extern Avatar			playerTwoAvatar;
extern BoardColor		boardColor;
extern GameState		gameState;
extern HelpMenuState	helpMenuState;
extern MoveSuggestion	moveSuggestion;
extern StonesColors		stonesColors;