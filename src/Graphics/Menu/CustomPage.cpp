/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomPage.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:33:47 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/17 11:33:12 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

void	MainMenu::customPage(sf::RenderWindow& window) {
	sf::RectangleShape	stoneColorFirstBar(sf::Vector2f(155, 5));
	sf::RectangleShape	stoneColorSecondBar(sf::Vector2f(155, 5));
	sf::RectangleShape	avatarsFirstBar(sf::Vector2f(198, 5));
	sf::RectangleShape	avatarsSecondBar(sf::Vector2f(201, 5));
	sf::RectangleShape	boardColorFirstBar(sf::Vector2f(206, 5));
	sf::RectangleShape	boardColorSecondBar(sf::Vector2f(207, 5));
	sf::Texture		artistTexture;
	sf::Texture		boardColorAzureTexture;
	sf::Texture		boardColorBlackTexture;
	sf::Texture		boardColorGrayTexture;
	sf::Texture		boardColorGreenTexture;
	sf::Texture		boardColorOrangeTexture;
	sf::Texture		boardColorPinkTexture;
	sf::Texture		boardColorRedTexture;
	sf::Texture		boardColorYellowTexture;
	sf::Texture		boardColorAzureSelectedTexture;
	sf::Texture		boardColorBlackSelectedTexture;
	sf::Texture		boardColorGraySelectedTexture;
	sf::Texture		boardColorGreenSelectedTexture;
	sf::Texture		boardColorOrangeSelectedTexture;
	sf::Texture		boardColorPinkSelectedTexture;
	sf::Texture		boardColorRedSelectedTexture;
	sf::Texture		boardColorYellowSelectedTexture;
	sf::Texture		avatarAlexTexture;
	sf::Texture		avatarGuntherTexture;
	sf::Texture		avatarHericTexture;
	sf::Texture		avatarLaureTexture;
	sf::Texture		avatarMousseTexture;
	sf::Texture		avatarTommyTexture;
	sf::Texture		avatarAlexSelectedTexture;
	sf::Texture		avatarGuntherSelectedTexture;
	sf::Texture		avatarHericSelectedTexture;
	sf::Texture		avatarLaureSelectedTexture;
	sf::Texture		avatarMousseSelectedTexture;
	sf::Texture		avatarTommySelectedTexture;
	sf::Texture		stoneColorBandWTexture;
	sf::Texture		stoneColorBandYTexture;
	sf::Texture		stoneColorDGandLGTexture;
	sf::Texture		stoneColorGandRTexture;
	sf::Texture		stoneColorOandVTexture;
	sf::Texture		stoneColorPandFYTexture;
	sf::Texture		stoneColorSandCTexture;
	sf::Texture		stoneColorTGandITexture;
	sf::Texture		stoneColorBandWSelectedTexture;
	sf::Texture		stoneColorBandYSelectedTexture;
	sf::Texture		stoneColorDGandLGSelectedTexture;
	sf::Texture		stoneColorGandRSelectedTexture;
	sf::Texture		stoneColorOandVSelectedTexture;
	sf::Texture		stoneColorPandFYSelectedTexture;
	sf::Texture		stoneColorSandCSelectedTexture;
	sf::Texture		stoneColorTGandISelectedTexture;
	sf::Sprite		artist;
	sf::Sprite		boardColorAzure;
	sf::Sprite		boardColorBlack;
	sf::Sprite		boardColorGray;
	sf::Sprite		boardColorGreen;
	sf::Sprite		boardColorOrange;
	sf::Sprite		boardColorPink;
	sf::Sprite		boardColorRed;
	sf::Sprite		boardColorYellow;
	sf::Sprite		avatarAlex;
	sf::Sprite		avatarGunther;
	sf::Sprite		avatarHeric;
	sf::Sprite		avatarLaure;
	sf::Sprite		avatarMousse;
	sf::Sprite		avatarTommy;
	sf::Sprite		stoneColorBandW;
	sf::Sprite		stoneColorBandY;
	sf::Sprite		stoneColorDGandLG;
	sf::Sprite		stoneColorGandR;
	sf::Sprite		stoneColorOandV;
	sf::Sprite		stoneColorPandFY;
	sf::Sprite		stoneColorSandC;
	sf::Sprite		stoneColorTGandI;

	if (!artistTexture.loadFromFile("assets/images/icons/artist.png"))
		std::cerr << "Error: could not load artist texture" << std::endl;
	if (!boardColorAzureTexture.loadFromFile("assets/images/boardSelection/Azure.png"))
		std::cerr << "Error: could not load board color azure texture" << std::endl;
	if (!boardColorBlackTexture.loadFromFile("assets/images/boardSelection/Black.png"))
		std::cerr << "Error: could not load board color black texture" << std::endl;
	if (!boardColorGrayTexture.loadFromFile("assets/images/boardSelection/Gray.png"))
		std::cerr << "Error: could not load board color gray texture" << std::endl;
	if (!boardColorGreenTexture.loadFromFile("assets/images/boardSelection/Green.png"))
		std::cerr << "Error: could not load board color green texture" << std::endl;
	if (!boardColorOrangeTexture.loadFromFile("assets/images/boardSelection/Orange.png"))
		std::cerr << "Error: could not load board color orange texture" << std::endl;
	if (!boardColorPinkTexture.loadFromFile("assets/images/boardSelection/Pink.png"))
		std::cerr << "Error: could not load board color pink texture" << std::endl;
	if (!boardColorRedTexture.loadFromFile("assets/images/boardSelection/Red.png"))
		std::cerr << "Error: could not load board color red texture" << std::endl;
	if (!boardColorYellowTexture.loadFromFile("assets/images/boardSelection/Yellow.png"))
		std::cerr << "Error: could not load board color yellow texture" << std::endl;
	if (!boardColorAzureSelectedTexture.loadFromFile("assets/images/boardSelection/Azure (selected).png"))
		std::cerr << "Error: could not load board color azure selected texture" << std::endl;
	if (!boardColorBlackSelectedTexture.loadFromFile("assets/images/boardSelection/Black (selected).png"))
		std::cerr << "Error: could not load board color black selected texture" << std::endl;
	if (!boardColorGraySelectedTexture.loadFromFile("assets/images/boardSelection/Gray (selected).png"))
		std::cerr << "Error: could not load board color gray selected texture" << std::endl;
	if (!boardColorGreenSelectedTexture.loadFromFile("assets/images/boardSelection/Green (selected).png"))
		std::cerr << "Error: could not load board color green selected texture" << std::endl;
	if (!boardColorOrangeSelectedTexture.loadFromFile("assets/images/boardSelection/Orange (selected).png"))
		std::cerr << "Error: could not load board color orange selected texture" << std::endl;
	if (!boardColorPinkSelectedTexture.loadFromFile("assets/images/boardSelection/Pink (selected).png"))
		std::cerr << "Error: could not load board color pink selected texture" << std::endl;
	if (!boardColorRedSelectedTexture.loadFromFile("assets/images/boardSelection/Red (selected).png"))
		std::cerr << "Error: could not load board color red selected texture" << std::endl;
	if (!boardColorYellowSelectedTexture.loadFromFile("assets/images/boardSelection/Yellow (selected).png"))
		std::cerr << "Error: could not load board color yellow selected texture" << std::endl;
/* 	if (!avatarAlexTexture.loadFromFile("assets/images/avatarSelection/Alex.png"))
		std::cerr << "Error: could not load avatar alex texture" << std::endl;
	if (!avatarGuntherTexture.loadFromFile("assets/images/avatarSelection/Gunther.png"))
		std::cerr << "Error: could not load avatar gunther texture" << std::endl;
	if (!avatarHericTexture.loadFromFile("assets/images/avatarSelection/Heric.png"))
		std::cerr << "Error: could not load avatar heric texture" << std::endl;
	if (!avatarLaureTexture.loadFromFile("assets/images/avatarSelection/Laure.png"))
		std::cerr << "Error: could not load avatar laure texture" << std::endl;
	if (!avatarMousseTexture.loadFromFile("assets/images/avatarSelection/Mousse.png"))
		std::cerr << "Error: could not load avatar mousse texture" << std::endl;
	if (!avatarTommyTexture.loadFromFile("assets/images/avatarSelection/Tommy.png"))
		std::cerr << "Error: could not load avatar tommy texture" << std::endl; */
	if (!avatarAlexSelectedTexture.loadFromFile("assets/images/avatarSelection/Alex (selected).png"))
		std::cerr << "Error: could not load avatar alex selected texture" << std::endl;
	if (!avatarGuntherSelectedTexture.loadFromFile("assets/images/avatarSelection/Gunther (selected).png"))
		std::cerr << "Error: could not load avatar gunther selected texture" << std::endl;
	if (!avatarHericSelectedTexture.loadFromFile("assets/images/avatarSelection/Heric (selected).png"))
		std::cerr << "Error: could not load avatar heric selected texture" << std::endl;
	if (!avatarLaureSelectedTexture.loadFromFile("assets/images/avatarSelection/Laure (selected).png"))
		std::cerr << "Error: could not load avatar laure selected texture" << std::endl;
	if (!avatarMousseSelectedTexture.loadFromFile("assets/images/avatarSelection/Mousse (selected).png"))
		std::cerr << "Error: could not load avatar mousse selected texture" << std::endl;
	if (!avatarTommySelectedTexture.loadFromFile("assets/images/avatarSelection/Tommy (selected).png"))
		std::cerr << "Error: could not load avatar tommy selected texture" << std::endl;
	if (!stoneColorBandWTexture.loadFromFile("assets/images/stoneSelection/B&W.png"))
		std::cerr << "Error: could not load stone color B&W texture" << std::endl;
	if (!stoneColorBandYTexture.loadFromFile("assets/images/stoneSelection/B&Y.png"))
		std::cerr << "Error: could not load stone color B&Y texture" << std::endl;
	if (!stoneColorDGandLGTexture.loadFromFile("assets/images/stoneSelection/DG&LG.png"))
		std::cerr << "Error: could not load stone color DG&LG texture" << std::endl;
	if (!stoneColorGandRTexture.loadFromFile("assets/images/stoneSelection/G&R.png"))
		std::cerr << "Error: could not load stone color G&R texture" << std::endl;
	if (!stoneColorOandVTexture.loadFromFile("assets/images/stoneSelection/O&V.png"))
		std::cerr << "Error: could not load stone color O&V texture" << std::endl;
	if (!stoneColorPandFYTexture.loadFromFile("assets/images/stoneSelection/P&FY.png"))
		std::cerr << "Error: could not load stone color P&FY texture" << std::endl;
	if (!stoneColorSandCTexture.loadFromFile("assets/images/stoneSelection/S&C.png"))
		std::cerr << "Error: could not load stone color S&C texture" << std::endl;
	if (!stoneColorTGandITexture.loadFromFile("assets/images/stoneSelection/TG&I.png"))
		std::cerr << "Error: could not load stone color TG&I texture" << std::endl;
	if (!stoneColorBandWSelectedTexture.loadFromFile("assets/images/stoneSelection/B&W (selected).png"))
		std::cerr << "Error: could not load stone color B&W selected texture" << std::endl;
	if (!stoneColorBandYSelectedTexture.loadFromFile("assets/images/stoneSelection/B&Y (selected).png"))
		std::cerr << "Error: could not load stone color B&Y selected texture" << std::endl;
	if (!stoneColorDGandLGSelectedTexture.loadFromFile("assets/images/stoneSelection/DG&LG (selected).png"))
		std::cerr << "Error: could not load stone color DG&LG selected texture" << std::endl;
	if (!stoneColorGandRSelectedTexture.loadFromFile("assets/images/stoneSelection/G&R (selected).png"))
		std::cerr << "Error: could not load stone color G&R selected texture" << std::endl;
	if (!stoneColorOandVSelectedTexture.loadFromFile("assets/images/stoneSelection/O&V (selected).png"))
		std::cerr << "Error: could not load stone color O&V selected texture" << std::endl;
	if (!stoneColorPandFYSelectedTexture.loadFromFile("assets/images/stoneSelection/P&FY (selected).png"))
		std::cerr << "Error: could not load stone color P&FY selected texture" << std::endl;
	if (!stoneColorSandCSelectedTexture.loadFromFile("assets/images/stoneSelection/S&C (selected).png"))
		std::cerr << "Error: could not load stone color S&C selected texture" << std::endl;
	if (!stoneColorTGandISelectedTexture.loadFromFile("assets/images/stoneSelection/TG&I (selected).png"))
		std::cerr << "Error: could not load stone color TG&I selected texture" << std::endl;
	
	artist.setTexture(artistTexture);
	boardColorAzure.setTexture(boardColorAzureTexture);
	boardColorBlack.setTexture(boardColorBlackTexture);
	boardColorGray.setTexture(boardColorGrayTexture);
	boardColorGreen.setTexture(boardColorGreenTexture);
	boardColorOrange.setTexture(boardColorOrangeTexture);
	boardColorPink.setTexture(boardColorPinkTexture);
	boardColorRed.setTexture(boardColorRedTexture);
	boardColorYellow.setTexture(boardColorYellowTexture);
	avatarAlex.setTexture(avatarAlexSelectedTexture);
	avatarGunther.setTexture(avatarGuntherSelectedTexture);
	avatarHeric.setTexture(avatarHericSelectedTexture);
	avatarLaure.setTexture(avatarLaureSelectedTexture);
	avatarMousse.setTexture(avatarMousseSelectedTexture);
	avatarTommy.setTexture(avatarTommySelectedTexture);
	stoneColorBandW.setTexture(stoneColorBandWTexture);
	stoneColorBandY.setTexture(stoneColorBandYTexture);
	stoneColorDGandLG.setTexture(stoneColorDGandLGTexture);
	stoneColorGandR.setTexture(stoneColorGandRTexture);
	stoneColorOandV.setTexture(stoneColorOandVTexture);
	stoneColorPandFY.setTexture(stoneColorPandFYTexture);
	stoneColorSandC.setTexture(stoneColorSandCTexture);
	stoneColorTGandI.setTexture(stoneColorTGandITexture);

	avatarAlex.setPosition(877, 563);
	avatarGunther.setPosition(1154, 563);
	avatarHeric.setPosition(970, 563);
	avatarLaure.setPosition(784, 563);
	avatarMousse.setPosition(1063, 563);
	avatarTommy.setPosition(691, 563);
	boardColorAzure.setPosition(691, 776);
	boardColorBlack.setPosition(1179, 776);
	boardColorGray.setPosition(1110, 776);
	boardColorGreen.setPosition(1041, 776);
	boardColorOrange.setPosition(901, 776);
	boardColorPink.setPosition(971, 776);
	boardColorRed.setPosition(831, 776);
	boardColorYellow.setPosition(761, 776);
	stoneColorBandW.setPosition(691, 379);
	stoneColorBandY.setPosition(971, 379);
	stoneColorDGandLG.setPosition(1110, 379);
	stoneColorGandR.setPosition(761, 379);
	stoneColorOandV.setPosition(1041, 379);
	stoneColorPandFY.setPosition(901, 379);
	stoneColorSandC.setPosition(831, 379);
	stoneColorTGandI.setPosition(1179, 379);
	stoneColorFirstBar.setPosition(682, 324);
	stoneColorSecondBar.setPosition(1082, 324);
	avatarsFirstBar.setPosition(682, 508);
	avatarsSecondBar.setPosition(1037, 508);
	boardColorFirstBar.setPosition(682, 727);
	boardColorSecondBar.setPosition(1031, 727);
	
	window.clear(sf::Color(38, 1, 69));
	window.draw(stoneColorBandW);
	window.draw(stoneColorBandY);
	window.draw(stoneColorDGandLG);
	window.draw(stoneColorGandR);
	window.draw(stoneColorOandV);
	window.draw(stoneColorPandFY);
	window.draw(stoneColorSandC);
	window.draw(stoneColorTGandI);

	window.draw(boardColorAzure);
	window.draw(boardColorBlack);
	window.draw(boardColorGray);
	window.draw(boardColorGreen);
	window.draw(boardColorOrange);
	window.draw(boardColorPink);
	window.draw(boardColorRed);
	window.draw(boardColorYellow);

	window.draw(avatarAlex);
	window.draw(avatarGunther);
	window.draw(avatarHeric);
	window.draw(avatarLaure);
	window.draw(avatarMousse);
	window.draw(avatarTommy);

	window.draw(stoneColorFirstBar);
	window.draw(stoneColorSecondBar);
	window.draw(avatarsFirstBar);
	window.draw(avatarsSecondBar);
	window.draw(boardColorFirstBar);
	window.draw(boardColorSecondBar);
}