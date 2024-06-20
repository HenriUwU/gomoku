/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gameplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:00:34 by hsebille          #+#    #+#             */
/*   Updated: 2024/06/20 14:00:36 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.hpp"

using namespace std;

Gameplay::Gameplay() {
	for (int i = 0; i < 19; i++) {
		int character = 'A' + i;
		for (int j = 1; j < 20; j++) {
			string position = string(1, character) + to_string(j);
			_playerPositions.insert(pair<string, int>(position, 0));
		}
	}
	
	_currentPlayer = 1;
    _gridPosition = sf::Vector2f(525, 48);
    _gridSize = 868;
    _cellSize = _gridSize / 19.0f;
	
	if (!_blackStoneTexture.loadFromFile("assets/images/stones/blackStoneTexture.png"))
		cerr << "Error while loading the blackStoneTexture file." << endl;
	if (!_whiteStoneTexture.loadFromFile("assets/images/stones/whiteStoneTexture.png"))
		cerr << "Error while loading the whiteStoneTexture file." << endl;
	if (!_coralStoneTexture.loadFromFile("assets/images/stones/coralStoneTexture.png"))
		cerr << "Error while loading the coralStoneTexture file." << endl;
	if (!_darkGreenStoneTexture.loadFromFile("assets/images/stones/darkGreenStoneTexture.png"))
		cerr << "Error while loading the darkGreenStoneTexture file." << endl;
	if (!_lightGreenStoneTexture.loadFromFile("assets/images/stones/lightGreenStoneTexture.png"))
		cerr << "Error while loading the lightGreenStoneTexture file." << endl;
	if (!_violetStoneTexture.loadFromFile("assets/images/stones/violetStoneTexture.png"))
		cerr << "Error while loading the violetStoneTexture file." << endl;
	if (!_yellowStoneTexture.loadFromFile("assets/images/stones/yellowStoneTexture.png"))
		cerr << "Error while loading the yellowStoneTexture file." << endl;
	if (!_fluoYellowStoneTexture.loadFromFile("assets/images/stones/fluoYellowStoneTexture.png"))
		cerr << "Error while loading the fluoYellowStoneTexture file." << endl;
	if (!_pinkStoneTexture.loadFromFile("assets/images/stones/pinkStoneTexture.png"))
		cerr << "Error while loading the pinkStoneTexture file." << endl;
	if (!_greenStoneTexture.loadFromFile("assets/images/stones/greenStoneTexture.png"))
		cerr << "Error while loading the greenStoneTexture file." << endl;
	if (!_indigoStoneTexture.loadFromFile("assets/images/stones/indigoStoneTexture.png"))
		cerr << "Error while loading the indigoStoneTexture file." << endl;
	if (!_orangeStoneTexture.loadFromFile("assets/images/stones/orangeStoneTexture.png"))
		cerr << "Error while loading the orangeStoneTexture file." << endl;
	if (!_redStoneTexture.loadFromFile("assets/images/stones/redStoneTexture.png"))
		cerr << "Error while loading the redStoneTexture file." << endl;
	if (!_salmonStoneTexture.loadFromFile("assets/images/stones/salmonStoneTexture.png"))
		cerr << "Error while loading the salmonStoneTexture file." << endl;
	if (!_turquoiseGreenStoneTexture.loadFromFile("assets/images/stones/turquoiseGreenStoneTexture.png"))
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

void Gameplay::mouseClick(const sf::Event::MouseButtonEvent& mouseEvent, sf::RenderWindow& window) {
    sf::Vector2i mousePos(mouseEvent.x, mouseEvent.y);
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

    if (worldPos.x >= _gridPosition.x && worldPos.x <= _gridPosition.x + _gridSize &&
        worldPos.y >= _gridPosition.y && worldPos.y <= _gridPosition.y + _gridSize) {

        // Calculate grid coordinates
        float relativeX = worldPos.x - _gridPosition.x;
        float relativeY = worldPos.y - _gridPosition.y;
        int col = static_cast<int>(relativeX / _cellSize);
        int row = static_cast<int>(relativeY / _cellSize);

        // Convert grid coordinates to position string (e.g., "A1", "B2", etc.)
        char character = 'A' + col;
        string position = string(1, character) + to_string(row + 1); // +1 to convert to 1-based index

        // Place stone if the position is legal
    }
}

void	Gameplay::mouseHover(sf::RenderWindow &window, Bitboard &bitboard) {
	if (stonesColor == BlackAndWhite) {
		_firstStone.setTexture(_blackStoneTexture);
		_secondStone.setTexture(_whiteStoneTexture);
	} else if (stonesColor == GreenAndRed) {
		_firstStone.setTexture(_greenStoneTexture);
		_secondStone.setTexture(_redStoneTexture);
	} else if (stonesColor == SalmonAndCoral) {
		_firstStone.setTexture(_salmonStoneTexture);
		_secondStone.setTexture(_coralStoneTexture);
	} else if (stonesColor == PinkAndFluoYellow) {
		_firstStone.setTexture(_pinkStoneTexture);
		_secondStone.setTexture(_fluoYellowStoneTexture);
	} else if (stonesColor == BlackAndYellow) {
		_firstStone.setTexture(_blackStoneTexture);
		_secondStone.setTexture(_yellowStoneTexture);
	} else if (stonesColor == OrangeAndViolet) {
		_firstStone.setTexture(_orangeStoneTexture);
		_secondStone.setTexture(_violetStoneTexture);
	} else if (stonesColor == DarkGreenAndLightGreen) {
		_firstStone.setTexture(_darkGreenStoneTexture);
		_secondStone.setTexture(_lightGreenStoneTexture);
	} else if (stonesColor == TurquoiseGreenAndIndigo) {
		_firstStone.setTexture(_turquoiseGreenStoneTexture);
		_secondStone.setTexture(_indigoStoneTexture);
	}

	float cellSize = 48;
	std::pair <unsigned int, unsigned int>	startPoint = std::make_pair(527, 50);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);	
	if (mousePosition.x > 525 + 868 || mousePosition.y > 48 + 868)
		return ;
	
	float xIndex = std::round((mousePosition.x - startPoint.first) / cellSize);
	float yIndex = std::round((mousePosition.y - startPoint.second) / cellSize);

	sf::Vector2f nearestIntersection(startPoint.first + xIndex * cellSize, startPoint.second + yIndex * cellSize);
	_firstStone.setPosition(nearestIntersection.x - 13, nearestIntersection.y - 13);
	_secondStone.setPosition(nearestIntersection.x - 13, nearestIntersection.y - 13);

	sf::Vector2i stonePos(nearestIntersection.x, nearestIntersection.y);

	sf::Vector2f worldPos = window.mapPixelToCoords(stonePos);
		
	float relativeX = worldPos.x - startPoint.first;
    float relativeY = worldPos.y - startPoint.second;

	int col = static_cast<int>(relativeX / _cellSize);
    int row = static_cast<int>(relativeY / _cellSize);

	if (col >= 0 && col < 19 && row >= 0 && row < 19) {
		if (bitboard.getBit(col, row) != 0)
			return ;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		std::cout << "Mouse clicked on grid position: (" << col << ", " << row << ")" << std::endl;
		if (col >= 0 && col < 19 && row >= 0 && row < 19) {
			if (bitboard.placeStone(col, row, _currentPlayer)) {
				if (_currentPlayer == 1)
					_currentPlayer = 2;
				else
					_currentPlayer = 1;
			}
		}
		bitboard.printBoard();
		sf::sleep(sf::milliseconds(100));
	}
	if (_currentPlayer == 1)
		window.draw(_firstStone);
	else
		window.draw(_secondStone);
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