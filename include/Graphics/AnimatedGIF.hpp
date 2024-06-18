/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimatedGIF.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:46:09 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/18 13:46:17 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMATEDGIF_H__
#define __ANIMATEDGIF_H__

#include <SFML/Graphics.hpp>

#include <vector>
#include <tuple>

class AnimatedGIF
{
    public:
        AnimatedGIF(const char* filename);

        const sf::Vector2i& getSize(void);
        void update(sf::Sprite& sprite);

    private:
        sf::Vector2i size;
        sf::Clock clock;
        sf::Time startTime;
        sf::Time totalDelay;
        std::vector<std::tuple<int, sf::Texture>> frames;
        std::vector<std::tuple<int, sf::Texture>>::iterator frameIter;
};

#endif