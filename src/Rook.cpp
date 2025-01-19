#include "Rook.hpp"
#include <imgui.h>
#include <algorithm>
#include <iostream>
#include "Piece.hpp"
#include "utils.hpp"

bool Rook::can_move(const int from, const int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    int direction = 1;
    if (to - from < 0)
        direction = -1;
    if (same_colone_move(from, to))
        return move_is_legit(from, to, board, direction, 8);
    else if (same_line_move(from, to))
        return move_is_legit(from, to, board, direction, 1);
    return false;
};

void Rook::check_for_obstacles(int selected_piece_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    m_obstacles["top"]    = -1;
    m_obstacles["bottom"] = -1;
    m_obstacles["left"]   = -1;
    m_obstacles["right"]  = -1;

    std::vector<int> col_obstacles_top;
    std::vector<int> col_obstacles_bottom;
    std::vector<int> line_obstacles_left;
    std::vector<int> line_obstacles_right;
    //
    for (int target_cell{0}; target_cell < board.size(); target_cell++)
    {
        if (same_colone_move(selected_piece_position, target_cell))
        {
            if (is_obstacle(selected_piece_position, target_cell, board))
            {
                if (selected_piece_position - target_cell > 0)
                    col_obstacles_top.push_back(target_cell);
                else
                    col_obstacles_bottom.push_back(target_cell);
            }
        }
        else if (same_line_move(selected_piece_position, target_cell))
        {
            if (is_obstacle(selected_piece_position, target_cell, board))
            {
                if (selected_piece_position - target_cell > 0)
                    line_obstacles_left.push_back(target_cell);
                else
                    line_obstacles_right.push_back(target_cell);
            }
        }
    }

    if (!col_obstacles_top.empty())
        m_obstacles["top"] = *std::max_element(col_obstacles_top.begin(), col_obstacles_top.end());
    if (!col_obstacles_bottom.empty())
        m_obstacles["bottom"] = *std::min_element(col_obstacles_bottom.begin(), col_obstacles_bottom.end());
    if (!line_obstacles_left.empty())
        m_obstacles["left"] = *std::max_element(line_obstacles_left.begin(), line_obstacles_left.end());
    if (!line_obstacles_right.empty())
        m_obstacles["right"] = *std::min_element(line_obstacles_right.begin(), line_obstacles_right.end());

    std::cout << "\n";
}

bool Rook::is_obstacle(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    return (cell_position != selected_piece_position && board[cell_position] != nullptr);
}

void Rook::draw_scope(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    if (same_line_move(from, to))
    {
        if ((to > m_obstacles["left"] && to < from) || ((m_obstacles["left"] == -1 && to < from)))
        {
            draw_cell_border(IM_COL32(0, 255, 0, 255));
        }
        if ((to < m_obstacles["right"] && to > from) || ((m_obstacles["right"] == -1 && to > from)))
        {
            draw_cell_border(IM_COL32(0, 255, 0, 255));
        }
        // TARGET ENEMY
        if (to == m_obstacles["left"] && board[to]->get_color() != board[from]->get_color())
        {
            draw_cell_border(IM_COL32(0, 255, 255, 255));
        }
        if (to == m_obstacles["right"] && board[to]->get_color() != board[from]->get_color())
        {
            draw_cell_border(IM_COL32(0, 255, 255, 255));
        }
    }

    if (same_colone_move(from, to))
    {
        if ((to > m_obstacles["top"] && to < from) || (m_obstacles["top"] == -1 && to < from))
        {
            draw_cell_border(IM_COL32(0, 255, 0, 255));
        }
        if ((to < m_obstacles["bottom"] && to > from) || (m_obstacles["bottom"] == -1 && to > from))
            draw_cell_border(IM_COL32(0, 255, 0, 255));
        // TARGET ENEMY
        if (to == m_obstacles["top"] && board[to]->get_color() != board[from]->get_color())
        {
            draw_cell_border(IM_COL32(0, 255, 255, 255));
        }
        if (to == m_obstacles["bottom"] && board[to]->get_color() != board[from]->get_color())
        {
            draw_cell_border(IM_COL32(0, 255, 255, 255));
        }
    }
};
