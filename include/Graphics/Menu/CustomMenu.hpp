/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomMenu.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:14:18 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/19 11:25:20 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class CustomMenu {
	private:
		sf::Texture		_customMenuTexture;
		sf::Texture		_backwardButtonTexture;
		sf::Texture		_backwardHoveredButtonTexture;
		sf::Texture		_colorSelectorTexture;
		sf::Texture		_avatarSelectorTexture;
		sf::Texture		_blackWhiteStoneTexture;
		sf::Texture		_greenRedStoneTexture;
		sf::Texture		_salmonCoralStoneTexture;
		sf::Texture		_pinkFYellowStoneTexture;
		sf::Texture		_blackYellowStoneTexture;
		sf::Texture		_orangeVioletStoneTexture;
		sf::Texture		_dGreenLGreenStoneTexture;
		sf::Texture		_tGreenIndigoStoneTexture;
		sf::Texture		_tommyAvatarTexture;
		sf::Texture		_laureAvatarTexture;
		sf::Texture		_alexAvatarTexture;
		sf::Texture		_hericAvatarTexture;
		sf::Texture		_mousseAvatarTexture;
		sf::Texture		_guntherAvatarTexture;
		sf::Texture		_azureBoardTexture;
		sf::Texture		_yellowBoardTexture;
		sf::Texture		_redBoardTexture;
		sf::Texture		_orangeBoardTexture;
		sf::Texture		_pinkBoardTexture;
		sf::Texture		_greenBoardTexture;
		sf::Texture		_grayBoardTexture;
		sf::Texture		_blackBoardTexture;
		sf::Sprite		_customMenuSprite;
		sf::Sprite		_backwardButtonSprite;
		sf::Sprite		_stoneSelectorSprite;
		sf::Sprite		_avatarSelectorSprite;
		sf::Sprite		_boardSelectorSprite;
		sf::Sprite		_blackWhiteStoneSprite;
		sf::Sprite		_greenRedStoneSprite;
		sf::Sprite		_salmonCoralStoneSprite;
		sf::Sprite		_pinkFYellowStoneSprite;
		sf::Sprite		_blackYellowStoneSprite;
		sf::Sprite		_orangeVioletStoneSprite;
		sf::Sprite		_dGreenLGreenStoneSprite;
		sf::Sprite		_tGreenIndigoStoneSprite;
		sf::Sprite		_tommyAvatarSprite;
		sf::Sprite		_laureAvatarSprite;
		sf::Sprite		_alexAvatarSprite;
		sf::Sprite		_hericAvatarSprite;
		sf::Sprite		_mousseAvatarSprite;
		sf::Sprite		_guntherAvatarSprite;
		sf::Sprite		_azureBoardSprite;
		sf::Sprite		_yellowBoardSprite;
		sf::Sprite		_redBoardSprite;
		sf::Sprite		_orangeBoardSprite;
		sf::Sprite		_pinkBoardSprite;
		sf::Sprite		_greenBoardSprite;
		sf::Sprite		_grayBoardSprite;
		sf::Sprite		_blackBoardSprite;
		

	public:
		CustomMenu();
		~CustomMenu();

		void	init();
		void	display(sf::RenderWindow& window);
		void	handleKeys(sf::RenderWindow& window);
		void	handleStonesSelection(sf::RenderWindow& window);
		void	handleBoardSelection(sf::RenderWindow& window);
		void	handleAvatarsSelection(sf::RenderWindow& window);
};