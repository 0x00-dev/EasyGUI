//
// Created by strannyi_tip on 23.02.2020.
//

#include <Controls/Input.hpp>
#include <Core/Definitions.hpp>
#include <Core/Messenger.hpp>
#include <SFML/System/InputStream.hpp>
#include <codecvt>
#include <sstream>
#include <iostream>

/**
 * @copydoc Input::Input()
 */
Input::Input(const Input::Configuration &configuration) {
    size = configuration.size;
    offset = configuration.offset;
    placeholder = configuration.placeholder;
    fg_color = configuration.fg_color;
    bg_color = configuration.bg_color;
    font_size = configuration.font_size;

    prepareEntity();
    preparePlaceholder();
}

/**
 * @copydoc Input::show()
 */
void Input::show() {
    is_visible = true;
}

/**
 * @copydoc Input::hide()
 */
void Input::hide() {
    is_visible = false;
}

/**
 * @copydoc Input::isVisible()
 */
bool Input::isVisible() {
    return is_visible;
}

/**
 * @copydoc Input::handle()
 */
void Input::handle(sf::Event event, sf::RenderWindow *window) {
    sf::Cursor cursor;
    sf::Vector2f real_mouse_coords = {
            (float) sf::Mouse::getPosition().x - window->getPosition().x,
            (float) sf::Mouse::getPosition().y - window->getPosition().y
    };
    bool hovered = entity->getGlobalBounds().contains(real_mouse_coords);
    bool clicked = event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left;

    if (hovered) {
        if (cursor.loadFromSystem(sf::Cursor::Text)) {
            window->setMouseCursor(cursor);
        }
    } else {
        if (cursor.loadFromSystem(sf::Cursor::Arrow)) {
            window->setMouseCursor(cursor);
        }
    }

    if (hovered && clicked) {
        keep_enter = true;
    }

    if (!hovered && clicked) {
        keep_enter = false;
    }

    if (keep_enter && sf::Event::KeyPressed == event.type) {
        std::string input;
        input = std::to_string(event.text.unicode);
        add(input);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
        removeBack();
    }

    sf::String buffer;
    for (const auto &symbol : container) {
        buffer += symbol;
    }
    text_entity->setString(buffer);
}

/**
 * @copydoc Input::setPosition()
 */
void Input::setPosition(sf::Vector2f position) {
    offset = position;
}

/**
 * @copydoc Input::setSize()
 */
void Input::setSize(sf::Vector2f new_size) {
    size = new_size;
}

/**
 * @copydoc Input::getEntity()
 */
sf::RectangleShape *Input::getEntity() {
    return entity;
}

/**
 * @copydoc Input::draw()
 */
void Input::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*entity);
    target.draw(*text_entity);
}

/**
 * @copydoc Input::getSymbols()
 */
std::vector<std::string> Input::getSymbols() {
    return container;
}

/**
 * @copydoc Input::add()
 */
Input *Input::add(const std::string &str) {
    container.emplace_back(str.c_str());
    std::cout << str.c_str();

    return this;
}

/**
 * @copydoc Input::removeBack()
 */
void Input::removeBack() {
    if (!container.empty()) {
        container.pop_back();
    }
}

/**
 * @copydoc Input::prepareEntity()
 */
void Input::prepareEntity() {
    entity = new sf::RectangleShape;
    entity->setSize(size);
    entity->setPosition(offset);
    entity->setFillColor(bg_color);
}

/**
 * @copydoc Input::preparePlaceholder()
 */
void Input::preparePlaceholder() {
    text_entity = new sf::Text;
    font = new sf::Font;

    if (!font->loadFromFile(EasyGUI::RESOURCES + font_file)) {
        Messenger::send("Не удалось загрузить шрифт ");
        Messenger::send(font_file + "\n", "red");
    }
    text_entity->setFont(*font);
    text_entity->setPosition({offset.x +5, offset.y + 5});
    text_entity->setFillColor(fg_color);
    text_entity->setCharacterSize(font_size);
}
