//
// Created by strannyi_tip on 23.02.2020.
//

#ifndef EASYGUI_INPUT_HPP
#define EASYGUI_INPUT_HPP

#include <Interface/Displayable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

/**
 * Ввод.
 */
class Input : public Displayable {
public:
    /**
     * Конфигурация.
     */
    struct Configuration {
        /** Размер **/
        sf::Vector2f size{100,20};
        /** Смещение **/
        sf::Vector2f offset{0,0};
        /** Текст подстказка **/
        sf::String placeholder = L"Введите текст";
        /**  Цвет текста. */
        sf::Color fg_color{123,123,123};
        /** Цвет фона. */
        sf::Color bg_color{0,0,0,0};
        /** Файл шрифта **/
        std::string font_file{};
        /** азмер шрифта **/
        unsigned int font_size = 10;
    };

    /**
     * Конструктор.
     *
     * @param configuration Конфигурация
     */
    explicit Input(const Input::Configuration &configuration);

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
     * @copydoc  Displayable::setSize()
     */
    void setSize(sf::Vector2f new_size) override;

    /**
     * @copydoc Displayable::getEntity()
     */
    sf::RectangleShape *getEntity() override;

    /**
     * @copydoc sf::Drawable::draw()
     */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    /**
     * Получить символы.
     *
     * @return std::vector<char*>
     */
    std::vector<std::string> getSymbols();

    /**
     * Добавить.
     *
     * @param symbol Символ
     *
     * @return Input*
     */
    Input *add(const std::string &str);

    /**
     * Удалить последний символ.
     */
    void removeBack();

private:
    /**
     * Видим.
     */
    bool is_visible = true;

    /**
     * Сущность.
     */
    sf::RectangleShape *entity{};

    /**
     * Сущность текста подсказки.
     */
    sf::Text *text_entity{};

    /**
     * Шрифт.
     */
    sf::Font *font{};

    /**
     * Файл шрифта.
     */
    std::string font_file = "/fonts/default.ttf";

    /**
     * Размер.
     */
    sf::Vector2f size{};

    /**
     * Смещение.
     */
    sf::Vector2f offset{};

    /**
     * Фокус.
     */
    bool has_focus = false;

    /**
     * Наведен курсор.
     */
    bool has_hover = false;

    /**
     * Ввод.
     */
    bool keep_enter = false;

    /**
     * Контейнер.
     */
    std::vector<std::string> container{};

    /**
     * Текст подсказка.
     */
    sf::String placeholder{};

    /**
     * Цвет текста.
     */
    sf::Color fg_color{123,123,123};

    /**
     * Цвет фона.
     */
    sf::Color bg_color{0,0,0,0};

    /**
     * Размер шрифта.
     */
    unsigned int font_size = 10;

    /**
     * Подгот овить сущность.
     */
    void prepareEntity();

    /**
     * Подготовить сущность текста-подсказки.
     *
     */
    void preparePlaceholder();
};

#endif //EASYGUI_INPUT_HPP
