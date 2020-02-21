//
// Created by strannyi_tip on 21.02.2020.
//

#ifndef EASYGUI_MESSENGER_HPP
#define EASYGUI_MESSENGER_HPP

#include <map>

class Messenger {
private:
    /**
     * Цвет шрифта.
     */
    std::map<std::string, std::string> fg_colors{
            {"black",          "0;30"},
            {"dark_gray",      "1;30"},
            {"blue",           "0;34"},
            {"light_blue",     "1;34"},
            {"green",          "0;32"},
            {"light_green",    "1;32"},
            {"cyan",           "0;36"},
            {"light_cyan",     "0;32"},
            {"red",            "0;31"},
            {"light_red",      "1;31"},
            {"purple",         "0;35"},
            {"light_purple",   "1;35"},
            {"brown",          "0;33"},
            {"yellow",         "1;33"},
            {"light_gray",     "0;37"},
            {"white",          "1;37"},
            {"bright_magenta", "1;95"},
            {"default",        "0;36"},
    };

    std::map<std::string, std::string> bg_colors{
            {"black",          "40"},
            {"red",            "41"},
            {"green",          "42"},
            {"yellow",         "43"},
            {"blue",           "44"},
            {"magenta",        "45"},
            {"cyan",           "46"},
            {"light_gray",     "47"},
            {"bright_magenta", "105"},
            {"default",        "47"},
    };

public:
    Messenger() = default;

    std::string
    colorize(const std::string &string, const std::string &fg = "default", const std::string &bg = "transparent");

    static void send(const std::string &string, const std::string &fg = "default", const std::string &bg = "transparent");
};

#endif //EASYGUI_MESSENGER_HPP
