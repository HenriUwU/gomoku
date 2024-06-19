/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomMenu.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:14:13 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/19 11:32:19 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomMenu.hpp"

CustomMenu::CustomMenu() {
	init();
}

CustomMenu::~CustomMenu() {}

void	CustomMenu::display(sf::RenderWindow& window) {
	if (stonesColor == NOSTONECOLOR)
		_stoneSelectorSprite.setPosition(-100, -100);
	if (stonesColor == BlackAndWhite)
		_stoneSelectorSprite.setPosition(691 - 8, 379 - 8);
	if (stonesColor == BlackAndYellow)
		_stoneSelectorSprite.setPosition(971 - 8, 379 - 8);
	if (stonesColor == DarkGreenAndLightGreen)
		_stoneSelectorSprite.setPosition(1110 - 8, 379 - 8);
	if (stonesColor == GreenAndRed)
		_stoneSelectorSprite.setPosition(761 - 8, 379 - 8);
	if (stonesColor == OrangeAndViolet)
		_stoneSelectorSprite.setPosition(1041 - 8, 379 - 8);
	if (stonesColor == PinkAndFluoYellow)
		_stoneSelectorSprite.setPosition(901 - 8, 379 - 8);
	if (stonesColor == SalmonAndCoral)
		_stoneSelectorSprite.setPosition(831 - 8, 379 - 8);
	if (stonesColor == TurquoiseGreenAndIndigo)
		_stoneSelectorSprite.setPosition(1179 - 8, 379 - 8);

	if (boardColor == NOBOARD)
		_boardSelectorSprite.setPosition(-100, -100);
	if (boardColor == AZURE)
		_boardSelectorSprite.setPosition(691 - 8, 776 - 8);
	if (boardColor == BLACK)
		_boardSelectorSprite.setPosition(1179 - 8, 776 - 8);
	if (boardColor == GRAY)
		_boardSelectorSprite.setPosition(1110 - 8, 776 - 8);
	if (boardColor == GREEN)
		_boardSelectorSprite.setPosition(1041 - 8, 776 - 8);
	if (boardColor == ORANGE)
		_boardSelectorSprite.setPosition(901 - 8, 776 - 8);
	if (boardColor == PINK)
		_boardSelectorSprite.setPosition(971 - 8, 776 - 8);
	if (boardColor == RED)
		_boardSelectorSprite.setPosition(831 - 8, 776 - 8);
	if (boardColor == YELLOW)
		_boardSelectorSprite.setPosition(761 - 8, 776 - 8);

	if (playerOneAvatar == NOAVATAR)
		_avatarSelectorSprite.setPosition(-100, -100);
	if (playerOneAvatar == ALEX)
		_avatarSelectorSprite.setPosition(877 - 8, 563 - 8);
	if (playerOneAvatar == GUNTHER)
		_avatarSelectorSprite.setPosition(1154 - 8, 563 - 8);
	if (playerOneAvatar == HERIC)
		_avatarSelectorSprite.setPosition(970 - 8, 563 - 8);
	if (playerOneAvatar == LAURE)
		_avatarSelectorSprite.setPosition(784 - 8, 563 - 8);
	if (playerOneAvatar == MOUSSE)
		_avatarSelectorSprite.setPosition(1063 - 8, 563 - 8);
	if (playerOneAvatar == TOMMY)
		_avatarSelectorSprite.setPosition(691 - 8, 563 - 8);

	handleKeys(window);
	
	window.clear(sf::Color(38, 1, 69));
	window.draw(_customMenuSprite);
	window.draw(_backwardButtonSprite);
	window.draw(_stoneSelectorSprite);
	window.draw(_avatarSelectorSprite);
	window.draw(_boardSelectorSprite);
	
	window.draw(_blackWhiteStoneSprite);
	window.draw(_greenRedStoneSprite);
	window.draw(_salmonCoralStoneSprite);
	window.draw(_pinkFYellowStoneSprite);
	window.draw(_blackYellowStoneSprite);
	window.draw(_orangeVioletStoneSprite);
	window.draw(_dGreenLGreenStoneSprite);
	window.draw(_tGreenIndigoStoneSprite);
	
	window.draw(_tommyAvatarSprite);
	window.draw(_laureAvatarSprite);
	window.draw(_alexAvatarSprite);
	window.draw(_hericAvatarSprite);
	window.draw(_mousseAvatarSprite);
	window.draw(_guntherAvatarSprite);

	window.draw(_azureBoardSprite);
	window.draw(_yellowBoardSprite);
	window.draw(_redBoardSprite);
	window.draw(_orangeBoardSprite);
	window.draw(_pinkBoardSprite);
	window.draw(_greenBoardSprite);
	window.draw(_grayBoardSprite);
	window.draw(_blackBoardSprite);

}

