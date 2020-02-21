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
    prepareFont();
    prepareImage();
    prepareEntity();
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
    label->setPosition({10,10});
}

/**
 * @copydoc Button::prepareImage()
 */
void Button::prepareImage() {
    if (!image_src.empty()) {
        texture = new sf::Texture;
        if (!texture->loadFromFile(EasyGUI::RESOURCES + image_src)) {
            Messenger::send("Не удалось загрузить изображение ");
            Messenger::send(image_src + "\n", "red");
        }
        entity->setTexture(texture);
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
    sf::Vector2f real_mouse_coords = {
            (float) sf::Mouse::getPosition().x - window->getPosition().x,
            (float) sf::Mouse::getPosition().y - window->getPosition().y
    };
    bool hovered = entity->getGlobalBounds().contains(real_mouse_coords);
    bool clicked = event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left;
    handleState(hovered);

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
 * @copydoc Button::handleState()
 */
void Button::handleState(bool state) {
    entity->setFillColor(bg_color[state]);
    label->setFillColor(fg_color[state]);
}
