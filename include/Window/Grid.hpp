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
     */
    explicit Grid(sf::Vector2f new_size);

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
    sf::Vector2f size = {4,4};

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
