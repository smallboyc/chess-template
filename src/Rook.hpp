#pragma once
#include "Piece.hpp"

class Rook : public Piece {
public:
    explicit Rook(const Color color = Color::None)
        : Piece(Type::Rook, color) {}
    bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;
    // scope
    void check_for_obstacles(int selected_piece_position, std::array<std::unique_ptr<Piece>, 64>& board) override;
    bool is_obstacle(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board);
    void draw_scope(int selected_piece_position, int cell_position, std::array<std::unique_ptr<Piece>, 64>& board) override;

private:
    std::vector<int> m_obstacles;
};