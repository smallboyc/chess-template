#pragma once
#include "Piece.hpp"

class Queen : public Piece {
public:
    explicit Queen(const Color color = Color::None)
        : Piece(Type::Queen, color) {}
    bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;
    void draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) override;
};