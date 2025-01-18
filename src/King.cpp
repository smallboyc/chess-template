#include "King.hpp"

// bool is_in_check(int cell_to_check, std::array<std::unique_ptr<Piece>, 64>& board)
// {
//     int row = cell_to_check % 8;
//     int col = cell_to_check / 8;

//     // check top & bottom enemy
//     // check left & right enemy
//     // check diagonal 1
//     // check diagonal 2
//     if (board[cell_to_check])
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
    // TODO(smallboyc):
    // is_in_check()
    // checkmate()
    return false;
};
void King::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) {};