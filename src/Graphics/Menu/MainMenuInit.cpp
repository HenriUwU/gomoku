/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu_init.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:35:09 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/17 12:12:31 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMenu.hpp"

using namespace std;

void	MainMenu::mainMenuInit() {
	if (!_exo2BlackFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-Black.ttf"))
		cerr << "Error while loading the 'Exo2-Black.ttf' file." << endl;
	if (!_ex02BlackItalicFont.loadFromFile("assets/fonts/Exo_2/static/Exo2-BlackItalic.ttf"))
		cerr << "Error while loading the 'Exo2-BlackItalic.ttf' file." << endl;
	if (!_greenButtonTexture.loadFromFile("assets/images/buttons/green_button.png"))
		cerr << "Error while loading the 'green_button.png' file." << endl;
	if (!_orangeButtonTexture.loadFromFile("assets/images/buttons/orange_button.png"))
		cerr << "Error while loading the 'orange_button.png' file." << endl;
	if (!_redButtonTexture.loadFromFile("assets/images/buttons/red_button.png"))
		cerr << "Error while loading the 'red_button.png' file." << endl;
	if (!_blueButtonTexture.loadFromFile("assets/images/buttons/blue_button.png"))
		cerr << "Error while loading the 'blue_button.png' file." << endl;
	if (!_greenButtonHighlightedTexture.loadFromFile("assets/images/buttons/green_button_highlight.png"))
		cerr << "Error while loading the 'green_button_highlight.png' file." << endl;
	if (!_orangeButtonHighlightedTexture.loadFromFile("assets/images/buttons/orange_button_highlight.png"))
		cerr << "Error while loading the 'orange_button_highlight.png' file." << endl;
	if (!_redButtonHighlightedTexture.loadFromFile("assets/images/buttons/red_button_highlight.png"))
		cerr << "Error while loading the 'red_button_highlight.png' file." << endl;
	if (!_blueButtonHighlightedTexture.loadFromFile("assets/images/buttons/blue_button_highlight.png"))
		cerr << "Error while loading the 'blue_button_highlight.png' file." << endl;
	if (!_customIconTexture.loadFromFile("assets/images/icons/custom.png"))
		cerr << "Error while loading the 'custom.png' file." << endl;
	if (!_settingsIconTexture.loadFromFile("assets/images/icons/settings.png"))
		cerr << "Error while loading the 'settings.png' file." << endl;
	if (!_helpIconTexture.loadFromFile("assets/images/icons/help.png"))
		cerr << "Error while loading the 'help.png' file." << endl;
	if (!_arrowIconTexture.loadFromFile("assets/images/buttons/return_arrow.png"))
		cerr << "Error while loading the 'return_arrow.png' file." << endl;
	if (!_arrowIconHighlightedTexture.loadFromFile("assets/images/buttons/return_arrow_highlight.png"))
		cerr << "Error while loading the 'return_arrow_highlight.png' file." << endl;

	_greenButtonSprite.setTexture(_greenButtonTexture);
	_orangeButtonSprite.setTexture(_orangeButtonTexture);
	_redButtonSprite.setTexture(_redButtonTexture);
	_blueButtonCustomSprite.setTexture(_blueButtonTexture);
	_blueButtonSettingsSprite.setTexture(_blueButtonTexture);
	_blueButtonHelpSprite.setTexture(_blueButtonTexture);
	_customIconSprite.setTexture(_customIconTexture);
	_settingsIconSprite.setTexture(_settingsIconTexture);
	_helpIconSprite.setTexture(_helpIconTexture);

	_greenButtonSprite.setPosition(683.64, 297.95);
	_orangeButtonSprite.setPosition(683.64, 430.09);
	_redButtonSprite.setPosition(683.64, 559.64);
	_blueButtonCustomSprite.setPosition(683.64, 755.45);
	_blueButtonSettingsSprite.setPosition(901.27, 755.45);
	_blueButtonHelpSprite.setPosition(1119.77, 755.45);
	_customIconSprite.setPosition(695, 766);
	_settingsIconSprite.setPosition(913, 766);
	_helpIconSprite.setPosition(1131, 766);

	_menuText[0].setString("Go");
	_menuText[0].setCharacterSize(140.48);
	_menuText[0].setFont(_exo2BlackFont);
	_menuText[0].setFillColor(sf::Color(141, 82, 190));
	_menuText[0].setPosition(684, 40);

	_menuText[1].setString("moku");
	_menuText[1].setCharacterSize(140.48);
	_menuText[1].setFont(_exo2BlackFont);
	_menuText[1].setFillColor(sf::Color(208, 87, 47));
	_menuText[1].setPosition(865, 40);

	_menuText[2].setString("Go");
	_menuText[2].setCharacterSize(140.48);
	_menuText[2].setFont(_exo2BlackFont);
	_menuText[2].setFillColor(sf::Color(248, 231, 254));
	_menuText[2].setPosition(684, 30);

	_menuText[3].setString("moku");
	_menuText[3].setCharacterSize(140.48);
	_menuText[3].setFont(_exo2BlackFont);
	_menuText[3].setFillColor(sf::Color(255, 164, 94));
	_menuText[3].setPosition(865, 30);

	_menuText[4].setString("by hsebille & laprieur");
	_menuText[4].setCharacterSize(30.23);
	_menuText[4].setFont(_exo2BlackFont);
	_menuText[4].setFillColor(sf::Color::White);
	_menuText[4].setPosition(800, 222);

	_menuText[5].setString("1 VS 1");
	_menuText[5].setCharacterSize(64.77);
	_menuText[5].setFont(_ex02BlackItalicFont);
	_menuText[5].setFillColor(sf::Color::White);
	_menuText[5].setPosition(877, 298);

	_menuText[6].setString("AI VERSUS");
	_menuText[6].setCharacterSize(64.77);
	_menuText[6].setFont(_ex02BlackItalicFont);
	_menuText[6].setFillColor(sf::Color::White);
	_menuText[6].setPosition(795, 430);

	_menuText[7].setString("EXIT");
	_menuText[7].setCharacterSize(64.77);
	_menuText[7].setFont(_ex02BlackItalicFont);
	_menuText[7].setFillColor(sf::Color::White);
	_menuText[7].setPosition(887, 559);

	_menuText[8].setString("More options");
	_menuText[8].setCharacterSize(30.23);
	_menuText[8].setFont(_exo2BlackFont);
	_menuText[8].setFillColor(sf::Color::White);
	_menuText[8].setPosition(857, 685);

	_selectedItemIndex = 5;
	_greenButtonSprite.setTexture(_greenButtonHighlightedTexture);
}