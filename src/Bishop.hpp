#pragma once
#include "Piece.hpp"

class Bishop : public Piece {
public:
    explicit Bishop(const Color color = Color::None)
        : Piece(Type::Bishop, color) {}
    bool move(int from, int to,std::array<std::unique_ptr<Piece>, 64> &board) override;
};