#pragma once
#include "Piece.hpp"

class Pawn : public Piece {
public:
    explicit Pawn(const Color color = Color::None)
        : Piece(Name::Pawn, color) {}
    void move(int position);
    bool special_start() const { return m_special_start; };
    void cancel_special_start() { m_special_start = false; };

private:
    bool m_special_start = true;
};