#include "Queen.hpp"
#include "Piece.hpp"

bool Queen::can_move(const int from, const int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    int direction = 1;
    if (to - from < 0)
        direction = -1;
    if (same_colone_move(from, to)) // top & bottom
        return move_is_legit(from, to, board, direction, 8);
    else if (same_line_move(from, to))
        return move_is_legit(from, to, board, direction, 1);
    else if (diagonal_move(std::abs(to - from), 7))
        return move_is_legit(from, to, board, direction, 7);
    else if (diagonal_move(std::abs(to - from), 9))
        return move_is_legit(from, to, board, direction, 9);
    return false;
};
void Queen::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) {};