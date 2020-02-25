//
// Created by strannyi_tip on 23.02.2020.
//

#ifndef EASYGUI_SELECT_HPP
#define EASYGUI_SELECT_HPP

#include <Interface/Displayable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "SelectItem.hpp"

class Select : public Displayable {
public:
    /**
     * Конфигурация.
     */
    struct Configuration {
        /** Размер. **/
        sf::Vector2f size{};
        /** Смещение. **/
        sf::Vector2f offset{};
        /** Файл шрифта. **/
        std::string font_file = "/fonts/default.ttf";
        /** Цвет фона. **/
        sf::Color bg_color{};
        /** Файл текстуры. */
        std::string image_src{};
        /** Ярлык. */
        sf::String label = L"Выберите из списка";
    };

    /**
     * Конструктор.
     *
     * @param configuration Конфигурация
     */
    explicit Select(const Select::Configuration &configuration);

    /**
     * @copydoc Displayable::show()
     */
    void show() override;

    /**
     * @copydoc Displayable::hide()
     */
    void hide() override;

    /**
     * @copydoc Displayable::isVisible()
     */
    bool isVisible() override;

    /**
     * @copydoc Displayable::handle()
     */
    void handle(sf::Event event, sf::RenderWindow *window) override;

    /**
     * @copydoc Displayable::setPosition()
     */
    void setPosition(sf::Vector2f position) override;

    /**
     * @copydoc Displayable::setSize()
     */
    void setSize(sf::Vector2f new_size) override;

    /**
     * @copydoc Displayable::getEntity()
     */
    sf::RectangleShape *getEntity() override;

    /**
     * Добавить.
     *
     * @param item Элемент.
     *
     * @return Select*
     */
    Select *add(SelectItem *item);

    /**
     * @copydoc sf::Drawable::draw()
     */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    /**
     * Выбранный.
     */
    SelectItem *selected{};

    /**
     * Видим.
     */
    bool is_visible = false;

    /**
     * Открыт.
     */
    bool is_opened = false;

    /**
     * Сущность.
     */
    sf::RectangleShape *entity{};

    /**
     * Контейнер.
     */
    std::vector<SelectItem *> container{};

    /**
     * Размер.
     */
    sf::Vector2f size{};

    /**
     * Смещение.
     */
    sf::Vector2f offset{};

    /**
     * Текстура.
     */
    sf::Texture *texture{};

    /**
     * Цвет фона.
     */
    sf::Color bg_color{};

    /**
     * Файл текстуры.
     */
    std::string image_src{};

    /**
     * Файл шрифта.
     */
    std::string font_file = "/fonts/default.ttf";

    /**
     * Ярлык.
     */
    sf::String label = L"Выберите из списка";

    /**
     * Шрифт.
     */
    sf::Font *font{};

    /**
     * Сущность ярлыка.
     */
    sf::Text *label_entity{};

    /**
     * Подготовить сущность.
     */
    void prepareEntity();
};

#endif //EASYGUI_SELECT_HPP
