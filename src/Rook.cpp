#include "Rook.hpp"
#include <algorithm>
#include <iostream>
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

void Rook::check_for_obstacles(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    if ((same_colone_move(selected_piece_position, cell_position) || same_line_move(selected_piece_position, cell_position)) && cell_position != selected_piece_position)
    {
        if ((std::find(m_obstacles.begin(), m_obstacles.end(), cell_position) == m_obstacles.end()) && is_obstacle(selected_piece_position, cell_position, board))
        {
            // TODO(smallboyc): ne pousser que les obstacles les plus proches.
            m_obstacles.push_back(cell_position);
        }
    }
}

bool Rook::is_obstacle(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    return (board[cell_position] != nullptr && board[selected_piece_position]->get_color() == board[cell_position]->get_color());
}

void Rook::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    // vérifier si il y a des obstacles sur les chemins de la tour sur
    check_for_obstacles(selected_piece_position, cell_position, board);
    std::cout << m_obstacles.size() << "\n";
    for (const int obstacle_position : m_obstacles)
    {
        std::cout << obstacle_position << "\n";
    }
    // if (!forbidden_cell && (same_colone_move(selected_piece_position, cell_position) || same_line_move(selected_piece_position, cell_position)))
    //     draw_cell_border(IM_COL32(0, 255, 0, 255));
    // else
    //     draw_cell_border(IM_COL32(255, 0, 0, 255));
};
