/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:19:41 by laprieur          #+#    #+#             */
/*   Updated: 2024/06/18 20:31:37 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

using namespace std;

Gameplay::Gameplay(sf::RenderWindow& window) : Graphics(window) {
	for (int i = 0; i < 19; i++) {
		int character = 'A' + i;
		for (int j = 1; j < 20; j++) {
			string position = string(1, character) + to_string(j);
			_playerPositions.insert(pair<string, int>(position, 0));
		}
	}
	_currentPlayer = 1;
	_gridPosition = sf::Vector2f(527 - 48, 50 - 48);
	_gridSize = 964;
	_cellSize = 48;
	
	if (!_blackStoneTexture.loadFromFile("assets/images/stones/black.png"))
		cerr << "Error while loading the blackStoneTexture file." << endl;
	if (!_whiteStoneTexture.loadFromFile("assets/images/stones/white.png"))
		cerr << "Error while loading the whiteStoneTexture file." << endl;
	if (!_coralStoneTexture.loadFromFile("assets/images/stones/coral.png"))
		cerr << "Error while loading the coralStoneTexture file." << endl;
	if (!_darkGreenStoneTexture.loadFromFile("assets/images/stones/darkGreen.png"))
		cerr << "Error while loading the darkGreenStoneTexture file." << endl;
	if (!_lightGreenStoneTexture.loadFromFile("assets/images/stones/lightGreen.png"))
		cerr << "Error while loading the lightGreenStoneTexture file." << endl;
	if (!_violetStoneTexture.loadFromFile("assets/images/stones/violet.png"))
		cerr << "Error while loading the violetStoneTexture file." << endl;
	if (!_yellowStoneTexture.loadFromFile("assets/images/stones/yellow.png"))
		cerr << "Error while loading the yellowStoneTexture file." << endl;
	if (!_fluoYellowStoneTexture.loadFromFile("assets/images/stones/fluoYellow.png"))
		cerr << "Error while loading the fluoYellowStoneTexture file." << endl;
	if (!_pinkStoneTexture.loadFromFile("assets/images/stones/pink.png"))
		cerr << "Error while loading the pinkStoneTexture file." << endl;
	if (!_greenStoneTexture.loadFromFile("assets/images/stones/green.png"))
		cerr << "Error while loading the greenStoneTexture file." << endl;
	if (!_indigoStoneTexture.loadFromFile("assets/images/stones/indigo.png"))
		cerr << "Error while loading the indigoStoneTexture file." << endl;
	if (!_orangeStoneTexture.loadFromFile("assets/images/stones/orange.png"))
		cerr << "Error while loading the orangeStoneTexture file." << endl;
	if (!_redStoneTexture.loadFromFile("assets/images/stones/red.png"))
		cerr << "Error while loading the redStoneTexture file." << endl;
	if (!_salmonStoneTexture.loadFromFile("assets/images/stones/salmon.png"))
		cerr << "Error while loading the salmonStoneTexture file." << endl;
	if (!_turquoiseGreenStoneTexture.loadFromFile("assets/images/stones/turquoiseGreen.png"))
		cerr << "Error while loading the turquoiseGreenStoneTexture file." << endl;

	_firstStone.setTexture(_blackStoneTexture);
	_secondStone.setTexture(_whiteStoneTexture);
}

Gameplay::~Gameplay() {}

void	Gameplay::handleKeys(sf::Event& event, sf::RenderWindow& window) {
	(void)window;
	(void)event;

	if (gameState == GAME) {
		//mouseHover(window, event);
	}
}

void Gameplay::mouseHover(sf::RenderWindow& window) {
	if (stonesColor == BlackAndWhite) {
		_firstStone.setTexture(_blackStoneTexture);
		_secondStone.setTexture(_whiteStoneTexture);
	}
	else if (stonesColor == GreenAndRed) {
		_firstStone.setTexture(_greenStoneTexture);
		_secondStone.setTexture(_redStoneTexture);
	}
	else if (stonesColor == SalmonAndCoral) {
		_firstStone.setTexture(_salmonStoneTexture);
		_secondStone.setTexture(_coralStoneTexture);
	}
	else if (stonesColor == PinkAndFluoYellow) {
		_firstStone.setTexture(_pinkStoneTexture);
		_secondStone.setTexture(_fluoYellowStoneTexture);
	}
	else if (stonesColor == BlackAndYellow) {
		_firstStone.setTexture(_blackStoneTexture);
		_secondStone.setTexture(_yellowStoneTexture);
	}
	else if (stonesColor == OrangeAndViolet) {
		_firstStone.setTexture(_orangeStoneTexture);
		_secondStone.setTexture(_violetStoneTexture);
	}
	else if (stonesColor == DarkGreenAndLightGreen) {
		_firstStone.setTexture(_darkGreenStoneTexture);
		_secondStone.setTexture(_lightGreenStoneTexture);
	}
	else if (stonesColor == TurquoiseGreenAndIndigo) {
		_firstStone.setTexture(_turquoiseGreenStoneTexture);
		_secondStone.setTexture(_indigoStoneTexture);
	}
	
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

    // Check if the mouse is within the grid bounds
    if (worldPos.x >= _gridPosition.x && worldPos.x <= _gridPosition.x + _gridSize &&
        worldPos.y >= _gridPosition.y && worldPos.y <= _gridPosition.y + _gridSize) {
        
        // Calculate the nearest intersection
        float relativeX = worldPos.x - _gridPosition.x;
        float relativeY = worldPos.y - _gridPosition.y;

        int col = static_cast<int>(relativeX / _cellSize);
        int row = static_cast<int>(relativeY / _cellSize);

        float nearestX = _gridPosition.x + col * _cellSize;
        float nearestY = _gridPosition.y + row * _cellSize;

        // Place the stone sprite at the nearest intersection with lower opacity
        _firstStone.setPosition(nearestX - _firstStone.getGlobalBounds().width / 2, nearestY - _firstStone.getGlobalBounds().height / 2);
    } else {
        // If the mouse is not within the grid, place the stone offscreen
        _firstStone.setPosition(-_firstStone.getGlobalBounds().width, -_firstStone.getGlobalBounds().height);
    }

    // Draw the stone sprite
    window.draw(_firstStone);
}


void Gameplay::circleFollowMouse(sf::RenderWindow& window, sf::Event& event) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	float xIndex = round((mousePosition.x - _gridStartPoint.first) / _cellSize);
	float yIndex = round((mousePosition.y - _gridStartPoint.second) / _cellSize);
	Goban goban(window);
	sf::Sprite	_stoneSprite;
	window.clear();
	//goban.display(window);
	
	// Draw the circle following the mouse if the mouse is on the grid
	if (xIndex >= 0 && xIndex < 19 && yIndex >= 0 && yIndex < 19) {
		sf::Vector2f nearestIntersection(_gridStartPoint.first + xIndex * _cellSize, _gridStartPoint.second + yIndex * _cellSize);
		
		if (_currentPlayer == 1)
			_stoneSprite.setTexture(_blackStoneTexture);
		else
			_stoneSprite.setTexture(_whiteStoneTexture);
		
		_stoneSprite.setPosition(nearestIntersection.x - 13, nearestIntersection.y - 13);
		window.draw(_stoneSprite);
	}
	
	char xCoord = 'A' + static_cast<int>(xIndex);
	int yCoord = 19 - static_cast<int>(yIndex);
	string position = string(1, xCoord) + to_string(yCoord);

	// Place the stone on the grid if left mouse button is pressed
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		if (xIndex >= 0 && xIndex < 19 && yIndex >= 0 && yIndex < 19) {
			// Place the stone for the current player
			placeStone(position, window);
		}
	}
	// checkStatus(_currentPlayer);
	if (gameState == GAME) {
		goban.drawPlayerPositions(window, _playerPositions);
	}
	window.display();
}

void	Gameplay::placeStone(string position, sf::RenderWindow& window) {
	if (_playerPositions[position] != 0)
		return;
	if (!isMoveLegal(position))
		return;

	_playerPositions[position] = _currentPlayer;

	if (isWinningMove(position)) {
		Goban goban(window);
	}

	if (_currentPlayer == 1)
		_currentPlayer = 2;
	else
		_currentPlayer = 1;
}

bool	Gameplay::isMoveLegal(string position) {
	vector<pair<string, int>>	nearbyLines[4];

	for (int i = 0; i < 4; i++) {
		pair<string, int> pair = make_pair(position, _currentPlayer);
		nearbyLines[i].push_back(pair);
	}
	findHorizontalLine(4, position, nearbyLines[0]);
	findVerticalLine(4, position, nearbyLines[1]);
	findDiagonalLine(4, position, nearbyLines[2]);
	findAntiDiagonalLine(4, position, nearbyLines[3]);

	if (!isCapturingMove(position) && isThereDoubleThree(nearbyLines)) {
		cout << "Illegal move : Double three detected\n";
		return false;
	}

	return true;
}

bool	Gameplay::isWinningMove(string position) {
	vector<pair<string, int>>	nearbyLines[4];

	for (int i = 0; i < 4; i++) {
		pair<string, int> pair = make_pair(position, _currentPlayer);
		nearbyLines[i].push_back(pair);
	}

	findHorizontalLine(4, position, nearbyLines[0]);
	findVerticalLine(4, position, nearbyLines[1]);
	findDiagonalLine(4, position, nearbyLines[2]);
	findAntiDiagonalLine(4, position, nearbyLines[3]);

	for (int i = 0; i < 4; i++) {
		if (nearbyLines[i].size() < 5)
			continue;

		for (unsigned int j = 0; j < nearbyLines[i].size(); j++) {
				int count = 0;
				while (j < nearbyLines[i].size() && nearbyLines[i][j].second == _currentPlayer) {
					if (nearbyLines[i][j].second == _currentPlayer)
						count++;
					j++;
				}
				if (count >= 5 && !isAlignmentBreakable(nearbyLines[i], i))
					return true;
		}
	}
	return false;
}

bool	Gameplay::isThereDoubleThree(vector<pair<string, int>> nearbyLines[4]) {
	int 	FreeThree = 0;
	int 	opponent = (_currentPlayer == 1) ? 2 : 1;

	for (int i = 0; i < 4; i++) {
		if (nearbyLines[i].size() < 5)
			continue;
		for (unsigned int j = 0; j < nearbyLines[i].size(); j++) {
			if (nearbyLines[i][j].second == 0) {
				int count = 0;
				while (j < nearbyLines[i].size() && (nearbyLines[i][j].second == _currentPlayer || nearbyLines[i][j].second == 0)) {
					if (nearbyLines[i][j].second == _currentPlayer && j + 1 < nearbyLines[i].size() && nearbyLines[i][j + 1].second != opponent)
						count++;
					j++;
				}
				if (count >= 3)
					FreeThree++;
			}
		}
	}
	if (FreeThree >= 2)
		return true;
	return false;
}

bool	Gameplay::isCapturingMove(string position) {
	vector<pair<string, int>> nearbyLines[4];
	int 	opponent = (_currentPlayer == 1) ? 2 : 1;
	int		nbCaptures = 0;
	
	for (int i = 0; i < 4; i++) {
		pair<string, int> pair = make_pair(position, _currentPlayer);
		nearbyLines[i].push_back(pair);
	}
	findVerticalLine(3, position, nearbyLines[0]);
	findHorizontalLine(3, position, nearbyLines[1]);
	findDiagonalLine(3, position, nearbyLines[2]);
	findAntiDiagonalLine(3, position, nearbyLines[3]);
	
	for (int i = 0; i < 4; i++) {
		for (unsigned int j = 0; j < nearbyLines[i].size(); j++) {
			if (j < nearbyLines[i].size() - 3) {
				if (nearbyLines[i][j].second == _currentPlayer
				&& nearbyLines[i][j + 1].second == opponent
				&& nearbyLines[i][j + 2].second == opponent
				&& nearbyLines[i][j + 3].second == _currentPlayer) {
					nbCaptures++;
					_playerPositions.at(nearbyLines[i][j + 1].first) = 0;
					_playerPositions.at(nearbyLines[i][j + 2].first) = 0;
					_catchedStones[_currentPlayer] += 2;
				}
			}
		}
	}
	if (nbCaptures > 0)
		return true;
	return false;
}