#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <map>

#include "non_copyable.hpp"

namespace town
{
    class FontManager : private NonCopyable
    {
        public:
            typedef std::map<std::string, std::unique_ptr<sf::Font>> FontMap;

            bool load_font(const std::string &name, const std::string &filename);

            const FontMap &fonts() const;
            const sf::Font *font(const std::string &name) const;

        private:

            FontMap _fonts;
    };
}

