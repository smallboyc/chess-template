#pragma once
#include "Piece.hpp"

class Knight : public Piece {
public:
    explicit Knight(const Color color = Color::None)
        : Piece(Type::Knight, color) {}
    void move() override;
};