#pragma once
#include "Piece.hpp"

class King : public Piece {
public:
    explicit King(const Color color = Color::None)
        : Piece(Type::King, color) {}
    bool move(int from, int to,std::array<std::unique_ptr<Piece>, 64> &board) override;
};