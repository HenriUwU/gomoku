/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Music.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:47:02 by laprieur          #+#    #+#             */
/*   Updated: 2024/07/09 23:14:51 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gomoku.hpp"

class Music {
	private:
		std::vector<std::unique_ptr<sf::Music>>	_musics;

	public:
		Music();
		~Music();

		void	defineVolume(float volume);
		void	stopAllMusics();
		void	playMusic();
};
