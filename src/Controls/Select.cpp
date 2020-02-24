//
// Created by strannyi_tip on 23.02.2020.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Controls/Select.hpp>
#include <Core/Messenger.hpp>
#include <Core/Definitions.hpp>

/**
 * @copydoc Select::Select()
 */
Select::Select(const Select::Configuration &configuration) {
    bg_color = configuration.bg_color;
    size = configuration.size;
    offset = configuration.offset;
    image_src = configuration.image_src;
    label = configuration.label;

    prepareEntity();
}

/**
 * @copydoc Select::show()
 */
void Select::show() {
    is_visible = true;
}

/**
 * @copydoc Select::hide()
 */
void Select::hide() {
    is_visible = false;
}

/**
 * @copydoc Select::isVisible()
 */
bool Select::isVisible() {
    return is_visible;
}

/**
 * @copydoc Select::handle()
 */
void Select::handle(sf::Event event, sf::RenderWindow *window) {

}

/**
 * @copydoc Select::setPosition()
 */
void Select::setPosition(sf::Vector2f position) {
    offset = position;
}

/**
 * @copydoc Select::setSize()
 */
void Select::setSize(sf::Vector2f new_size) {
    size = new_size;
}

/**
 * @copydoc Select::getEntity()
 */
sf::RectangleShape *Select::getEntity() {
    return entity;
}

/**
 * @copydoc Select::getEntity()
 */
Select *Select::add(SelectItem *item) {
    container.emplace_back(item);

    return this;
}

/**
 * @copydoc Select::draw()
 */
void Select::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (is_visible && is_opened) {
        target.draw(*entity);
        for (const auto &item : container) {
            item->show();
            target.draw(*item);
        }
    }
    if (!is_opened && selected != nullptr) {
        target.draw(*selected);
    } else {
        target.draw(*label_entity);
    }
}

/**
 * @copydoc Select::prepareEntity()
 */
void Select::prepareEntity() {
    entity = new sf::RectangleShape;
    if (!image_src.empty()) {
        texture = new sf::Texture;
        if (!texture->loadFromFile(EasyGUI::RESOURCES + image_src)) {
            Messenger::send("Не удалось загрузить изображение ");
            Messenger::send(image_src + "\n", "red");
        }
        entity->setTexture(texture);
    } else {
        entity->setFillColor(bg_color);
    }
    entity->setSize(size);
    entity->setPosition(offset);
}
