#pragma once

#include "Piece.hpp"

class Pawn : public Piece {
public:
    explicit Pawn(const Color color = Color::None)
        : Piece(Type::Pawn, color) {}
    bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override;
    //* MOVES *//
    bool special_move(int from, int attempted_move, std::array<std::unique_ptr<Piece>, 64>& board);
    bool classic_move(int from, int attempted_move, std::array<std::unique_ptr<Piece>, 64>& board);
    bool capture_move(int from, int attempted_move, std::array<std::unique_ptr<Piece>, 64>& board);
    //
    void check_for_obstacles(int selected_piece_position, std::array<std::unique_ptr<Piece>, 64>& board) override {};
    void draw_scope(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) override {};
    bool is_vulnerable_to_in_passing() const override { return m_vulnerable; };
    // scope
    bool target_cell_scope(int selected_piece_position, int cell_position, int range);

private:
    bool               m_vulnerable{false};
    int                m_step{0};
    int                m_classique_move{8 * direction()};
    int                m_special_move{16 * direction()};
    std::array<int, 2> m_capture_move{7 * direction(), 9 * direction()};
};
