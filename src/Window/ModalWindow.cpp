//
// Created by strannyi_tip on 21.02.2020.
//

#include <Window/ModalWindow.hpp>
#include <Core/Definitions.hpp>
#include <Core/Messenger.hpp>

/**
 * {@copydoc ModalWindow::ModalWindow()}
 */
ModalWindow::ModalWindow(const ModalWindow::Configuration &config) {
    configure(config);
}

/**
 * {@copydoc ModalWindow::configure()}
 */
void ModalWindow::configure(const ModalWindow::Configuration &config) {
    size = config.size;
    bg_color = config.bg_color;
    title = config.title;
    coords = config.coords;
    font_file = config.font_file;

    prepareFont();
    prepareEntity();
    prepareTitle();
}

/**
 * {@copydoc ModalWindow::prepareFont()}
 */
void ModalWindow::prepareFont() {
    font = new sf::Font;
    if (!font->loadFromFile(EasyGUI::RESOURCES + font_file)) {
        Messenger::send("Не удалось загрузить шрифт ");
        Messenger::send(font_file + "\n", "red");
    }
}

/**
 * {@copydoc ModalWindow::prepareEntity()}
 */
void ModalWindow::prepareEntity() {
    entity = new sf::RectangleShape;
    entity->setSize(size);
    entity->setFillColor(bg_color);
    entity->setPosition(coords);
}

/**
 * {@copydoc ModalWindow::prepareTitle()}
 */
void ModalWindow::prepareTitle() {
    text_entity = new sf::Text;
    auto title_font = new sf::Font;
    if (!title_font->loadFromFile(EasyGUI::RESOURCES + title.font_file)) {
        Messenger::send("Не удалось загрузить шрифт ");
        Messenger::send(font_file + "\n", "red");
    }
    text_entity->setFillColor(title.color);
    text_entity->setPosition({coords.x + title.offset.x, coords.y + title.offset.y});
    text_entity->setFont(*title_font);
    text_entity->setString(title.text);
}

/**
 * {@copydoc ModalWindow::show()}
 */
void ModalWindow::show() {
    is_opened = true;
}

/**
 * {@copydoc ModalWindow::hide()}
 */
void ModalWindow::hide() {
    is_opened = false;
}

/**
 * {@copydoc ModalWindow::handle()}
 */
void ModalWindow::handle(sf::Event event, sf::RenderWindow *window) {
    for (const auto &item: items_container) {
        item->handle(event, window);
    }
}

/**
 * {@copydoc ModalWindow::draw()}
 */
void ModalWindow::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (is_opened) {
        target.draw(*entity, states);
        target.draw(*text_entity);
        for (const auto &control: controls) {
            target.draw(*control.second);
        }
        for (const auto &item: items_container) {
            target.draw(*item);
        }
    }
}

/**
 * {@copydoc ModalWindow::add()}
 */
ModalWindow *ModalWindow::add(sf::Vector2f item_offset, Displayable *element) {
    element->setPosition({coords.x + item_offset.x, coords.y + item_offset.y});
    items_container.push_back(element);

    return this;
}

/**
 * {@copydoc ModalWindow::getEntity()}
 */
sf::RectangleShape *ModalWindow::getEntity() {
    return entity;
}

/**
 * {@copydoc ModalWindow::isVisible()}
 */
bool ModalWindow::isVisible() {
    return is_opened;
}

/**
 * {@copydoc Displayable::setPosition()}
 */
void ModalWindow::setPosition(sf::Vector2f position) {
    coords = position;
}
