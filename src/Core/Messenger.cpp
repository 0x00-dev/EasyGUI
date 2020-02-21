//
// Created by strannyi_tip on 21.02.2020.
//

#include <Core/Messenger.hpp>
#include <iostream>

std::string
Messenger::colorize(const std::string &string, const std::string &fg, const std::string &bg) {
    std::string final_fg, final_bg;

    final_fg = "\033[" + (fg_colors.find(fg) == fg_colors.end() ? fg_colors["default"] : fg_colors[fg]) + "m";
    if ("transparent" != bg) {
        final_bg = "\033[" + (bg_colors.find(bg) == bg_colors.end() ? bg_colors["default"] : bg_colors[bg]) + "m";
    }

    return final_fg + final_bg + string + "\033[0m";
}

void Messenger::send(const std::string &string, const std::string &fg, const std::string &bg) {
    Messenger messenger{};

    auto str = messenger.colorize(string, fg, bg);

    std::cout << str;
}