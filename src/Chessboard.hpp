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
    void                   draw_cell(int cell_position, const Color& color, const std::unique_ptr<Piece>& piece) const;
    Color                  get_piece_color(const PiecePosition& piece_position, int cell_position);
    std::unique_ptr<Piece> create_piece(const Color& piece_color, const PiecePosition& piece_position);
    void                   create_board();
    void                   display_board() const;
};