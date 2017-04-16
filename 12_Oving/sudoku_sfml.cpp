#include<SFML\Graphics.hpp>
#include<iostream>
#include<string>
#include"Sudoku.h"

/*
Interface requirements:
Requires a class Sudoku located in Sudoku.h
Sudoku must have the following public member functions:
    Sudoku() - default constructor (you could also modify the code (@line 51) to accomodate other constructors
	loadFromFile(std::string) - loads a board from a text-file
	int getDimensions() - returns the dimensions of the board (edge size of a small square, denoted n in the excersice)
	void placeNumber(int row, int col, int num) throw(std::exception) - enters num into place denoted by row and col. Throws an std::exception (or its subclasses) at failure
	void undoMove() - undoes the last move. Does nothing if no moves have been made
	bool validCoordinates(int,int) - returns true if the specified coordinates exist in the game. COULD PROBABLY BE REMOVED
	int getNumber(int, int) - returns the nimber currently placed at the position specified by the arguments (row, col)

*/

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int tile_size = 32;
const int border_size = 2;
const int border_size_box = 4;

const sf::Color tileColor = sf::Color::White;
const sf::Color markedTileColor = sf::Color::Cyan;
const sf::Color failedTileColor = sf::Color::Red;
const sf::Color textColor = sf::Color::Black;
const sf::Color borderColor = sf::Color::Black;

int stringToInt(string str) {
	if (str.length() <= 0) return 0;
	return std::stoi(str);
}

