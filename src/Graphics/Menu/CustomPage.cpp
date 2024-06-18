/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomPage.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:33:47 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/18 21:15:32 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomPage.hpp"

CustomPage::CustomPage() {
	customPageInit();
}

CustomPage::~CustomPage() {}

void	CustomPage::display(sf::RenderWindow& window) {
	if (stonesColor == NOSTONECOLOR)
		_stonesSelection.setPosition(-100, -100);
	if (stonesColor == BlackAndWhite)
		_stonesSelection.setPosition(691 - 8, 379 - 8);
	if (stonesColor == BlackAndYellow)
		_stonesSelection.setPosition(971 - 8, 379 - 8);
	if (stonesColor == DarkGreenAndLightGreen)
		_stonesSelection.setPosition(1110 - 8, 379 - 8);
	if (stonesColor == GreenAndRed)
		_stonesSelection.setPosition(761 - 8, 379 - 8);
	if (stonesColor == OrangeAndViolet)
		_stonesSelection.setPosition(1041 - 8, 379 - 8);
	if (stonesColor == PinkAndFluoYellow)
		_stonesSelection.setPosition(901 - 8, 379 - 8);
	if (stonesColor == SalmonAndCoral)
		_stonesSelection.setPosition(831 - 8, 379 - 8);
	if (stonesColor == TurquoiseGreenAndIndigo)
		_stonesSelection.setPosition(1179 - 8, 379 - 8);

	if (boardColor == NOBOARD)
		_boardSelection.setPosition(-100, -100);
	if (boardColor == AZURE)
		_boardSelection.setPosition(691 - 8, 776 - 8);
	if (boardColor == BLACK)
		_boardSelection.setPosition(1179 - 8, 776 - 8);
	if (boardColor == GRAY)
		_boardSelection.setPosition(1110 - 8, 776 - 8);
	if (boardColor == GREEN)
		_boardSelection.setPosition(1041 - 8, 776 - 8);
	if (boardColor == ORANGE)
		_boardSelection.setPosition(901 - 8, 776 - 8);
	if (boardColor == PINK)
		_boardSelection.setPosition(971 - 8, 776 - 8);
	if (boardColor == RED)
		_boardSelection.setPosition(831 - 8, 776 - 8);
	if (boardColor == YELLOW)
		_boardSelection.setPosition(761 - 8, 776 - 8);

	if (playerOneAvatar == NOAVATAR)
		_avatarsSelection.setPosition(-100, -100);
	if (playerOneAvatar == ALEX)
		_avatarsSelection.setPosition(877 - 8, 563 - 8);
	if (playerOneAvatar == GUNTHER)
		_avatarsSelection.setPosition(1154 - 8, 563 - 8);
	if (playerOneAvatar == HERIC)
		_avatarsSelection.setPosition(970 - 8, 563 - 8);
	if (playerOneAvatar == LAURE)
		_avatarsSelection.setPosition(784 - 8, 563 - 8);
	if (playerOneAvatar == MOUSSE)
		_avatarsSelection.setPosition(1063 - 8, 563 - 8);
	if (playerOneAvatar == TOMMY)
		_avatarsSelection.setPosition(691 - 8, 563 - 8);

	handleKeys(window);
	
	window.clear(sf::Color(38, 1, 69));
	window.draw(_customPage);
	window.draw(_stoneColorBandW);
	window.draw(_stoneColorBandY);
	window.draw(_stoneColorDGandLG);
	window.draw(_stoneColorGandR);
	window.draw(_stoneColorOandV);
	window.draw(_stoneColorPandFY);
	window.draw(_stoneColorSandC);
	window.draw(_stoneColorTGandI);

	window.draw(_boardColorAzure);
	window.draw(_boardColorBlack);
	window.draw(_boardColorGray);
	window.draw(_boardColorGreen);
	window.draw(_boardColorOrange);
	window.draw(_boardColorPink);
	window.draw(_boardColorRed);
	window.draw(_boardColorYellow);

	window.draw(_avatarAlex);
	window.draw(_avatarGunther);
	window.draw(_avatarHeric);
	window.draw(_avatarLaure);
	window.draw(_avatarMousse);
	window.draw(_avatarTommy);

	window.draw(_returnButton);
	window.draw(_stonesSelection);
	window.draw(_boardSelection);
	window.draw(_avatarsSelection);
}

