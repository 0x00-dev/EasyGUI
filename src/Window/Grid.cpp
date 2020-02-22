//
// Created by strannyi_tip on 22.02.2020.
//

#include <Window/Grid.hpp>

/**
 * @copydoc Grid::Grid();
 */
Grid::Grid(sf::Vector2i new_size, float new_width) {
    size = new_size;
    width = new_width;
}

/**
 * @copydoc Grid::add();
 */
Grid *Grid::add(Displayable *item) {
    container.push_back(item);

    return this;
}

/**
 * @copydoc Grid::configure();
 */
void Grid::configure() {
    float complete_width = 0;
    for (const auto &item : container) {
        complete_width += item->getEntity()->getSize().x;
    }
    if (complete_width > width) {
        return;
    }
}

