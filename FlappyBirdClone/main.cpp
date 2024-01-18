#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace sf;
using namespace std;

void showWelcomePage(sf::RenderWindow& window) {
    // Code to display welcome page elements
    // You can use SFML shapes, text, and other elements to create your welcome page
    // For simplicity, let's just display a title and instructions.

    sf::Font font;
    if (!font.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/fonts/flappy-font.ttf")) {
        // Handle font loading error
        return;
    }
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/images/background.png"))
        return;
    sf::Sprite sprite(texture);
    sprite.setScale(static_cast<float>(window.getSize().x) / texture.getSize().x,
                    static_cast<float>(window.getSize().y) / texture.getSize().y);

    sf::Text title("Flappy Bird", font, 50);
    title.setPosition(350, 150);

    sf::Text instructions("Press Enter to start", font, 30);
    instructions.setPosition(350, 300);

    window.draw(sprite);
    window.draw(title);
    window.draw(instructions);
    window.display();

    // Wait for Enter key press to go to the main menu
    sf::Event event;
    while (window.waitEvent(event)) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
            return; // Exit the welcome page function
        }
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }
    }
}

void showMenu(sf::RenderWindow& window) {
    // Code to display menu options, handle input, etc.
    sf::Font font;
    if (!font.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/fonts/flappy-font.ttf")) {
        // Handle font loading error
        return;
    }
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/images/background.png"))
        return;
    sf::Sprite sprite(texture);
    sprite.setScale(static_cast<float>(window.getSize().x) / texture.getSize().x,
                    static_cast<float>(window.getSize().y) / texture.getSize().y);

    sf::Text title("Main Menu", font, 50);
    title.setPosition(350, 150);

    sf::Text soloOption("1. Play Solo", font, 30);
    soloOption.setPosition(350, 250);

    sf::Text multiplayerOption("2. Play Multiplayer", font, 30);
    multiplayerOption.setPosition(350, 300);

    int selectedOption = 1; // Default selection

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        selectedOption = (selectedOption == 1) ? 2 : 1;
                        break;

                    case sf::Keyboard::Down:
                        selectedOption = (selectedOption == 2) ? 1 : 2;
                        break;

                    case sf::Keyboard::Enter:
                        // User pressed Enter, act based on the selected option
                        if (selectedOption == 1) {
                            // Start solo game
                            std::cout << "Starting Solo Game" << std::endl;
                        } else if (selectedOption == 2) {
                            // Start multiplayer game
                            std::cout << "Starting Multiplayer Game" << std::endl;
                        }
                        return; // Exit the menu function
                }
            }
        }

        window.clear();
        window.draw(sprite);
        window.draw(title);
        // Draw the solo option with a different color if selected
        soloOption.setFillColor((selectedOption == 1) ? sf::Color::Red : sf::Color::White);
        window.draw(soloOption);
        // Draw the multiplayer option with a different color if selected
        multiplayerOption.setFillColor((selectedOption == 2) ? sf::Color::Red : sf::Color::White);
        window.draw(multiplayerOption);
        window.display();
        
    }
}

