/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimatedGIF.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:46:09 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/03 13:28:26 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMATEDGIF_H__
#define __ANIMATEDGIF_H__

#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>

class AnimatedGIF {
	private:
		sf::Time											_startTime;
		sf::Time											_totalDelay;
		sf::Clock											_clock;
		sf::Vector2i										_size;
		std::vector<std::tuple<int, sf::Texture>>			_frames;
		std::vector<std::tuple<int, sf::Texture>>::iterator	_frameIter;

	public:
		AnimatedGIF();
		~AnimatedGIF();

		void				loadFile(const std::string& filename);
		const sf::Vector2i&	getSize(void);
		void				update(sf::Sprite& sprite);
};

#endif