#include "Pawn.hpp"
#include <imgui.h>
#include <array>
#include "Piece.hpp"
#include "utils.hpp"

bool Pawn::can_move(const int from, const int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    int attempted_move = to - from;
    return special_move(from, attempted_move, board) || classic_move(from, attempted_move, board) || capture_move(from, attempted_move, board);
}

//* MOVES *//
bool Pawn::special_move(const int from, const int attempted_move, std::array<std::unique_ptr<Piece>, 64>& board)
{
    if (board[from + m_classique_move] == nullptr && board[from + m_special_move] == nullptr && attempted_move == m_special_move && m_step == 0)
    {
        m_step++;
        m_vulnerable = true; // pion vulnérable à la prise en passant.
        return true;
    }
    return false;
}

bool Pawn::classic_move(const int from, const int attempted_move, std::array<std::unique_ptr<Piece>, 64>& board)
{
    if (board[from + m_classique_move] == nullptr && attempted_move == m_classique_move)
    {
        if (m_vulnerable) // si le pion fait un mouvement classique il n'est plus vulnérable à la prise en passant.
            m_vulnerable = false;
        m_step++;
        return true;
    }
    return false;
}

bool Pawn::capture_move(const int from, const int attempted_move, std::array<std::unique_ptr<Piece>, 64>& board)
{
    for (const int move : m_capture_move)
    {
        const int target_move{from + move};
        if (board[target_move] != nullptr && move == attempted_move)
        {
            m_step++;
            return true;
        }
        else if (board[target_move] == nullptr)
        {
            // in passing move
            if (board[target_move - m_classique_move] != nullptr && board[target_move - m_classique_move]->is_vulnerable_to_in_passing())
            {
                m_step++;
                board[target_move - m_classique_move].reset();
                return true;
            }
        }
    }
    return false;
}

//* SCOPE *//
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
            if (board[cell_position] != nullptr)
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
