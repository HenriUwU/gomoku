/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:06:48 by hsebille          #+#    #+#             */
/*   Updated: 2024/05/09 14:24:31 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define NB_MENU_ITEMS 4

class MainMenu {
    private:
        int         _selectedItemIndex;
        sf::Font    _font;
        sf::Text    _menu[NB_MENU_ITEMS];
        sf::Texture _backgroundTexture;
        sf::Sprite  _backgroundSprite;
        sf::Music   _music;
        
    public:
        MainMenu(float width, float height);
        ~MainMenu();

        void    draw(sf::RenderWindow &window);
        void    MoveUp();
        void    MoveDown();
        void    playMusic();
        void    stopMusic();
        int     getSelectedItemIndex() { return _selectedItemIndex; }   
};