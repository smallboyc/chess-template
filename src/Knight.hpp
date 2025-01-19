#pragma once
#include "Piece.hpp"

class Knight : public Piece {
public:
    explicit Knight(const Color color = Color::None)
        : Piece(Type::Knight, color) {}
    bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;
    void check_for_obstacles(int selected_piece_position, std::array<std::unique_ptr<Piece>, 64>& board) override {};
    void draw_scope(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override {};
};