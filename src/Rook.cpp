#include "Rook.hpp"
#include <imgui.h>
#include <algorithm>
#include <climits>
#include <cmath>
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

bool obstacle_not_already_saved(const std::vector<int>& obstacles, const int obstacle_position)
{
    return (std::find(obstacles.begin(), obstacles.end(), obstacle_position) == obstacles.end());
}

// avec cette fonction j'arrive à dire quelles sont les pièces les plus proches de la pièce courante.
void Rook::check_for_obstacles(int selected_piece_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    std::vector<int> col_obstacles;
    std::vector<int> line_obstacles;
    //
    for (int target_cell{0}; target_cell < board.size(); target_cell++)
    {
        if (is_obstacle(selected_piece_position, target_cell, board) && obstacle_not_already_saved(m_obstacles, target_cell))
        {
            if (same_colone_move(selected_piece_position, target_cell))
            {
                int direction{8};
                std::cout << target_cell << "\n";
                if (selected_piece_position - target_cell > 0)
                    std::cout << "obstacle en haut" << "\n"; // + 8
                else
                    std::cout << "obstacle en bas" << "\n"; // -8
                // col_obstacles.push_back(target_cell);
            }
            else if (same_line_move(selected_piece_position, target_cell))
            {
                std::cout << target_cell << "\n";
                if (selected_piece_position - target_cell > 0)
                    std::cout << "obstacle à gauche" << "\n"; // - 1
                else
                    std::cout << "obstacle à droite" << "\n"; // + 1
                // line_obstacles.push_back(target_cell);
            }
        }
    }

    // std::cout << "Col : ";
    // for (const int obstacle : col_obstacles)
    //     std::cout << obstacle << ",";
    // std::cout << "\n";
    // std::cout << "Line : ";
    // for (const int obstacle : line_obstacles)
    //     std::cout << obstacle << ",";
    // std::cout << "\n";
}

bool Rook::is_obstacle(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    return (cell_position != selected_piece_position && board[cell_position] != nullptr);
}

void Rook::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) {
    // vérifier si il y a des obstacles sur les chemins de la tour sur
    // check_for_obstacles(selected_piece_position, cell_position, board);
    // std::cout << m_obstacles.size() << "\n";
    // for (const int obstacle_position : m_obstacles)
    // {
    //     std::cout << obstacle_position << "\n";
    // }
    // if (!forbidden_cell && (same_colone_move(selected_piece_position, cell_position) || same_line_move(selected_piece_position, cell_position)))
    //     draw_cell_border(IM_COL32(0, 255, 0, 255));
    // else
    //     draw_cell_border(IM_COL32(255, 0, 0, 255));
};
