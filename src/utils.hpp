#pragma once
#include <imgui.h>
enum class Color {
    White,
    Black,
    /*default*/
    None,
};

ImVec4 color_to_rgba(const Color& color);
// Color  current_cell_color(bool toggle_color_row_start, Color& current_color_cell, size_t cell_position, int board_size);
