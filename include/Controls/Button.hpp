//
// Created by strannyi_tip on 22.02.2020.
//

#ifndef EASYGUI_BUTTON_HPP
#define EASYGUI_BUTTON_HPP

#include <Interface/Displayable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <Core/Definitions.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Button : public Displayable {
public:

    /**
     * Конфигурация.
     */
    struct Configuration {
        /** Файл шрифта. */
        std::string font_file = "/fonts/default.ttf";
        /** Цвет фона. */
        std::map<int,sf::Color> bg_color;
        /** Цвет текста. */
        std::map<int,sf::Color> fg_color;
        /** Размер кегля. */
        unsigned int font_size = 14;
        /** Смещение относительно предка. */
        sf::Vector2f offset = {10, 10};
        /** Фоновое изображение. */
        std::string image_src{};
        /** Текст. */
        sf::String text = L"Кнопка";
        /** Размер. */
        sf::Vector2f size;
    };

    /**
     * Конструктор.
     *
     * @param config Конфигурация
     */
    explicit Button(const Button::Configuration &config);

    /**
     * @copydoc sf::Drawable::draw()
     */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    /**
     * При клике.
     *
     * @param callback Функция обратного вызова
     */
    void onClick(EasyGUI::Callback &callback);

private:
    /**
     * Файл шрифта.
     */
    std::string font_file = "/fonts/default.ttf";

    /**
     * Цвет фона.
     */
    std::map<int,sf::Color> bg_color;

    /**
     * Цвет текста.
     */
    std::map<int,sf::Color> fg_color;

    /**
     * Размер кегля.
     */
    unsigned int font_size = 14;

    /**
     * Смещение относительно предка.
     */
    sf::Vector2f offset = {10, 10};

    /**
     * Фоновое изображение.
     */
    std::string image_src;

    /**
     * Шрифт.
     */
    sf::Font *font;

    /**
     * Ярлык.
     */
    sf::Text *label;

    /**
     * Текст.
     */
    sf::String text = L"Кнопка";

    /**
     * Текстура.
     */
    sf::Texture *texture;

    /**
     * Фокус.
     */
    bool has_hover = false;

    /**
     * Активна.
     */
    bool is_active = false;

    /**
     * Видна.
     */
    bool is_visible = true;

    /**
     * Действие.
     */
    EasyGUI::Callback action{};

    /**
     * Сущность.
     */
    sf::RectangleShape *entity{};

    /**
     * Размер.
     */
    sf::Vector2f size;

    /**
     * Конфигурировать.
     */
    void configure();

    /**
     * Подготовить шрифт.
     */
    void prepareFont();

    /**
     * Подготовить изображение.
     */
    void prepareImage();

    /**
     * Подготовить сущность.
     */
    void prepareEntity();

    /**
     * @copydoc Eventable::handle()
     */
    void handle(sf::Event event, sf::RenderWindow *window) override;

    /**
     * @copydoc Displayable::handle()
     */
    sf::RectangleShape *getEntity() override;

    /**
     * @copydoc Containable::show()
     */
    void show() override;

    /**
     * @copydoc Containable::hide()
     */
    void hide() override;

    /**
     * Захватить состояние.
     *
     * @param state Состояние
     */
    void handleState(bool state);
};

#endif //EASYGUI_BUTTON_HPP
