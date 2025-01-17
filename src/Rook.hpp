#pragma once
#include "Piece.hpp"

class Rook : public Piece {
public:
    explicit Rook(const Color color = Color::None)
        : Piece(Type::Rook, color) {}
    bool move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;
};