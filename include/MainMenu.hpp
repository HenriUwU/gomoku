/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMenu.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:06:48 by hsebille          #+#    #+#             */
/*   Updated: 2024/05/08 16:13:13 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include <iostream>

#define NB_MENU_ITEMS 4

class MainMenu {
    private:
        int         _selectedItemIndex;
        sf::Font    _font;
        sf::Text    _menu[NB_MENU_ITEMS];
        
    public:
        MainMenu(float width, float height);
        ~MainMenu();

        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int getSelectedItemIndex() { return _selectedItemIndex; }   
};