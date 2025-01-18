#pragma once
#include <imgui.h>
enum class Color {
    White,
    Black,
    /*default*/
    None,
};

// enum class Scope {
//     Green,
//     Red,
// };

ImVec4 color_to_rgba(const Color& color);
void   draw_cell_border(ImU32 scope_color);
