#include "Pawn.hpp"
#include <array>
#include "Piece.hpp"

bool Pawn::can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    int classic_move = 8 * direction();
    int special_move = 2 * classic_move;

    // Condition de la possibilité du double mouvement au départ
    if (board[from + classic_move] == nullptr && board[from + special_move] == nullptr && from + special_move == to && m_step == 0)
    {
        m_step++;
        return true;
    }

    // Condition du mouvement classique
    if (board[from + classic_move] == nullptr && from + classic_move == to)
    {
        m_step++;
        return true;
    }

    // Le pion mange un adversaire
    std::array<int, 2> kill_move = {7 * direction(), 9 * direction()};
    for (const int move : kill_move)
        if (board[from + move] != nullptr && from + move == to)
        {
            m_step++;
            return true;
        }
    return false;
}
