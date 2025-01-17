#pragma once
#include "Piece.hpp"

class Knight : public Piece {
public:
    explicit Knight(const Color color = Color::None)
        : Piece(Type::Knight, color) {}
    bool move(int from, int to,std::array<std::unique_ptr<Piece>, 64> &board) override;
};