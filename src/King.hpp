#pragma once
#include "Piece.hpp"

class King : public Piece {
public:
    explicit King(const Color color = Color::None)
        : Piece(Name::King, color) {}
    void move() override;
};