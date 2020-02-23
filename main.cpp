//
// Created by strannyi_tip on 21.02.2020.
//

#include <Window/ModalWindow.hpp>
#include <Controls/Button.hpp>
#include <Core/Messenger.hpp>

int main()
{
    ModalWindow::Configuration win_config{};

    win_config.size = {400, 300};
    win_config.bg_color = {66, 66, 66, 230};
    win_config.coords = {200, 100};
    win_config.title.color = {255, 10, 10, 255};
    win_config.title.font_size = 14;
    win_config.title.offset = {10, 0};
    win_config.title.text = L"Тестовый заголовок";
    win_config.title.font_file = "/fonts/default.ttf";

    auto win = new ModalWindow(win_config);

    sf::RenderWindow window(sf::VideoMode(1366, 768), "easyGUI");

    sf::View view(sf::FloatRect(0.f, 0.f, 1366.f, 768.f));

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