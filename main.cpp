#include <SFML/Graphics.hpp>

#define LENGHT 1080
#define HEIGHT 720
#define FPS 30

#define NB_SQUARES_LENGTH 20
#define NB_SQUARES_HEIGHT 20

#define SIZE_SQUARE 20
#define MARGIN_BETWEEN_SQUARES 2

using namespace std;

void drawSquare(sf::RenderWindow &window, sf::Vector2f size, sf::Vector2f position, sf::Color color);

int main(void)
{
    sf::RenderWindow window(sf::VideoMode({LENGHT, HEIGHT}), "Ray-casting");
    window.setFramerateLimit(FPS);

    sf::Vector2f playerPosition = sf::Vector2f(200, 200);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();


        //Dessine le sol
        drawSquare (window, sf::Vector2f(
            NB_SQUARES_LENGTH*(SIZE_SQUARE+MARGIN_BETWEEN_SQUARES)-MARGIN_BETWEEN_SQUARES,
            NB_SQUARES_HEIGHT*(SIZE_SQUARE+MARGIN_BETWEEN_SQUARES)-MARGIN_BETWEEN_SQUARES),
            sf::Vector2f(0,0), sf::Color::Red
        );

        //Dessine les cases
        for (int i = 0; i < NB_SQUARES_LENGTH; i++)
        {
            for (int j = 0; j < NB_SQUARES_HEIGHT; j++)
            {
                drawSquare(window, 
                    sf::Vector2f(SIZE_SQUARE,SIZE_SQUARE), 
                    sf::Vector2f((SIZE_SQUARE+MARGIN_BETWEEN_SQUARES)*i,(SIZE_SQUARE+MARGIN_BETWEEN_SQUARES)*j),
                    sf::Color::White);
            }
        }

        //Dessine player
        sf::CircleShape drawPlayer(10);
        drawPlayer.setPosition(playerPosition);
        drawPlayer.setFillColor(sf::Color::Green);
        window.draw(drawPlayer);

        window.display();
    
    } 
    return 0;
}


void drawSquare(sf::RenderWindow &window, sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
    sf::RectangleShape square(size);
    square.setPosition(position);
    square.setFillColor(color);
    window.draw(square);
}