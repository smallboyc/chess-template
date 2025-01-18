#include "Bishop.hpp"

bool Bishop::move_is_legit(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board, int direction, int pattern)
{
    for (int i{from + pattern * direction}; i != to; i += pattern * direction)
        if (board[i] != nullptr)
            return false;
    return true;
}
bool Bishop::can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    int distance  = std::abs(to - from);
    int direction = 1;
    if (to - from < 0)
        direction = -1;
    if (distance % 7 == 0)
        return move_is_legit(from, to, board, direction, 7);
    else if (distance % 9 == 0)
        return move_is_legit(from, to, board, direction, 9);
    return false;
};

void Bishop::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) {};