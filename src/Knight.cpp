#include "Knight.hpp"

bool Knight::can_move(int from, int to, [[maybe_unused]] std::array<std::unique_ptr<Piece>, 64>& board)
{
    std::array<int, 4> patterns{
        6, 10, 15, 17
    };
    int distance = std::abs(to - from);

    for (const int pattern : patterns)
        if (distance == pattern)
            return true;

    return false;
};

void Knight::draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) {
};