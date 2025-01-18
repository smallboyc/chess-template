#include "Pawn.hpp"
#include <imgui.h>
#include <array>
#include "Piece.hpp"
#include "utils.hpp"

bool Pawn::can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    int distance = to - from;
    if (board[from + m_classique_move] == nullptr) // TODO(smallboyc): simplifier en fonction ?? -> bool
    {
        // Condition de la possibilité du double mouvement au départ (special)
        if (board[from + m_special_move] == nullptr && distance == m_special_move && m_step == 0)
        {
            m_step++;
            return true;
        }

        // Condition du mouvement classique
        if (distance == m_classique_move)
        {
            m_step++;
            return true;
        }
    }

    // Le pion mange un adversaire
    // TODO(smallboyc): simplifier en fonction ??
    for (const int move : m_capture_move)
        if (board[from + move] != nullptr && from + move == to)
        {
            m_step++;
            return true;
        }
    return false;
}

// TODO(smallboyc): empty_cell() peut être une fonction "générale"
bool empty_cell(int cell_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    return board[cell_position] == nullptr;
}

bool is_enemy(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    return (board[selected_piece_position]->get_color() != board[cell_position]->get_color());
}

void Pawn::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board)
{
    ImU32            current_color = IM_COL32(0, 255, 0, 255);
    std::vector<int> legit_move    = {m_classique_move, m_special_move};

    if (m_step != 0)
        legit_move.pop_back(); // si le pion se déplace pour la 1ère fois, il ne peut plus utiliser la double avancée

    for (int move : legit_move)
    {
        if (target_cell_scope(selected_piece_position, cell_position, move))
        {
            if (!empty_cell(cell_position, board))
                current_color = IM_COL32(255, 0, 0, 255);
            draw_cell_border(current_color);
        }
    }

    // for (int capture : m_capture_move)
    // {
    //     if (target_cell_scope(selected_piece_position, cell_position, capture))
    //     {
    //         if (!empty_cell(cell_position, board) && is_enemy(selected_piece_position, cell_position, board))
    //             current_color = IM_COL32(255, 255, 0, 255);
    //         draw_cell_border(current_color);
    //     }
    // }
}

bool Pawn::target_cell_scope(int selected_piece_position, int cell_position, int range)
{
    return cell_position == range + selected_piece_position;
}
