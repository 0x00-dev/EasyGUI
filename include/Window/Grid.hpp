//
// Created by strannyi_tip on 22.02.2020.
//

#ifndef EASYGUI_GRID_HPP
#define EASYGUI_GRID_HPP

#include <Interface/Displayable.hpp>

/**
 * Сетка.
 */
class Grid : public Displayable
{
public:
    /**
     * Конструктор.
     *
     * @param new_size Размер
     * @param new_width Ширина
     */
    explicit Grid(sf::Vector2i new_size, float new_width);

    /**
     * Добавить.
     *
     * @param item Элемент
     *
     * @return Grid*
     */
    Grid *add(Displayable *item);
private:
    /**
     * Размер.
     */
    sf::Vector2i size = {4,4};

    /**
     * Ширина.
     */
    float width = 1000;

    /**
     * Контейнер.
     */
    std::vector<Displayable*> container{};

    /**
     * Конфигурировать.
     */
    void configure();
};

#endif //EASYGUI_GRID_HPP
