#pragma once
#include "Piece.hpp"

class Bishop : public Piece {
public:
    explicit Bishop(const Color color = Color::None)
        : Piece(Type::Bishop, color) {}
    bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;
    bool move_is_legit(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board, int direction, int pattern);
    void draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) override;

private:
    // std::array<int, 2> m_move{7, 9};
};