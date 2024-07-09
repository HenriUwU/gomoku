/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Music.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:46:08 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/09 23:51:13 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Music.hpp"

Music::Music() {
	const std::string musics[] = {"menu", "1vs1", "aiVersus"};
	for (int i = 0; i < 3; i++) {
		std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();
		std::string filePath = "assets/musics/" + musics[i] + "Music.ogg";
		if (music->openFromFile(filePath))
			_musics.push_back(std::move(music));
	}
}

Music::~Music() {}

void	Music::defineVolume(float volume) {
	for (int i = 0; i < 3; i++)
		_musics[i]->setVolume(volume);
}

void	Music::stopAllMusics() {
	for (int i = 0; i < 3; i++) {
		_musics[i]->stop();
		_musics[i]->setLoop(false);
	}
}

void Music::playMusic() {
	static GameState previousGameState = NONE;
	if (previousGameState != gameState) {
		switch (gameState) {
			case MENU:
				if (previousGameState != CUSTOM && previousGameState != SETTINGS && previousGameState != HELP) {
					stopAllMusics();
					_musics[MENU]->play();
					_musics[MENU]->setLoop(true);
				}
				break;
			case GAME:
				stopAllMusics();
				_musics[GAME]->play();
				_musics[GAME]->setLoop(true);
				break;
			case AIVERSUS:
				stopAllMusics();
				_musics[AIVERSUS]->play();
				_musics[AIVERSUS]->setLoop(true);
				break;
			default:
				break;
		}
		previousGameState = gameState;
	}
}
