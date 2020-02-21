//
// Created by strannyi_tip on 21.02.2020.
//

#ifndef EASYGUI_EVENTABLE_HPP
#define EASYGUI_EVENTABLE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

/**
 * Событийный.
 */
class Eventable {
public:
    /**
     * Присваивать.
     *
     * @param event Событие
     */
    virtual void handle(sf::Event event, sf::RenderWindow *window) = 0;
};

#endif //EASYGUI_EVENTABLE_HPP
