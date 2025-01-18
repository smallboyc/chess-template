#include "Queen.hpp"

bool Queen::move_is_legit(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board, int direction, int pattern)
{
    for (int i{from + pattern * direction}; i != to; i += pattern * direction)
        if (board[i] != nullptr)
            return false;
    return true;
}

bool Queen::can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    int distance  = std::abs(to - from);
    int direction = 1;
    if (to - from < 0)
        direction = -1;
    if (distance % 8 == 0) //top & bottom
        return move_is_legit(from, to, board, direction, 8);
    else if (distance % 7 == 0) //diagonale 1
        return move_is_legit(from, to, board, direction, 7);
    else if (distance % 9 == 0) //diagonale 2
        return move_is_legit(from, to, board, direction, 9);
    else if (distance % 1 == 0) //left & right (doit être à la fin! car tout est divisible par 1)
        return move_is_legit(from, to, board, direction, 1);
    return false;
};
void Queen::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) {};