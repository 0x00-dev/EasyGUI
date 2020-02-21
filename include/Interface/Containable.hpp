//
// Created by strannyi_tip on 21.02.2020.
//

#ifndef EASYGUI_CONTAINABLE_HPP
#define EASYGUI_CONTAINABLE_HPP

#include <SFML/Graphics/Drawable.hpp>

class Containable : public sf::Drawable {
public:
    /**
     * Показать.
     */
    virtual void show() = 0;

    /**
     * Скрыть.
     */
    virtual void hide() = 0;
};

#endif //EASYGUI_CONTAINABLE_HPP
