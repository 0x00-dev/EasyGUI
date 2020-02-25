//
// Created by strannyi_tip on 22.02.2020.
//

#include <Controls/Button.hpp>
#include <Core/Messenger.hpp>
#include <iostream>

/**
 * @copydoc sf::Drawable::draw()
 */
void Button::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (is_visible) {
        target.draw(*entity);
        target.draw(*label);
        target.draw(*sprite);
    }
}

/**
 * @copydoc Button::Button()
 */
Button::Button(const Button::Configuration &config) {
    font_file = config.font_file;
    fg_color = config.fg_color;
    bg_color = config.bg_color;
    font_size = config.font_size;
    offset = config.offset;
    text = config.text;
    image_src = config.image_src;
    size = config.size;
    parent = config.parent;
    is_visible = parent->isVisible();
    configure();
}

/**
 * @copydoc Button::onClick()
 */
void Button::onClick(EasyGUI::Callback &callback) {
    action = callback;
}

/**
 * @copydoc Button::configure()
 */
void Button::configure() {
    prepareEntity();
    prepareImage();
    prepareFont();
}

/**
 * @copydoc Button::prepareFont()
 */
void Button::prepareFont() {
    font = new sf::Font;
    if (!font->loadFromFile(EasyGUI::RESOURCES + font_file)) {
        Messenger::send("Не удалось загрузить шрифт ");
        Messenger::send(font_file + "\n", "red");
    }
    label = new sf::Text;
    label->setString(text);
    label->setFont(*font);
    label->setFillColor(fg_color[0]);
    label->setPosition({offset.x + 0, offset.y + 0});
}

/**
 * @copydoc Button::prepareImage()
 */
void Button::prepareImage() {
    if (!image_src.empty()) {
        texture = new sf::Texture;
        sprite = new sf::Sprite;
        if (!texture->loadFromFile(EasyGUI::RESOURCES + image_src)) {
            Messenger::send("Не удалось загрузить изображение ");
            Messenger::send(image_src + "\n", "red");
        }
        float x,y;
        x = parent->getEntity()->getGlobalBounds().left + offset.x + size.x/2 + 2;
        y = parent->getEntity()->getGlobalBounds().top + offset.y + +size.y/2 + 2;
        sprite->setPosition({x,y});
        sprite->setTexture(*texture);
    }
}

/**
 * @copydoc Button::prepareEntity()
 */
void Button::prepareEntity() {
    entity = new sf::RectangleShape;
    entity->setPosition(offset);
    entity->setSize(size);
}

/**
 * @copydoc Button::handle()
 */
void Button::handle(sf::Event event, sf::RenderWindow *window) {
    sf::Cursor cursor;
    sf::Vector2f real_mouse_coords = {
            (float) sf::Mouse::getPosition().x - window->getPosition().x,
            (float) sf::Mouse::getPosition().y - window->getPosition().y
    };
    bool hovered = entity->getGlobalBounds().contains(real_mouse_coords);
    bool clicked = event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left;
    handleState(hovered);

    if (hovered) {
        if (cursor.loadFromSystem(sf::Cursor::Hand)) {
            window->setMouseCursor(cursor);
        }
    } else {
        if (cursor.loadFromSystem(sf::Cursor::Arrow)) {
            window->setMouseCursor(cursor);
        }
    }

    if (hovered && clicked) {
        action();
    }
}

/**
 * @copydoc Displayable::getEntity()
 */
sf::RectangleShape *Button::getEntity() {
    return entity;
}

/**
 * @copydoc Containable::show()
 */
void Button::show() {
    is_visible = true;
}

/**
 * @copydoc Containable::hide()
 */
void Button::hide() {
    is_visible = false;
}

/**
 * {@copydoc ModalWindow::isVisible()}
 */
bool Button::isVisible() {
    return is_visible;
}

/**
 * @copydoc Button::handleState()
 */
void Button::handleState(bool state) {
    if (image_src.empty()) {
        entity->setFillColor(bg_color[state]);
        label->setFillColor(fg_color[state]);
    } else {
        entity->setFillColor({0,0,0,0});
    }
}

/**
 * @copydoc Button::setPosition()
 */
void Button::setPosition(sf::Vector2f position) {
    offset = position;
    prepareEntity();
    prepareFont();
}

/**
 * @copydoc Button::setSize()
 */
void Button::setSize(sf::Vector2f new_size) {
    size = new_size;
}
