/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:37:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/30 15:43:21 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <bitset>

#include "MainMenu.hpp"
#include "Gameplay.hpp"
#include "Goban.hpp"
#include "Debug.hpp"
#include "CustomMenu.hpp"
#include "SettingsMenu.hpp"
#include "HelpMenu.hpp"
#include "AnimatedGIF.hpp"
#include "Bitboard.hpp"

typedef enum {
	MENU,
	GAME,
	VS_IA,
	CUSTOM,
	HELP,
	SETTINGS,
} GameState;

typedef enum {
	NOBOARD,
	AZURE,
	YELLOW,
	RED,
	ORANGE,
	PINK,
	GREEN,
	GRAY,
	BLACK,
} BoardColor;

typedef enum {
	NOAVATAR,
	TOMMY,
	LAURE,
	ALEX,
	HERIC,
	MOUSSE,
	GUNTHER,
} Avatar;

typedef enum {
	NOSTONECOLOR,
	BlackAndWhite,
	GreenAndRed,
	SalmonAndCoral,
	PinkAndFluoYellow,
	BlackAndYellow,
	OrangeAndViolet,
	DarkGreenAndLightGreen,
	TurquoiseGreenAndIndigo,
} StonesColors;

typedef enum {
	ENABLED,
	DISABLED,
} MoveSuggestion;

typedef enum {
	NOAIMODE,
	IMPOSSIBLE,
	AGGRESSIVE,
	PASSIVE,
	DEFENSIVE,
} AIMode;

typedef enum {
	RULES,
	CAPTURES,
	DOUBLETHREE,
} HelpMenuState;

extern GameState		gameState;
extern BoardColor		boardColor;
extern Avatar			playerOneAvatar;
extern Avatar			playerTwoAvatar;
extern StonesColors		stonesColor;
extern MoveSuggestion	moveSuggestion;
extern AIMode			aiMode;
extern HelpMenuState	helpMenuState;