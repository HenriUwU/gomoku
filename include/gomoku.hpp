/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:37:22 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/13 14:26:27 by hsebille         ###   ########.fr       */
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

#include "Graphics.hpp"
#include "MainMenu.hpp"
#include "Gameplay.hpp"
#include "Goban.hpp"
#include "Debug.hpp"

extern bool	displayMenu;
extern bool	displayGame;
extern bool	displayHelp;