void sfml_main() {
	sf::Font font;
	if (!font.loadFromFile("sansation.ttf")) {
		cout << "Fant ikke skrifttypen 'sansation.ttf'" << endl;
		exit(0);
	}


	sf::Clock timer;
	sf::Time inputTimeout = sf::milliseconds(250);

	Sudoku* game = new Sudoku();
	game->loadFromFile("board.txt");
	int dim = game->getDimensions();
	int row = 0, col = 0, num = 0;

	sf::RenderWindow window(sf::VideoMode(dim*dim * tile_size, dim*dim * tile_size), "Sudoku", sf::Style::Titlebar | sf::Style::Close);

	bool entering = false, timing = false, failed = false;
	string input = "";

	window.setFramerateLimit(15);
	while (window.isOpen()) {


		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				if (entering) {
					//should ignore nonumbers
					char c = (char)event.text.unicode;
					if (c >= '0' && c <= '9') {
						input += c;
						cout << input << endl;
						if (!timing) {
							timer.restart();
							timing = true;
						}
					}
				}
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case sf::Keyboard::Key::Escape:
				case sf::Keyboard::Key::Q:
					window.close();
					break;
				case sf::Keyboard::Key::Return:
					//add the typed number if somthing is to be entered
					if (entering) {
						if (input.length() > 0)
							num = stringToInt(input);
						else num = 0;

						cout << "Adding number to game" << endl;
						timing = entering = false;
						input = "";
						try {
							game->placeNumber(row, col, num);
						}
						catch (std::exception& e) {
							cout << e.what();
							failed = true;
							timer.restart();
						}
						/*if (!game->placeNumber(row, col, num)) {
							failed = true;
							timer.restart();
						}*/
					}
					break;
				case sf::Keyboard::Key::Left:
					if (entering && !timing) {
						if (col > 0) col--;
					}
					else entering = true;
					break;
				case sf::Keyboard::Key::Right:
					if (entering && !timing) {
						if (col < dim*dim - 1) col++;
					}
					else entering = true;
					break;
				case sf::Keyboard::Key::Up:
					if (entering && !timing) {
						if (row > 0) row--;
					}
					else entering = true;
					break;
				case sf::Keyboard::Key::Down:
					if (entering && !timing) {
						if (row < dim*dim - 1) row++;
					}
					else entering = true;
					break;
				}

				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Key::Z) {
					if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl))) {
						//undo the last move
						/*if (game->undoMove()) {
							cout << "Undid last move" << endl;
						}
						else {
							cout << "No moves to undo!" << endl;
						}*/
					}
				}

				if (event.key.code == sf::Keyboard::Key::C) {
					game->solve();
				}
				if (event.key.code == sf::Keyboard::Key::I) {
					if (entering) {
						//printSet(game->intersection(row, col));
					}
				}
				if (event.key.code == sf::Keyboard::Key::S) {
					//game->saveBoard("sudoku_temp.txt");
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (entering) {
						cout << "Canceling ongoing entry" << endl;
						input = "";
						entering = false;
						timing = false;
					}
					int temp_row = event.mouseButton.y / tile_size;
					int temp_col = event.mouseButton.x / tile_size;
					
					if (game->validCoordinates(temp_row, temp_col)) {
						/*
						cout << "Enter a number to put into the tile: ";
						cin >> num;
						game->addNumber(row, col, num);*/
						row = temp_row;
						col = temp_col;
						cout << "Entering new number. (row,col) = (" << row << "," << col << ")" << endl;

						entering = true;
						timing = false;


					}
				}
				break;
			}
		}

		if (timing && timer.getElapsedTime() >= inputTimeout) {
			//add the number(s) currently in the textbox

			if (input.length() > 0)
				num = stringToInt(input);
			else num = 0;

			cout << "Adding number to game" << endl;
			timing = entering = false;
			input = "";
			try {
				game->placeNumber(row, col, num);
			}
			catch (std::exception& e) {
				failed = true;
				timer.restart();
			}
		}
		if (failed && timer.getElapsedTime() >= inputTimeout) {
			failed = false;
		}

		window.clear();
		//draw
		for (int y = 0; y < dim*dim; y++) {
			for (int x = 0; x < dim*dim; x++) {
				const int tile_x = x*tile_size;
				const int tile_y = y*tile_size;

				sf::RectangleShape tile;
				tile.setSize(sf::Vector2f(tile_size - border_size, tile_size - border_size));

				if (entering && x == col && y == row)
					tile.setFillColor(markedTileColor);
				else if (failed && x == col && y == row)
					tile.setFillColor(failedTileColor);
				else
					tile.setFillColor(tileColor);

				tile.setPosition(tile_x + border_size / 2.0, tile_y + border_size / 2.0);

				window.draw(tile);

				//TODO: add thicker borders (sf::RectangleShape?) around the boxes

				sf::Text text;
				text.setStyle(sf::Text::Regular);
				text.setCharacterSize(tile_size / 2.0);

				int num = game->getNumber(y, x);
				if (num != 0) {
					text.setString(std::to_string(num));
					text.setFillColor(sf::Color::Black);
				}

				text.setFont(font);

				sf::FloatRect text_rect = text.getLocalBounds();
				text.setOrigin(text_rect.left + text_rect.width / 2.0,
					text_rect.top + text_rect.height / 2.0);
				text.setPosition(tile_x + tile_size / 2.0, tile_y + tile_size / 2.0);

				window.draw(text);
			}
		}
		//Draw borders between the boxes, need n-1 x 2borders
		for (int i = 1; i <= dim - 1; i++) {
			sf::RectangleShape horizontalBorder;
			sf::RectangleShape verticalBorder;

			const int border_height = dim*dim*tile_size;
			const int border_width = border_size_box;

			int xpos = tile_size * dim * dim / 2.0;
			int ypos = i*dim*tile_size;

			horizontalBorder.setSize(sf::Vector2f(border_height, border_width));
			horizontalBorder.setOrigin(border_height / 2.0, border_width / 2.0);
			horizontalBorder.setPosition(xpos, ypos);
			horizontalBorder.setFillColor(borderColor);

			xpos = i*dim*tile_size;
			ypos = tile_size * dim * dim / 2.0;

			verticalBorder.setSize(sf::Vector2f(border_width, border_height));
			verticalBorder.setOrigin(border_width / 2.0, border_height / 2.0);
			verticalBorder.setPosition(xpos, ypos);
			verticalBorder.setFillColor(borderColor);

			window.draw(horizontalBorder);
			window.draw(verticalBorder);

		}



		window.display();
	}

	delete game;
}