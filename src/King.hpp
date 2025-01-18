#pragma once
#include "Piece.hpp"

class King : public Piece {
public:
    explicit King(const Color color = Color::None)
        : Piece(Type::King, color) {}
    bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;
    void draw_scope(int selected_piece_position, int cell_position,std::array<std::unique_ptr<Piece>, 64>& board) override;
};