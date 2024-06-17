/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomPageInit.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:18:29 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/17 12:24:56 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

void	MainMenu::customPageInit() {
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
	if (!_boardColorAzureSelectedTexture.loadFromFile("assets/images/boardSelection/Azure (selected).png"))
		std::cerr << "Error: could not load board color azure selected texture" << std::endl;
	if (!_boardColorBlackSelectedTexture.loadFromFile("assets/images/boardSelection/Black (selected).png"))
		std::cerr << "Error: could not load board color black selected texture" << std::endl;
	if (!_boardColorGraySelectedTexture.loadFromFile("assets/images/boardSelection/Gray (selected).png"))
		std::cerr << "Error: could not load board color gray selected texture" << std::endl;
	if (!_boardColorGreenSelectedTexture.loadFromFile("assets/images/boardSelection/Green (selected).png"))
		std::cerr << "Error: could not load board color green selected texture" << std::endl;
	if (!_boardColorOrangeSelectedTexture.loadFromFile("assets/images/boardSelection/Orange (selected).png"))
		std::cerr << "Error: could not load board color orange selected texture" << std::endl;
	if (!_boardColorPinkSelectedTexture.loadFromFile("assets/images/boardSelection/Pink (selected).png"))
		std::cerr << "Error: could not load board color pink selected texture" << std::endl;
	if (!_boardColorRedSelectedTexture.loadFromFile("assets/images/boardSelection/Red (selected).png"))
		std::cerr << "Error: could not load board color red selected texture" << std::endl;
	if (!_boardColorYellowSelectedTexture.loadFromFile("assets/images/boardSelection/Yellow (selected).png"))
		std::cerr << "Error: could not load board color yellow selected texture" << std::endl;
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
	if (!_avatarAlexSelectedTexture.loadFromFile("assets/images/avatarSelection/Alex (selected).png"))
		std::cerr << "Error: could not load avatar alex selected texture" << std::endl;
	if (!_avatarGuntherSelectedTexture.loadFromFile("assets/images/avatarSelection/Gunther (selected).png"))
		std::cerr << "Error: could not load avatar gunther selected texture" << std::endl;
	if (!_avatarHericSelectedTexture.loadFromFile("assets/images/avatarSelection/Heric (selected).png"))
		std::cerr << "Error: could not load avatar heric selected texture" << std::endl;
	if (!_avatarLaureSelectedTexture.loadFromFile("assets/images/avatarSelection/Laure (selected).png"))
		std::cerr << "Error: could not load avatar laure selected texture" << std::endl;
	if (!_avatarMousseSelectedTexture.loadFromFile("assets/images/avatarSelection/Mousse (selected).png"))
		std::cerr << "Error: could not load avatar mousse selected texture" << std::endl;
	if (!_avatarTommySelectedTexture.loadFromFile("assets/images/avatarSelection/Tommy (selected).png"))
		std::cerr << "Error: could not load avatar tommy selected texture" << std::endl;
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
	if (!_stoneColorBandWSelectedTexture.loadFromFile("assets/images/stoneSelection/B&W (selected).png"))
		std::cerr << "Error: could not load stone color B&W selected texture" << std::endl;
	if (!_stoneColorBandYSelectedTexture.loadFromFile("assets/images/stoneSelection/B&Y (selected).png"))
		std::cerr << "Error: could not load stone color B&Y selected texture" << std::endl;
	if (!_stoneColorDGandLGSelectedTexture.loadFromFile("assets/images/stoneSelection/DG&LG (selected).png"))
		std::cerr << "Error: could not load stone color DG&LG selected texture" << std::endl;
	if (!_stoneColorGandRSelectedTexture.loadFromFile("assets/images/stoneSelection/G&R (selected).png"))
		std::cerr << "Error: could not load stone color G&R selected texture" << std::endl;
	if (!_stoneColorOandVSelectedTexture.loadFromFile("assets/images/stoneSelection/O&V (selected).png"))
		std::cerr << "Error: could not load stone color O&V selected texture" << std::endl;
	if (!_stoneColorPandFYSelectedTexture.loadFromFile("assets/images/stoneSelection/P&FY (selected).png"))
		std::cerr << "Error: could not load stone color P&FY selected texture" << std::endl;
	if (!_stoneColorSandCSelectedTexture.loadFromFile("assets/images/stoneSelection/S&C (selected).png"))
		std::cerr << "Error: could not load stone color S&C selected texture" << std::endl;
	if (!_stoneColorTGandISelectedTexture.loadFromFile("assets/images/stoneSelection/TG&I (selected).png"))
		std::cerr << "Error: could not load stone color TG&I selected texture" << std::endl;

	_artist.setTexture(_artistTexture);
	_boardColorAzure.setTexture(_boardColorAzureTexture);
	_boardColorBlack.setTexture(_boardColorBlackTexture);
	_boardColorGray.setTexture(_boardColorGrayTexture);
	_boardColorGreen.setTexture(_boardColorGreenTexture);
	_boardColorOrange.setTexture(_boardColorOrangeTexture);
	_boardColorPink.setTexture(_boardColorPinkTexture);
	_boardColorRed.setTexture(_boardColorRedTexture);
	_boardColorYellow.setTexture(_boardColorYellowTexture);
	_avatarAlex.setTexture(_avatarAlexSelectedTexture);
	_avatarGunther.setTexture(_avatarGuntherSelectedTexture);
	_avatarHeric.setTexture(_avatarHericSelectedTexture);
	_avatarLaure.setTexture(_avatarLaureSelectedTexture);
	_avatarMousse.setTexture(_avatarMousseSelectedTexture);
	_avatarTommy.setTexture(_avatarTommySelectedTexture);
	_stoneColorBandW.setTexture(_stoneColorBandWTexture);
	_stoneColorBandY.setTexture(_stoneColorBandYTexture);
	_stoneColorDGandLG.setTexture(_stoneColorDGandLGTexture);
	_stoneColorGandR.setTexture(_stoneColorGandRTexture);
	_stoneColorOandV.setTexture(_stoneColorOandVTexture);
	_stoneColorPandFY.setTexture(_stoneColorPandFYTexture);
	_stoneColorSandC.setTexture(_stoneColorSandCTexture);
	_stoneColorTGandI.setTexture(_stoneColorTGandITexture);

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
}