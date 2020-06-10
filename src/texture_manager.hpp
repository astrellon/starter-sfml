#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <map>

#include "non_copyable.hpp"

namespace town
{
    class TextureManager : private NonCopyable
    {
        public:
            typedef std::map<std::string, std::unique_ptr<sf::Texture>> TextureMap;

            bool loadTexture(const std::string &name, const std::string &filename);

            const sf::Texture *texture(const std::string &name) const;
            const TextureMap &textures() const;

        private:

            TextureMap _textures;
    };
}

