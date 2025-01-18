#include "King.hpp"

bool King::can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    std::array<int, 4> patterns{
        1, 7, 8, 9
    };
    int distance = std::abs(to - from);
    for (const int pattern : patterns)
        if (distance == pattern)
            return true;
    // TODO(smallboyc):
    // is_in_check()
    // checkmate()
    return false;
};
void King::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) {};