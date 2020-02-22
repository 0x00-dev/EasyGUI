//
// Created by strannyi_tip on 21.02.2020.
//

#ifndef EASYGUI_MODALWINDOW_HPP
#define EASYGUI_MODALWINDOW_HPP

#include <SFML/Graphics.hpp>
#include <Interface/Displayable.hpp>

class ModalWindow: public Displayable
{
public:
    /**
    * Тип.
    */
    enum Type {
        /**
         * Подтверждаемый.
         *
         * Должен предоставлять выбор Подтвердить, Отмена
         */
        Confirmable,
        /**
         * Закрываемый.
         *
         * Должен предоставлять э.у Закрыть
         */
        Closeable,
        /**
         * Предоставляющый выбор.
         *
         * Должен предоставлять Выпадающий список
         */
        Selectable,
        /**
         * Записывающий.
         *
         * Должен предоставлять поле ввода и кнопку сохранения
         */
        Writeable
    };

    /**
     * Заголовок.
     */
    struct Title {
        /**
         * Текст.
         */
        sf::String text = "Без заголовка";

        /**
         * Размер шрифта.
         */
        int font_size = 10;

        /**
         * Цвет фона.
         */
        sf::Color color = sf::Color::Red;

        /**
         * Расположение.
         */
        sf::Vector2f offset = {10, 10};

        /**
         * Файл шрифта.
         */
        std::string font_file = "fonts/default.ttf";
    };

    /**
     * Конфигурация.
     */
    struct Configuration {
        /**
         * Разрешение.
         */
        sf::Vector2f size{200, 100};

        /**
         * Координаты.
         */
        sf::Vector2f coords{0, 0};

        /**
         * Цвет фона.
         */
        sf::Color bg_color = sf::Color::White;

        /**
         * Путь изображения фона.
         */
        std::string image_src{};

        /**
         * Файл шрифта.
         */
        std::string font_file = "/fonts/default.ttf";

        /**
         * Заголовок.
         */
        Title title;
    };
    /**
     * Конструктор.
     *
     * @param config Конфигурация.
     */
    explicit ModalWindow(const ModalWindow::Configuration &config);

    /**
     * @copydoc Containable::show()
     */
    void show() override;

    /**
     * @copydoc Containable::hide()
     */
    void hide() override ;

    /**
     * @copydoc Eventable::handle()
     */
    void handle(sf::Event event, sf::RenderWindow *window) override;

    /**
     * @copydoc sf::Drawable::draw()
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * Добавить.
     *
     * @param element Элемент
     *
     * @return *ModalWindow
     */
    ModalWindow *add(sf::Vector2f item_offset, Displayable *element);

    /**
     * @copydoc Displayable::getEntity()
     */
    sf::RectangleShape *getEntity() override;

    /**
     * @copydoc Containable::isVisible()
     */
    bool isVisible() override;

    void setPosition(sf::Vector2f position) override;

private:
    /**
     * Разрешение.
     */
    sf::Vector2f size{100, 50};

    /**
     * Координаты.
     */
    sf::Vector2f coords{0, 0};

    /**
     * Цвет фона.
     */
    sf::Color bg_color = {66,66,66,200};

    /**
     * Путь изображения фона.
     */
    std::string image_src{};

    /**
     * Имя.
     */
    std::string name = "undefined";

    /**
     * Контейнер для хранения элементов окна.
     */
    std::vector<Displayable *> items_container;

    /**
     * Управляющие элементы окна.
     */
    std::map<sf::Vector2f, sf::Drawable *> controls{};

    /**
     * Текстура окна.
     */
    sf::Texture *texture = nullptr;

    /**
     * Закрываемое.
     */
    bool is_closeable = true;

    /**
     * Открыто.
     */
    bool is_opened = true;

    /**
    * Сущность для отрисовки.
    */
    sf::RectangleShape *entity;

    /**
    * Текст.
    */
    sf::Text *text_entity{};

    /**
    * Размер шрифта.
    */
    unsigned int font_size = 16;

    /**
     * Файл шрифта.
     */
    std::string font_file = "/fonts/default.ttf";

    /**
     * Шрифт.
     */
    sf::Font *font{};

    /**
     * Заголовок.
     */
    Title title{};

    /**
     * Конфигурировать.
     *
     * @param config Конфигурация
     */
    void configure(const ModalWindow::Configuration &config);

    /**
     * Подготовить шрифт.
     */
    void prepareFont();

    /**
     * Подготовить сущность.
     */
    void prepareEntity();

    /**
     * Подготовить заголовок.
     */
    void prepareTitle();
};

#endif //EASYGUI_MODALWINDOW_HPP
