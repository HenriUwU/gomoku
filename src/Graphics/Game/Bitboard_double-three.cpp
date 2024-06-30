/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bitboard_double-three.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:41:03 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/30 14:11:11 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitboard.hpp"

bool	Bitboard::isDoubleThree(int x, int y, int player) {
	int	nbFreeThree = 0;
	(void)x;
	(void)y;
	(void)player;
	
	
	if (nbFreeThree >= 2)
		return (true);
	return (false);
}

/* void	Bitboard::verifyFreeThreeHorizontal(int &nbFreeThree, int x, int y, int player) {
	uint32_t	bitSelection();
} */
