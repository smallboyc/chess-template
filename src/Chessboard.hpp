#pragma once
#include <memory>
#include "Piece.hpp"

class Chessboard {
private:
    std::array<std::unique_ptr<Piece>, 64> m_board;

public:
    Chessboard()
    {
        create_board();
    };
    // Create
    void                   create_board();
    void                   set_piece_on_board(const PiecePositions& piece_positions, const Color& piece_color);
    std::unique_ptr<Piece> create_piece(const Name& piece_name, const Color& piece_color);
    // Display
    void display_board() const;
    void draw_cell(int cell_position, const Color& color, const std::unique_ptr<Piece>& piece) const;
};