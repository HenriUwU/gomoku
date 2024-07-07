/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimatedGIF.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:46:09 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/18 22:32:48 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMATEDGIF_H__
#define __ANIMATEDGIF_H__

#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>

class AnimatedGIF {
	private:
		sf::Time											startTime;
		sf::Time											totalDelay;
		sf::Clock											clock;
		sf::Vector2i										size;
		std::vector<std::tuple<int, sf::Texture>>			frames;
		std::vector<std::tuple<int, sf::Texture>>::iterator	frameIter;

	public:
		AnimatedGIF(const char* filename);
		
		const sf::Vector2i& getSize(void);
		void update(sf::Sprite& sprite);
};

#endif