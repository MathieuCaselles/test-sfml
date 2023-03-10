#include <engine/test.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

int main()
{
    // Create the main window
    sf::RectangleShape rect({ 100, 100});
    rect.setFillColor(sf::Color(100, 250, 50));
    rect.setPosition({400, 400});
    
    sf::RenderWindow window = engine::getWindow("SFML window");
    auto time = std::chrono::high_resolution_clock::now();
    sf::Clock chrono;
    bool left = false;
    while (window.isOpen())
    {
        auto newTime = std::chrono::high_resolution_clock::now();
        auto dt =  std::chrono::duration<double>(newTime - time);
        time = newTime;
        chrono.restart();
        // Process events

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                if ( event.key.code == sf::Keyboard::J) {
                    left = true;
                }
                if ( event.key.code == sf::Keyboard::M) {
                    left = false;
                }
            }
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f move({350.0, 0});

        auto [x, y] = rect.getPosition();

        if (x < 0 || ( !left && x > window.getSize().x - rect.getSize().x))  left = !left;

        if ( left  ) {
          move.x *= -1;
        }
        std::cout << dt.count()	 << "\n";
        rect.move(move * static_cast<float>(dt.count()));



        // Clear screen
        window.clear();
        window.draw(rect);
        // Update the window
        window.display();

    }
    return EXIT_SUCCESS;
}