void	CustomMenu::handleKeys(sf::RenderWindow &window) {
	if (_backwardButtonSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		_backwardButtonSprite.setTexture(_backwardHoveredButtonTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			gameState = MENU;
	} else
		_backwardButtonSprite.setTexture(_backwardButtonTexture);

	handleStonesSelection(window);
	handleBoardSelection(window);
	handleAvatarsSelection(window);
}

void	CustomMenu::handleStonesSelection(sf::RenderWindow& window) {
	if (_blackWhiteStoneSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stoneSelectorSprite.setPosition(691 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = BlackAndWhite;
	} else if (_blackYellowStoneSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stoneSelectorSprite.setPosition(971 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = BlackAndYellow;
	} else if (_dGreenLGreenStoneSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stoneSelectorSprite.setPosition(1110 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = DarkGreenAndLightGreen;
	} else if (_greenRedStoneSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stoneSelectorSprite.setPosition(761 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = GreenAndRed;
	} else if (_orangeVioletStoneSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stoneSelectorSprite.setPosition(1041 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = OrangeAndViolet;
	} else if (_pinkFYellowStoneSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stoneSelectorSprite.setPosition(901 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = PinkAndFluoYellow;
	} else if (_salmonCoralStoneSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stoneSelectorSprite.setPosition(831 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = SalmonAndCoral;
	} else if (_tGreenIndigoStoneSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stoneSelectorSprite.setPosition(1179 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = TurquoiseGreenAndIndigo;
	} else if (stonesColor == NOSTONECOLOR)
			_stoneSelectorSprite.setPosition(-100, -100);
}

void	CustomMenu::handleAvatarsSelection(sf::RenderWindow& window) {
	if (_alexAvatarSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(877 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = ALEX;
	} else if (_guntherAvatarSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(1154 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = GUNTHER;
	} else if (_hericAvatarSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(970 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = HERIC;
	} else if (_laureAvatarSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(784 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = LAURE;
	} else if (_mousseAvatarSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(1063 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = MOUSSE;
	} else if (_tommyAvatarSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(691 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = TOMMY;
	} else if (playerOneAvatar == NOAVATAR)
			_avatarSelectorSprite.setPosition(-100, -100);
}

void	CustomMenu::handleBoardSelection(sf::RenderWindow& window) {
	if (_azureBoardSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(691 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = AZURE;
	} else if (_blackBoardSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(1179 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = BLACK;
	} else if (_grayBoardSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(1110 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = GRAY;
	} else if (_greenBoardSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(1041 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = GREEN;
	} else if (_orangeBoardSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(901 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = ORANGE;
	} else if (_pinkBoardSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(971 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = PINK;
	} else if (_redBoardSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(831 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = RED;
	} else if (_yellowBoardSprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(761 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = YELLOW;
	} else if (boardColor == NOBOARD)
			_boardSelectorSprite.setPosition(-100, -100);
}

void	CustomMenu::init() {
	if (!_customMenuTexture.loadFromFile("assets/customMenu/Custom_Gomoku.png"))
		std::cerr << "Error: could not load custom page texture" << std::endl;
	if (!_backwardButtonTexture.loadFromFile("assets/images/buttons/return_arrow.png"))
		std::cerr << "Error: could not load return button texture" << std::endl;
	if (!_backwardHoveredButtonTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png"))
		std::cerr << "Error: could not load return button highlighted texture" << std::endl;
	if (!_colorSelectorTexture.loadFromFile("assets/images/icons/selector.png"))
		std::cerr << "Error: could not load selection halo texture" << std::endl;
	if (!_avatarSelectorTexture.loadFromFile("assets/images/icons/avatar_selector.png"))
		std::cerr << "Error: could not load avatar selector texture" << std::endl;
	if (!_blackWhiteStoneTexture.loadFromFile("assets/images/stoneSelection/B&W.png"))
		std::cerr << "Error: could not load stone color B&W texture" << std::endl;
	if (!_greenRedStoneTexture.loadFromFile("assets/images/stoneSelection/G&R.png"))
		std::cerr << "Error: could not load stone color G&R texture" << std::endl;
	if (!_salmonCoralStoneTexture.loadFromFile("assets/images/stoneSelection/S&C.png"))
		std::cerr << "Error: could not load stone color S&C texture" << std::endl;
	if (!_pinkFYellowStoneTexture.loadFromFile("assets/images/stoneSelection/P&FY.png"))
		std::cerr << "Error: could not load stone color P&FY texture" << std::endl;
	if (!_blackYellowStoneTexture.loadFromFile("assets/images/stoneSelection/B&Y.png"))
		std::cerr << "Error: could not load stone color B&Y texture" << std::endl;
	if (!_orangeVioletStoneTexture.loadFromFile("assets/images/stoneSelection/O&V.png"))
		std::cerr << "Error: could not load stone color O&V texture" << std::endl;
	if (!_dGreenLGreenStoneTexture.loadFromFile("assets/images/stoneSelection/DG&LG.png"))
		std::cerr << "Error: could not load stone color DG&LG texture" << std::endl;
	if (!_tGreenIndigoStoneTexture.loadFromFile("assets/images/stoneSelection/TG&I.png"))
		std::cerr << "Error: could not load stone color TG&I texture" << std::endl;
	if (!_tommyAvatarTexture.loadFromFile("assets/images/avatarSelection/Tommy.png"))
		std::cerr << "Error: could not load avatar tommy texture" << std::endl;
	if (!_laureAvatarTexture.loadFromFile("assets/images/avatarSelection/Laure.png"))
		std::cerr << "Error: could not load avatar laure texture" << std::endl;
	if (!_alexAvatarTexture.loadFromFile("assets/images/avatarSelection/Alex.png"))
		std::cerr << "Error: could not load avatar alex texture" << std::endl;
	if (!_hericAvatarTexture.loadFromFile("assets/images/avatarSelection/Heric.png"))
		std::cerr << "Error: could not load avatar heric texture" << std::endl;
	if (!_mousseAvatarTexture.loadFromFile("assets/images/avatarSelection/Mousse.png"))
		std::cerr << "Error: could not load avatar mousse texture" << std::endl;
	if (!_guntherAvatarTexture.loadFromFile("assets/images/avatarSelection/Gunther.png"))
		std::cerr << "Error: could not load avatar gunther texture" << std::endl;
	if (!_azureBoardTexture.loadFromFile("assets/images/boardSelection/Azure.png"))
		std::cerr << "Error: could not load board color azure texture" << std::endl;
	if (!_yellowBoardTexture.loadFromFile("assets/images/boardSelection/Yellow.png"))
		std::cerr << "Error: could not load board color yellow texture" << std::endl;
	if (!_redBoardTexture.loadFromFile("assets/images/boardSelection/Red.png"))
		std::cerr << "Error: could not load board color red texture" << std::endl;
	if (!_orangeBoardTexture.loadFromFile("assets/images/boardSelection/Orange.png"))
		std::cerr << "Error: could not load board color orange texture" << std::endl;
	if (!_pinkBoardTexture.loadFromFile("assets/images/boardSelection/Pink.png"))
		std::cerr << "Error: could not load board color pink texture" << std::endl;
	if (!_greenBoardTexture.loadFromFile("assets/images/boardSelection/Green.png"))
		std::cerr << "Error: could not load board color green texture" << std::endl;
	if (!_grayBoardTexture.loadFromFile("assets/images/boardSelection/Gray.png"))
		std::cerr << "Error: could not load board color gray texture" << std::endl;
	if (!_blackBoardTexture.loadFromFile("assets/images/boardSelection/Black.png"))
		std::cerr << "Error: could not load board color black texture" << std::endl;

	_customMenuSprite.setTexture(_customMenuTexture);
	_backwardButtonSprite.setTexture(_backwardButtonTexture);
	_stoneSelectorSprite.setTexture(_colorSelectorTexture);
	_avatarSelectorSprite.setTexture(_avatarSelectorTexture);
	_boardSelectorSprite.setTexture(_colorSelectorTexture);

	_blackWhiteStoneSprite.setTexture(_blackWhiteStoneTexture);
	_greenRedStoneSprite.setTexture(_greenRedStoneTexture);
	_salmonCoralStoneSprite.setTexture(_salmonCoralStoneTexture);
	_pinkFYellowStoneSprite.setTexture(_pinkFYellowStoneTexture);
	_blackYellowStoneSprite.setTexture(_blackYellowStoneTexture);
	_orangeVioletStoneSprite.setTexture(_orangeVioletStoneTexture);
	_dGreenLGreenStoneSprite.setTexture(_dGreenLGreenStoneTexture);
	_tGreenIndigoStoneSprite.setTexture(_tGreenIndigoStoneTexture);
	
	_tommyAvatarSprite.setTexture(_tommyAvatarTexture);
	_laureAvatarSprite.setTexture(_laureAvatarTexture);
	_alexAvatarSprite.setTexture(_alexAvatarTexture);
	_mousseAvatarSprite.setTexture(_mousseAvatarTexture);
	_hericAvatarSprite.setTexture(_hericAvatarTexture);
	_guntherAvatarSprite.setTexture(_guntherAvatarTexture);

	_azureBoardSprite.setTexture(_azureBoardTexture);
	_yellowBoardSprite.setTexture(_yellowBoardTexture);
	_redBoardSprite.setTexture(_redBoardTexture);
	_orangeBoardSprite.setTexture(_orangeBoardTexture);
	_pinkBoardSprite.setTexture(_pinkBoardTexture);
	_greenBoardSprite.setTexture(_greenBoardTexture);
	_grayBoardSprite.setTexture(_grayBoardTexture);
	_blackBoardSprite.setTexture(_blackBoardTexture);
	
	_backwardButtonSprite.setPosition(100, 100);
	
	_blackWhiteStoneSprite.setPosition(691, 379);
	_greenRedStoneSprite.setPosition(761, 379);
	_salmonCoralStoneSprite.setPosition(831, 379);
	_pinkFYellowStoneSprite.setPosition(901, 379);
	_blackYellowStoneSprite.setPosition(971, 379);
	_orangeVioletStoneSprite.setPosition(1041, 379);
	_dGreenLGreenStoneSprite.setPosition(1110, 379);
	_tGreenIndigoStoneSprite.setPosition(1179, 379);

	_alexAvatarSprite.setPosition(877, 563);
	_guntherAvatarSprite.setPosition(1154, 563);
	_hericAvatarSprite.setPosition(970, 563);
	_laureAvatarSprite.setPosition(784, 563);
	_mousseAvatarSprite.setPosition(1063, 563);
	_tommyAvatarSprite.setPosition(691, 563);
	
	_azureBoardSprite.setPosition(691, 776);
	_yellowBoardSprite.setPosition(761, 776);
	_redBoardSprite.setPosition(831, 776);
	_orangeBoardSprite.setPosition(901, 776);
	_pinkBoardSprite.setPosition(971, 776);
	_greenBoardSprite.setPosition(1041, 776);
	_grayBoardSprite.setPosition(1110, 776);
	_blackBoardSprite.setPosition(1179, 776);
}
