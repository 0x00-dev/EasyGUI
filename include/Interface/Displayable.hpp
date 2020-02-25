//
// Created by strannyi_tip on 21.02.2020.
//

#ifndef EASYGUI_DISPLAYABLE_HPP
#define EASYGUI_DISPLAYABLE_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "Containable.hpp"
#include "Eventable.hpp"

/**
 * Отображаемый.
 */
class Displayable : public Containable, public Eventable {
public:
    /**
     * @copydoc Containable::show()
     */
    virtual void show() = 0;

    /**
     * @copydoc Containable::hide()
     */
    virtual void hide() = 0;

    /**
     * @copydoc Containable::isVisible()
     */
    virtual bool isVisible() = 0;

    /**
     * @copydoc Eventable::handle()
     */
    virtual void handle(sf::Event event, sf::RenderWindow *window) = 0;

    /**
     * Установить расположение.
     *
     * @param position Расположение
     */
    virtual void setPosition(sf::Vector2f position) = 0;

    /**
     * Установить размер.
     *
     * @param new_size Размер
     */
    virtual void setSize(sf::Vector2f new_size) = 0;

    /**
     * Получить сущность.
     *
     * @return *Drawable
     */
    virtual sf::RectangleShape *getEntity() = 0;
};
#endif //EASYGUI_DISPLAYABLE_HPP