/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomPage.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:33:47 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/17 16:42:29 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomPage.hpp"

CustomPage::CustomPage() {
	customPageInit();
}

CustomPage::~CustomPage() {}

void	CustomPage::display(sf::RenderWindow& window) {
	sf::RectangleShape	stoneColorFirstBar(sf::Vector2f(155, 5));
	sf::RectangleShape	stoneColorSecondBar(sf::Vector2f(155, 5));
	sf::RectangleShape	avatarsFirstBar(sf::Vector2f(198, 5));
	sf::RectangleShape	avatarsSecondBar(sf::Vector2f(201, 5));
	sf::RectangleShape	boardColorFirstBar(sf::Vector2f(206, 5));
	sf::RectangleShape	boardColorSecondBar(sf::Vector2f(207, 5));

	stoneColorFirstBar.setPosition(682, 324);
	stoneColorSecondBar.setPosition(1082, 324);
	avatarsFirstBar.setPosition(682, 508);
	avatarsSecondBar.setPosition(1037, 508);
	boardColorFirstBar.setPosition(682, 727);
	boardColorSecondBar.setPosition(1031, 727);

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

	window.draw(_customShadow);
	window.draw(_custom);
	window.draw(_showYourArtisticSoul);
	window.draw(_stonesColor);
	window.draw(_BandW);
	window.draw(_BandY);
	window.draw(_GandR);
	window.draw(_OandV);
	window.draw(_PandFY);
	window.draw(_SandC);
	window.draw(_TGandI);
	window.draw(_DGandLG);
	window.draw(_backToMenu);
	
	window.draw(_avatars);
	window.draw(_Alex);
	window.draw(_Gunther);
	window.draw(_Heric);
	window.draw(_Laure);
	window.draw(_Mousse);
	window.draw(_Tommy);
	window.draw(_boards);
	window.draw(_Azure);
	window.draw(_Black);
	window.draw(_Gray);
	window.draw(_Green);
	window.draw(_Orange);
	window.draw(_Pink);
	window.draw(_Red);
	window.draw(_Yellow);

	window.draw(stoneColorFirstBar);
	window.draw(stoneColorSecondBar);
	window.draw(avatarsFirstBar);
	window.draw(avatarsSecondBar);
	window.draw(boardColorFirstBar);
	window.draw(boardColorSecondBar);

	window.draw(_artist);
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
	if (!_artistTexture.loadFromFile("assets/images/icons/artist.png"))
		std::cerr << "Error: could not load artist texture" << std::endl;
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
	if (!_exo2BlackFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-Black.ttf"))
		std::cerr << "Error: could not load Exo2-Black font" << std::endl;
	if (!_exo2BlackItalicFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-BlackItalic.ttf"))
		std::cerr << "Error: could not load Exo2-BlackItalic font" << std::endl;
	if (!_selectionHaloTexture.loadFromFile("assets/images/icons/selector.png"))
		std::cerr << "Error: could not load selection halo texture" << std::endl;
	if (!_avatarSelectorTexture.loadFromFile("assets/images/icons/avatar_selector.png"))
		std::cerr << "Error: could not load avatar selector texture" << std::endl;

	_artist.setTexture(_artistTexture);
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
	_returnButton.setPosition(34, 34);
	_artist.setPosition(1113, 245);

	_custom.setFont(_exo2BlackFont);
	_customShadow.setFont(_exo2BlackFont);
	_showYourArtisticSoul.setFont(_exo2BlackFont);
	_stonesColor.setFont(_exo2BlackFont);
	_BandW.setFont(_exo2BlackFont);
	_BandY.setFont(_exo2BlackFont);
	_GandR.setFont(_exo2BlackFont);
	_OandV.setFont(_exo2BlackFont);
	_PandFY.setFont(_exo2BlackFont);
	_SandC.setFont(_exo2BlackFont);
	_TGandI.setFont(_exo2BlackFont);
	_DGandLG.setFont(_exo2BlackFont);
	_avatars.setFont(_exo2BlackFont);
	_Alex.setFont(_exo2BlackFont);
	_Gunther.setFont(_exo2BlackFont);
	_Heric.setFont(_exo2BlackFont);
	_Laure.setFont(_exo2BlackFont);
	_Mousse.setFont(_exo2BlackFont);
	_Tommy.setFont(_exo2BlackFont);
	_boards.setFont(_exo2BlackFont);
	_Azure.setFont(_exo2BlackFont);
	_Black.setFont(_exo2BlackFont);
	_Gray.setFont(_exo2BlackFont);
	_Green.setFont(_exo2BlackFont);
	_Orange.setFont(_exo2BlackFont);
	_Pink.setFont(_exo2BlackFont);
	_Red.setFont(_exo2BlackFont);
	_Yellow.setFont(_exo2BlackFont);
	_backToMenu.setFont(_exo2BlackItalicFont);
	_customShadow.setFillColor(sf::Color(193, 167, 252));

	_custom.setString("Custom");
	_customShadow.setString("Custom");
	_showYourArtisticSoul.setString("Show your artistic soul!");
	_stonesColor.setString("Stones colors");
	_BandW.setString("B&W");
	_BandY.setString("B&Y");
	_GandR.setString("G&R");
	_OandV.setString("O&V");
	_PandFY.setString("P&FY");
	_SandC.setString("S&C");
	_TGandI.setString("TG&I");
	_DGandLG.setString("DG&LG");
	_avatars.setString("Avatars");
	_Alex.setString("Alex");
	_Gunther.setString("Gunther");
	_Heric.setString("Heric");
	_Laure.setString("Laure");
	_Mousse.setString("Mousse");
	_Tommy.setString("Tommy");
	_boards.setString("Boards");
	_Azure.setString("Azure");
	_Black.setString("Black");
	_Gray.setString("Gray");
	_Green.setString("Green");
	_Orange.setString("Orange");
	_Pink.setString("Pink");
	_Red.setString("Red");
	_Yellow.setString("Yellow");
	_backToMenu.setString("Back to menu");

	_custom.setCharacterSize(152);
	_customShadow.setCharacterSize(152);
	_showYourArtisticSoul.setCharacterSize(30);
	_stonesColor.setCharacterSize(30);
	_BandW.setCharacterSize(18.75);
	_BandY.setCharacterSize(18.75);
	_GandR.setCharacterSize(18.75);
	_OandV.setCharacterSize(18.75);
	_PandFY.setCharacterSize(18.75);
	_SandC.setCharacterSize(18.75);
	_TGandI.setCharacterSize(18.75);
	_DGandLG.setCharacterSize(18.75);
	_avatars.setCharacterSize(30);
	_Alex.setCharacterSize(18.75);
	_Gunther.setCharacterSize(18.75);
	_Heric.setCharacterSize(18.75);
	_Laure.setCharacterSize(18.75);
	_Mousse.setCharacterSize(18.75);
	_Tommy.setCharacterSize(18.75);
	_boards.setCharacterSize(30);
	_Azure.setCharacterSize(18.75);
	_Black.setCharacterSize(18.75);
	_Gray.setCharacterSize(18.75);
	_Green.setCharacterSize(18.75);
	_Orange.setCharacterSize(18.75);
	_Pink.setCharacterSize(18.75);
	_Red.setCharacterSize(18.75);
	_Yellow.setCharacterSize(18.75);
	_backToMenu.setCharacterSize(20);
	
	_stonesColor.setPosition(857, 306);
	_avatars.setPosition(900, 491);
	_boards.setPosition(907, 710);
	_Azure.setPosition(687, 841);
	_Black.setPosition(1177, 841);
	_Gray.setPosition(1111, 841);
	_Green.setPosition(1037, 841);
	_Orange.setPosition(893, 841);
	_Pink.setPosition(974, 841);
	_Yellow.setPosition(753, 841);
	_Red.setPosition(837, 841);
	_Tommy.setPosition(695, 653);
	_Laure.setPosition(793, 653);
	_Alex.setPosition(891, 653);
	_Heric.setPosition(982, 653);
	_Mousse.setPosition(1062, 653);
	_Gunther.setPosition(1154, 653);
	_showYourArtisticSoul.setPosition(745, 250);
	_custom.setPosition(680, 60);
	_customShadow.setPosition(682, 70);
	_BandW.setPosition(695, 442);
	_BandY.setPosition(975, 442);
	_GandR.setPosition(764, 442);
	_OandV.setPosition(1044, 442);
	_PandFY.setPosition(902, 442);
	_SandC.setPosition(835, 442);
	_TGandI.setPosition(1181, 442);
	_DGandLG.setPosition(1105, 442);
	_backToMenu.setPosition(114, 54);
}