//
// Created by strannyi_tip on 21.02.2020.
//

#ifndef EASYGUI_DEFINITIONS_HPP
#define EASYGUI_DEFINITIONS_HPP

#include <functional>

namespace EasyGUI
{
    /**
     * Путь к ресурсам.
     */
    const std::string RESOURCES = "../resources";

    typedef std::function<void (void)> Callback;
};

#endif //EASYGUI_DEFINITIONS_HPP
