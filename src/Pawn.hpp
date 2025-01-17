#pragma once

#include "Piece.hpp"

class Pawn : public Piece {
public:
    explicit Pawn(const Color color = Color::None)
        : Piece(Type::Pawn, color) {}
    bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;

private:
    int m_step{0};
};