#pragma once
#include "Piece.hpp"

class Rook : public Piece {
public:
    explicit Rook(const Color color = Color::None)
        : Piece(Type::Rook, color) {}
    bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;
    bool move_is_legit(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board, int direction, int pattern);
    void draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) override;
};