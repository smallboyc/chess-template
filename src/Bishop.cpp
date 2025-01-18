#include "Bishop.hpp"
#include "Piece.hpp"

bool Bishop::can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    int direction = 1;
    if (to - from < 0)
        direction = -1;
    if (diagonal_move(std::abs(to - from), 7))
        return move_is_legit(from, to, board, direction, 7);
    else if (diagonal_move(std::abs(to - from), 9))
        return move_is_legit(from, to, board, direction, 9);
    return false;
};

void Bishop::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) {};