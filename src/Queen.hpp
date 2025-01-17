#pragma once
#include "Piece.hpp"

class Queen : public Piece {
public:
    explicit Queen(const Color color = Color::None)
        : Piece(Name::Queen, color) {}
    void move() override;
};