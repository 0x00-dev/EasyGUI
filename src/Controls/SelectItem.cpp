//
// Created by strannyi_tip on 23.02.2020.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Controls/SelectItem.hpp>

/**
 * @copydoc sf::SelectItem::show()
 */
void SelectItem::show() {
    is_visible = true;
}

/**
 * @copydoc sf::SelectItem::hide()
 */
void SelectItem::hide() {
    is_visible = true;
}

/**
 * @copydoc sf::SelectItem::isVisible()
 */
bool SelectItem::isVisible() {
    return is_visible;
}

/**
 * @copydoc sf::SelectItem::handle()
 */
void SelectItem::handle(sf::Event event, sf::RenderWindow *window) {
    is_visible = parent->isVisible();
}

/**
 * @copydoc sf::SelectItem::position()
 */
void SelectItem::setPosition(sf::Vector2f position) {
    offset = position;
}

/**
 * @copydoc sf::SelectItem::setSize()
 */
void SelectItem::setSize(sf::Vector2f new_size) {
    size = new_size;
}

/**
 * @copydoc sf::SelectItem::getEntity()
 */
sf::RectangleShape *SelectItem::getEntity() {
    return entity;
}

/**
 * @copydoc sf::SelectItem::draw()
 */
void SelectItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (is_visible) {
        target.draw(*entity);
    }
}
