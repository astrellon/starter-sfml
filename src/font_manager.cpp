#include "font_manager.hpp"

#include <iostream>

namespace town
{
    bool FontManager::load_font(const std::string &name, const std::string &filename)
    {
        if (name.empty())
        {
            return false;
        }

        auto font = std::make_unique<sf::Font>();
        if (!font->loadFromFile(filename))
        {
            return false;
        }

        _fonts.emplace(name, std::move(font));
        return true;
    }

    const FontManager::FontMap &FontManager::fonts() const
    {
        return _fonts;
    }

    const sf::Font *FontManager::font(const std::string &name) const
    {
        auto find = _fonts.find(name);
        if (find == _fonts.end())
        {
            return nullptr;
        }

        return find->second.get();
    }
}

