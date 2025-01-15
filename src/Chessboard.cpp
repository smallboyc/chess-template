#include "Chessboard.hpp"

void Chessboard::create_board()
{
    bool  toggle_color_row_start = false;
    Color current_color_cell     = Color::Black;

    for (int i{0}; i < 64; i++)
    {
        toggle_color_row_start = i % 8 == 0;

        if (!toggle_color_row_start)
            current_color_cell = current_color_cell == Color::Black ? Color::White : Color::Black;

        Cell new_cell(i, current_color_cell);
        m_board.push_back(new_cell);
    }
}

void Chessboard::display_board()
{
    for (Cell& cell : m_board)
    {
        cell.draw();
        if ((cell.get_position() + 1) % 8 != 0)
            ImGui::SameLine();
    }
}
