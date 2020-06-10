#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "src/engine.hpp"
#include "src/font_manager.hpp"
#include "src/tiles.hpp"
#include "src/game_session.hpp"
#include "src/particle_system.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "Starter");
    window.setVerticalSyncEnabled(true);

    town::Engine engine(window);
    engine.spriteScale(4.0f);

    auto textureManager = engine.textureManager();

    engine.fontManager()->load_font("sans", "data/LiberationSans-Regular.ttf");
    auto sansFont = engine.fontManager()->font("sans");

    auto spriteSize = static_cast<uint>(engine.spriteSize());
    auto spriteScale = engine.spriteScale();

    auto gameSession = engine.startGameSession();

    sf::Text text("hello", *sansFont);
    text.setCharacterSize(72);

    while (window.isOpen())
    {
        engine.processEvents();
        engine.preUpdate();
        engine.update();
        engine.draw();

        window.draw(text);
        window.display();
    }

    return 0;
}
