#pragma once
#include "Piece.hpp"

class Pawn : public Piece {
public:
    explicit Pawn(const Color color = Color::None)
        : Piece(Name::Pawn, color) {}
    bool special_start() const { return m_special_start; };
    void cancel_special_start() { m_special_start = false; };
    void move() override;

private:
    bool m_special_start = true;
};