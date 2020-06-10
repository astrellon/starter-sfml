#pragma once

#include <SFML/Graphics.hpp>

namespace town
{
    class Engine;

    class GameSession
    {
        public:
            GameSession(Engine *engine);
            ~GameSession();

            void onResize(sf::Vector2f area);

            void update(sf::Time dt);
            void draw(sf::RenderTarget &target);

        private:
            Engine *_engine;
            sf::View _camera;
    };
} // town