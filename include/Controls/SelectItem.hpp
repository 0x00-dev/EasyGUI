//
// Created by strannyi_tip on 23.02.2020.
//

#ifndef EASYGUI_SELECTITEM_HPP
#define EASYGUI_SELECTITEM_HPP

#include <Interface/Displayable.hpp>
#include <SFML/Graphics/Font.hpp>

class SelectItem : public Displayable {
public:
    /**
     * @copydoc sf::Displayable::draw()
     */
    void show() override;

    /**
     * @copydoc sf::Displayable::hide()
     */
    void hide() override;

    /**
     * @copydoc sf::Displayable::isVisible()
     */
    bool isVisible() override;

    /**
     * @copydoc sf::Displayable::handle()
     */
    void handle(sf::Event event, sf::RenderWindow *window) override;

    /**
     * @copydoc sf::Displayable::setPosition()
     */
    void setPosition(sf::Vector2f position) override;

    /**
     * @copydoc sf::Displayable::setSize()
     */
    void setSize(sf::Vector2f new_size) override;

    /**
     * @copydoc sf::Displayable::getEntity()
     */
    sf::RectangleShape *getEntity() override;

    /**
     * @copydoc sf::Drawable::draw()
     */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    /**
     * Предок.
     */
    Displayable *parent{};

    /**
     * Виден.
     */
    bool is_visible = false;

    /**
     * Выбран.
     */
    bool is_selected = false;

    /**
     * Цвет текста.
     */
    sf::Color fg_color{};

    /**
     * Цвет фона.
     */
    sf::Color bg_color{};

    /**
     * Файл шрифта.
     */
    std::string font_file{};

    /**
     * Размер.
     */
    sf::Vector2f size{};

    /**
     * Смещение.
     */
    sf::Vector2f offset{};

    /**
     * Шрифт.
     */
    sf::Font *font{};

    /**
     * Текстура.
     */
    sf::Texture *texture{};

    /**
     * Сущность.
     */
    sf::RectangleShape *entity{};
};

#endif //EASYGUI_SELECTITEM_HPP
