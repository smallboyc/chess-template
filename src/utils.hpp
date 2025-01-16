#pragma once
#include <imgui.h>
enum class Color {
    White,
    Black,
    /*default*/
    None,
};

ImVec4 color_to_rgba(const Color& color);
