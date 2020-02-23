//
// Created by strannyi_tip on 21.02.2020.
//

#include <Window/ModalWindow.hpp>
#include <Controls/Button.hpp>
#include <Core/Messenger.hpp>
#include <Controls/Input.hpp>
#include <termios.h>
#include <unistd.h>
#include <iostream>

int main()
{
    ModalWindow::Configuration win_config{};
    Input::Configuration input_config{};

    win_config.size = {400, 300};
    win_config.bg_color = {66, 66, 66, 230};
    win_config.coords = {200, 100};
    win_config.title.color = {255, 10, 10, 255};
    win_config.title.font_size = 14;
    win_config.title.offset = {10, 0};
    win_config.title.font_file = "/fonts/default.ttf";

    input_config.size = {200, 200};
    input_config.bg_color = {255, 255, 255};
    input_config.fg_color = {0,0,0};
    input_config.font_file = "/fonts/default.ttf";
    input_config.font_size = 20;

    Input input(input_config);

    auto win = new ModalWindow(win_config);

    win->add({20, 20}, &input);

    sf::RenderWindow window(sf::VideoMode(800, 600), "easyGUI");

    sf::View view(sf::FloatRect(0.f, 0.f, 800.f, 600.f));

    window.setView(view);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            win->handle(event, &window);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear({255,255,255});
        window.draw(*win);
        window.display();
    }
}