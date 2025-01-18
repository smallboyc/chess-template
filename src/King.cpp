#include "King.hpp"
#include <iostream>
#include "Piece.hpp"

// bool is_in_check(int cell_to_check, std::array<std::unique_ptr<Piece>, 64>& board)
// {
//     //** */ la fonction a pour objectif de bloquer le déplacement du roi s'il se met en situation d'échec.

//     //  à gauche du roi
//     for (int left = cell_to_check - 1; same_line_move(cell_to_check, left); left--)
//     {
//         if (board[left] != nullptr)
//         {
//             if (board[left]->get_type() == Type::Queen || board[left]->get_type() == Type::Rook)
//                 return true; // in_check
//             break;           // on break car ça veut dire qu'une autre pièce est sur le chemin
//         }
//     }

//     // à droite du roi
//     for (int right = cell_to_check + 1; same_line_move(cell_to_check, right); right++)
//     {
//         if (board[right] != nullptr)
//         {
//             if (board[right]->get_type() == Type::Queen || board[right]->get_type() == Type::Rook)
//                 return true;
//             break;
//         }
//     }

//     // au dessus du roi
//     for (int top = cell_to_check - 8; same_colone_move(cell_to_check, top); top -= 8)
//     {
//         if (board[top] != nullptr)
//         {
//             if (board[top]->get_type() == Type::Queen || board[top]->get_type() == Type::Rook)
//                 return true; // in_check
//             break;           // on break car ça veut dire qu'une autre pièce est sur le chemin
//         }
//     }

//     return false;
// }

bool King::can_move(int from, int to, [[maybe_unused]] std::array<std::unique_ptr<Piece>, 64>& board)
{
    std::array<int, 4> patterns{
        1, 7, 8, 9
    };
    int distance = std::abs(to - from);
    for (const int pattern : patterns)
    {
        if (distance == pattern)
            return true;
        // return !is_in_check(to, board);
    }
    return false;
};
void King::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) {};