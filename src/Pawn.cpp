#include "Pawn.hpp"
#include "Piece.hpp"

bool Pawn::move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    int classic_move = 8 * direction();
    int special_move = 2 * classic_move * direction();

    for (int i{from}; i < to; i += classic_move)
    {
        if (board[i] != nullptr)
            return false;
    }

    if (from + classic_move == to) // classic move
        return true;
}