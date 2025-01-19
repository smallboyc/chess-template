#pragma once
#include "Piece.hpp"

class Bishop : public Piece {
public:
    explicit Bishop(const Color color = Color::None)
        : Piece(Type::Bishop, color) {}
    bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;
    void check_for_obstacles(int selected_piece_position, std::array<std::unique_ptr<Piece>, 64>& board) override {};
    void draw_scope(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override {};
};