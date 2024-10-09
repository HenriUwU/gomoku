/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimatedGIF.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:47:04 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/03 13:30:06 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/Graphics/GIF/AnimatedGIF.hpp"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_GIF
#include "../../../lib/stb/stb_image.h"

AnimatedGIF::AnimatedGIF() {}

AnimatedGIF::~AnimatedGIF() {}

void	AnimatedGIF::loadFile(const std::string& filename) {
	FILE *f = stbi__fopen(filename.c_str(), "rb");
	stbi__context s;
	stbi__start_file(&s, f);

	int *delays = 0;
	int z = 0, comp = 0;

	void *pixels = stbi__load_gif_main(&s, &delays, &_size.x, &_size.y, &z, &comp, STBI_rgb_alpha);

	sf::Image image;
	int step = _size.x * _size.y * 4;

	for (int i = 0; i < z; i++) {
		image.create(_size.x, _size.y, (const sf::Uint8*) pixels + step * i);

		sf::Texture texture;
		texture.loadFromImage(image);

		_frames.push_back(std::tuple<int, sf::Texture>(delays[i], texture));
	}

	_frameIter = _frames.begin();

	stbi_image_free(pixels);
	if(delays)
		stbi_image_free(delays);
	fclose(f);

	_totalDelay = sf::Time::Zero;
	_startTime = _clock.getElapsedTime();
}

const sf::Vector2i& AnimatedGIF::getSize() {
	return _size;
}

void	AnimatedGIF::update(sf::Sprite& sprite) {
	sf::Time delay = sf::milliseconds(std::get<0>(*_frameIter));

	while (_startTime + _totalDelay + delay < _clock.getElapsedTime()) {
		_frameIter++;
		if (_frameIter == _frames.end()) _frameIter = _frames.begin();
			_totalDelay += delay;
		delay = sf::milliseconds(std::get<0>(*_frameIter));
	}

	sf::Texture &texture = std::get<1>(*_frameIter);
	sprite.setTexture(texture);
}