void	CustomPage::handleKeys(sf::RenderWindow &window) {
	if (_returnButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		_returnButton.setTexture(_returnButtonHighlightedTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			gameState = MENU;
	}
	else {
		_returnButton.setTexture(_returnButtonTexture);
	}
	handleStonesSelection(window);
	handleBoardSelection(window);
	handleAvatarsSelection(window);
}

void	CustomPage::handleStonesSelection(sf::RenderWindow& window) {
	if (_stoneColorBandW.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stonesSelection.setPosition(691 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = BlackAndWhite;
	}
	else if (_stoneColorBandY.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stonesSelection.setPosition(971 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = BlackAndYellow;
	}
	else if (_stoneColorDGandLG.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stonesSelection.setPosition(1110 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = DarkGreenAndLightGreen;
	}
	else if (_stoneColorGandR.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stonesSelection.setPosition(761 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = GreenAndRed;
	}
	else if (_stoneColorOandV.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stonesSelection.setPosition(1041 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = OrangeAndViolet;
	}
	else if (_stoneColorPandFY.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stonesSelection.setPosition(901 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = PinkAndFluoYellow;
	}
	else if (_stoneColorSandC.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stonesSelection.setPosition(831 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = SalmonAndCoral;
	}
	else if (_stoneColorTGandI.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (stonesColor == NOSTONECOLOR)
			_stonesSelection.setPosition(1179 - 8, 379 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			stonesColor = TurquoiseGreenAndIndigo;
	}
	else {
		if (stonesColor == NOSTONECOLOR)
		_stonesSelection.setPosition(-100, -100);
	}
}

void	CustomPage::handleAvatarsSelection(sf::RenderWindow& window) {
	if (_avatarAlex.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarsSelection.setPosition(877 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = ALEX;
	}
	else if (_avatarGunther.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarsSelection.setPosition(1154 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = GUNTHER;
	}
	else if (_avatarHeric.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarsSelection.setPosition(970 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = HERIC;
	}
	else if (_avatarLaure.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarsSelection.setPosition(784 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = LAURE;
	}
	else if (_avatarMousse.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarsSelection.setPosition(1063 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = MOUSSE;
	}
	else if (_avatarTommy.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (playerOneAvatar == NOAVATAR)
			_avatarsSelection.setPosition(691 - 8, 563 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			playerOneAvatar = TOMMY;
	}
	else {
		if (playerOneAvatar == NOAVATAR)
			_avatarsSelection.setPosition(-100, -100);
	}
}

void	CustomPage::handleBoardSelection(sf::RenderWindow& window) {
	if (_boardColorAzure.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelection.setPosition(691 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = AZURE;
	}
	else if (_boardColorBlack.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelection.setPosition(1179 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = BLACK;
	}
	else if (_boardColorGray.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelection.setPosition(1110 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = GRAY;
	}
	else if (_boardColorGreen.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelection.setPosition(1041 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = GREEN;
	}
	else if (_boardColorOrange.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelection.setPosition(901 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = ORANGE;
	}
	else if (_boardColorPink.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelection.setPosition(971 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = PINK;
	}
	else if (_boardColorRed.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelection.setPosition(831 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = RED;
	}
	else if (_boardColorYellow.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (boardColor == NOBOARD)
			_boardSelection.setPosition(761 - 8, 776 - 8);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			boardColor = YELLOW;
	}
	else {
		if (boardColor == NOBOARD)
			_boardSelection.setPosition(-100, -100);
	}
}

void	CustomPage::customPageInit() {
	if (!_boardColorAzureTexture.loadFromFile("assets/images/boardSelection/Azure.png"))
		std::cerr << "Error: could not load board color azure texture" << std::endl;
	if (!_boardColorBlackTexture.loadFromFile("assets/images/boardSelection/Black.png"))
		std::cerr << "Error: could not load board color black texture" << std::endl;
	if (!_boardColorGrayTexture.loadFromFile("assets/images/boardSelection/Gray.png"))
		std::cerr << "Error: could not load board color gray texture" << std::endl;
	if (!_boardColorGreenTexture.loadFromFile("assets/images/boardSelection/Green.png"))
		std::cerr << "Error: could not load board color green texture" << std::endl;
	if (!_boardColorOrangeTexture.loadFromFile("assets/images/boardSelection/Orange.png"))
		std::cerr << "Error: could not load board color orange texture" << std::endl;
	if (!_boardColorPinkTexture.loadFromFile("assets/images/boardSelection/Pink.png"))
		std::cerr << "Error: could not load board color pink texture" << std::endl;
	if (!_boardColorRedTexture.loadFromFile("assets/images/boardSelection/Red.png"))
		std::cerr << "Error: could not load board color red texture" << std::endl;
	if (!_boardColorYellowTexture.loadFromFile("assets/images/boardSelection/Yellow.png"))
		std::cerr << "Error: could not load board color yellow texture" << std::endl;
	if (!_avatarAlexTexture.loadFromFile("assets/images/avatarSelection/Alex.png"))
		std::cerr << "Error: could not load avatar alex texture" << std::endl;
	if (!_avatarGuntherTexture.loadFromFile("assets/images/avatarSelection/Gunther.png"))
		std::cerr << "Error: could not load avatar gunther texture" << std::endl;
	if (!_avatarHericTexture.loadFromFile("assets/images/avatarSelection/Heric.png"))
		std::cerr << "Error: could not load avatar heric texture" << std::endl;
	if (!_avatarLaureTexture.loadFromFile("assets/images/avatarSelection/Laure.png"))
		std::cerr << "Error: could not load avatar laure texture" << std::endl;
	if (!_avatarMousseTexture.loadFromFile("assets/images/avatarSelection/Mousse.png"))
		std::cerr << "Error: could not load avatar mousse texture" << std::endl;
	if (!_avatarTommyTexture.loadFromFile("assets/images/avatarSelection/Tommy.png"))
		std::cerr << "Error: could not load avatar tommy texture" << std::endl;
	if (!_stoneColorBandWTexture.loadFromFile("assets/images/stoneSelection/B&W.png"))
		std::cerr << "Error: could not load stone color B&W texture" << std::endl;
	if (!_stoneColorBandYTexture.loadFromFile("assets/images/stoneSelection/B&Y.png"))
		std::cerr << "Error: could not load stone color B&Y texture" << std::endl;
	if (!_stoneColorDGandLGTexture.loadFromFile("assets/images/stoneSelection/DG&LG.png"))
		std::cerr << "Error: could not load stone color DG&LG texture" << std::endl;
	if (!_stoneColorGandRTexture.loadFromFile("assets/images/stoneSelection/G&R.png"))
		std::cerr << "Error: could not load stone color G&R texture" << std::endl;
	if (!_stoneColorOandVTexture.loadFromFile("assets/images/stoneSelection/O&V.png"))
		std::cerr << "Error: could not load stone color O&V texture" << std::endl;
	if (!_stoneColorPandFYTexture.loadFromFile("assets/images/stoneSelection/P&FY.png"))
		std::cerr << "Error: could not load stone color P&FY texture" << std::endl;
	if (!_stoneColorSandCTexture.loadFromFile("assets/images/stoneSelection/S&C.png"))
		std::cerr << "Error: could not load stone color S&C texture" << std::endl;
	if (!_stoneColorTGandITexture.loadFromFile("assets/images/stoneSelection/TG&I.png"))
		std::cerr << "Error: could not load stone color TG&I texture" << std::endl;
	if (!_returnButtonTexture.loadFromFile("assets/images/buttons/return_arrow.png"))
		std::cerr << "Error: could not load return button texture" << std::endl;
	if (!_returnButtonHighlightedTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png"))
		std::cerr << "Error: could not load return button highlighted texture" << std::endl;
	if (!_selectionHaloTexture.loadFromFile("assets/images/icons/selector.png"))
		std::cerr << "Error: could not load selection halo texture" << std::endl;
	if (!_avatarSelectorTexture.loadFromFile("assets/images/icons/avatar_selector.png"))
		std::cerr << "Error: could not load avatar selector texture" << std::endl;
	if (!_customPageTexture.loadFromFile("assets/customPage/Custom_Gomoku.png"))
		std::cerr << "Error: could not load custom page texture" << std::endl;

	_boardColorAzure.setTexture(_boardColorAzureTexture);
	_boardColorBlack.setTexture(_boardColorBlackTexture);
	_boardColorGray.setTexture(_boardColorGrayTexture);
	_boardColorGreen.setTexture(_boardColorGreenTexture);
	_boardColorOrange.setTexture(_boardColorOrangeTexture);
	_boardColorPink.setTexture(_boardColorPinkTexture);
	_boardColorRed.setTexture(_boardColorRedTexture);
	_boardColorYellow.setTexture(_boardColorYellowTexture);
	_avatarAlex.setTexture(_avatarAlexTexture);
	_avatarGunther.setTexture(_avatarGuntherTexture);
	_avatarHeric.setTexture(_avatarHericTexture);
	_avatarLaure.setTexture(_avatarLaureTexture);
	_avatarMousse.setTexture(_avatarMousseTexture);
	_avatarTommy.setTexture(_avatarTommyTexture);
	_stoneColorBandW.setTexture(_stoneColorBandWTexture);
	_stoneColorBandY.setTexture(_stoneColorBandYTexture);
	_stoneColorDGandLG.setTexture(_stoneColorDGandLGTexture);
	_stoneColorGandR.setTexture(_stoneColorGandRTexture);
	_stoneColorOandV.setTexture(_stoneColorOandVTexture);
	_stoneColorPandFY.setTexture(_stoneColorPandFYTexture);
	_stoneColorSandC.setTexture(_stoneColorSandCTexture);
	_stoneColorTGandI.setTexture(_stoneColorTGandITexture);
	_returnButton.setTexture(_returnButtonTexture);
	_stonesSelection.setTexture(_selectionHaloTexture);
	_boardSelection.setTexture(_selectionHaloTexture);
	_avatarsSelection.setTexture(_avatarSelectorTexture);
	_customPage.setTexture(_customPageTexture);

	_avatarAlex.setPosition(877, 563);
	_avatarGunther.setPosition(1154, 563);
	_avatarHeric.setPosition(970, 563);
	_avatarLaure.setPosition(784, 563);
	_avatarMousse.setPosition(1063, 563);
	_avatarTommy.setPosition(691, 563);
	_boardColorAzure.setPosition(691, 776);
	_boardColorBlack.setPosition(1179, 776);
	_boardColorGray.setPosition(1110, 776);
	_boardColorGreen.setPosition(1041, 776);
	_boardColorOrange.setPosition(901, 776);
	_boardColorPink.setPosition(971, 776);
	_boardColorRed.setPosition(831, 776);
	_boardColorYellow.setPosition(761, 776);
	_stoneColorBandW.setPosition(691, 379);
	_stoneColorBandY.setPosition(971, 379);
	_stoneColorDGandLG.setPosition(1110, 379);
	_stoneColorGandR.setPosition(761, 379);
	_stoneColorOandV.setPosition(1041, 379);
	_stoneColorPandFY.setPosition(901, 379);
	_stoneColorSandC.setPosition(831, 379);
	_stoneColorTGandI.setPosition(1179, 379);
	_returnButton.setPosition(100, 100);
}