// rect rect collision detection helper function
bool collides(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
	if (x1 + w1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 <= y2 + h2) {
		return true;
	}
	return false;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Flappy Bird Clone");
    window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	srand(time(0));
    // all sounds and their buffers will rest in this singleton struct
	struct Sounds {
		SoundBuffer chingBuffer;
		SoundBuffer hopBuffer;
		SoundBuffer dishkBuffer;
		Sound ching;
		Sound hop;
		Sound dishk;
	} sounds;

    // load sounds
	sounds.chingBuffer.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/audio/audio_score.wav");
	sounds.hopBuffer.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/audio/audio_flap.wav");
	sounds.dishkBuffer.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/audio/audio_crash.wav");
	sounds.ching.setBuffer(sounds.chingBuffer);
	sounds.hop.setBuffer(sounds.hopBuffer);
	sounds.dishk.setBuffer(sounds.dishkBuffer);

    struct Textures {
		Texture flappy[3];
		Texture pipe;
		Texture background;
		Texture gameover;
	} textures;

    // load textures
	textures.background.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/images/background.png");
	textures.pipe.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/images/pipe.png");
	textures.gameover.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/images/gameover.png");
	textures.flappy[0].loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/images/flappy1.png");
	textures.flappy[1].loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/images/flappy2.png");
	textures.flappy[2].loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/images/flappy3.png");

    struct Flappy {
		double v = 0;
		int frame = 0;
		Sprite sprite;
	} flappy;

    // initial position, scale
	flappy.sprite.setPosition(250, 300);
	flappy.sprite.setScale(2, 2);

    // resizable array of sprites representing pipes
	vector<Sprite> pipes;

    // waiting = game not started yet
	// started = playing
	// gameover = game is over
	enum GameState { waiting,
					 started,
					 gameover };

    // game settings in singleton game struct
	// frames counts total frames passed since the beginning of time
	struct Game {
		int score = 0;
		int highscore = 0;
		int frames = 0;
		GameState gameState = waiting;
		Sprite background[3];
		Sprite gameover;
		Text pressEnter;
		Text scoreText;
		Text highscoreText;
		Font font;
	} game;

    // load font, set positions, scales etc
	game.font.loadFromFile("/Users/amirali/Desktop/FlappyBirdClone/fonts/flappy-font.ttf");
	game.background[0].setTexture(textures.background);
	game.background[1].setTexture(textures.background);
	game.background[2].setTexture(textures.background);
	game.background[0].setScale(1.15625, 1.171875);
	game.background[1].setScale(1.15625, 1.171875);
	game.background[2].setScale(1.15625, 1.171875);
	game.background[1].setPosition(333, 0);
	game.background[2].setPosition(666, 0);
	game.gameover.setTexture(textures.gameover);
	game.gameover.setOrigin(192 / 2, 42 / 2);
	game.gameover.setPosition(500, 125);
	game.gameover.setScale(2, 2);
	game.pressEnter.setString("Press Enter to continue");
	game.pressEnter.setFont(game.font);
	game.pressEnter.setFillColor(Color::White);
	game.pressEnter.setCharacterSize(50);
	game.pressEnter.setOrigin(game.pressEnter.getLocalBounds().width / 2, 0);
	game.pressEnter.setPosition(500, 250);
	game.scoreText.setFont(game.font);
	game.scoreText.setFillColor(Color::White);
	game.scoreText.setCharacterSize(75);
	game.scoreText.move(30, 0);
	game.highscoreText.setFont(game.font);
	game.highscoreText.setFillColor(Color::White);
	game.highscoreText.move(30, 80);

    // Show the menu before entering the game loop
    showWelcomePage(window);
    showMenu(window);

    // main loop
	while (window.isOpen()) {


		// update score
		flappy.sprite.setTexture(textures.flappy[1]);
		game.scoreText.setString(to_string(game.score));
		game.highscoreText.setString("HIGHEST SCORE " + to_string(game.highscore));

		// update flappy
		float fx = flappy.sprite.getPosition().x;
		float fy = flappy.sprite.getPosition().y;
		float fw = 34 * flappy.sprite.getScale().x;
		float fh = 24 * flappy.sprite.getScale().y;

		// flap the wings if playing
		if (game.gameState == waiting || game.gameState == started) {

			// change the texture once in 6 frames
			if (game.frames % 6 == 0) {
				flappy.frame += 1;
			}
			if (flappy.frame == 3) {
				flappy.frame = 0;
			}
		}

		flappy.sprite.setTexture(textures.flappy[flappy.frame]);

		// move flappy
		if (game.gameState == started) {
			flappy.sprite.move(0, flappy.v);
			flappy.v += 0.5;
		}

		// if hits ceiling, stop ascending
		// if out of screen, game over
		if (game.gameState == started) {
			if (fy < 0) {
				flappy.sprite.setPosition(250, 0);
				flappy.v = 0;
			} else if (fy > 600) {
				flappy.v = 0;
				game.gameState = gameover;
				sounds.dishk.play();
			}
		}

		// count the score
		for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
			if (game.gameState == started && (*itr).getPosition().x == 250) {
				game.score++;
				sounds.ching.play();

				if (game.score > game.highscore) {
					game.highscore = game.score;
				}

				break;
			}
		}

		// generate pipes
		if (game.gameState == started && game.frames % 150 == 0) {
			int r = rand() % 275 + 75;
			int gap = 150;

			// lower pipe
			Sprite pipeL;
			pipeL.setTexture(textures.pipe);
			pipeL.setPosition(1000, r + gap);
			pipeL.setScale(2, 2);

			// upper pipe
			Sprite pipeU;
			pipeU.setTexture(textures.pipe);
			pipeU.setPosition(1000, r);
			pipeU.setScale(2, -2);

			// push to the array
			pipes.push_back(pipeL);
			pipes.push_back(pipeU);
		}

		// move pipes
		if (game.gameState == started) {
			for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
				(*itr).move(-3, 0);
			}
		}

		// remove pipes if offscreen
		if (game.frames % 100 == 0) {
			vector<Sprite>::iterator startitr = pipes.begin();
			vector<Sprite>::iterator enditr = pipes.begin();

			for (; enditr != pipes.end(); enditr++) {
				if ((*enditr).getPosition().x > -104) {
					break;
				}
			}

			pipes.erase(startitr, enditr);
		}

		// collision detection
		if (game.gameState == started) {
			for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {

				float px, py, pw, ph;

				if ((*itr).getScale().y > 0) {
					px = (*itr).getPosition().x;
					py = (*itr).getPosition().y;
					pw = 52 * (*itr).getScale().x;
					ph = 320 * (*itr).getScale().y;
				} else {
					pw = 52 * (*itr).getScale().x;
					ph = -320 * (*itr).getScale().y;
					px = (*itr).getPosition().x;
					py = (*itr).getPosition().y - ph;
				}

				if (collides(fx, fy, fw, fh, px, py, pw, ph)) {
					game.gameState = gameover;
					sounds.dishk.play();
				}
			}
		}

		// events
		Event event;
		while (window.pollEvent(event)) {

			// bye bye
			if (event.type == Event::Closed) {
				window.close();
			}
			
			// flap
			else if (event.type == Event::KeyPressed &&
					   event.key.code == Keyboard::Space) {
				if (game.gameState == waiting) {
					game.gameState = started;
				}

				if (game.gameState == started) {
					flappy.v = -8;
					sounds.hop.play();
				}

			// restart
			} else if (event.type == Event::KeyPressed &&
					   event.key.code == Keyboard::Enter &&
					   game.gameState == gameover) {
				game.gameState = waiting;
				flappy.sprite.setPosition(250, 300);
				game.score = 0;
				pipes.clear();
			}
		}

		// clear, draw, display
		window.clear();
		window.draw(game.background[0]);
		window.draw(game.background[1]);
		window.draw(game.background[2]);
		window.draw(flappy.sprite);


		// draw pipes
		for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
			window.draw(*itr);
		}

		// draw scores
		window.draw(game.scoreText);
		window.draw(game.highscoreText);

		// gameover. press Enter to continue
		if (game.gameState == gameover) {
			window.draw(game.gameover);

			if (game.frames % 60 < 30) {
				window.draw(game.pressEnter);
			}
		}
		window.display();

		// dont forget to update total frames
		game.frames++;
	}

	return 0;
}
