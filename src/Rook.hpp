#pragma once
#include "Piece.hpp"

class Rook : public Piece {
public:
    explicit Rook(const Color color = Color::None)
        : Piece(Name::Rook, color) {}
    void move() override;
};