/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitboardVictory.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:39:41 by hsebille          #+#    #+#             */
/*   Updated: 2025/01/05 13:35:27 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool	Bitboard::fiveInARow() {
	PatternInfo playerOnePattern[] = {0b11111, 0b00000, 5, 1, 1};
	PatternInfo playerTwoPattern[] = {0b11111, 0b00000, 5, 2, 1};

	return (evaluatePatterns(playerOnePattern, 1) || evaluatePatterns(playerTwoPattern, 1));
}