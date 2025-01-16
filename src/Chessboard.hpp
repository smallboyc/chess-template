#pragma once
#include <memory>
#include <utility>
#include "Cell.hpp"
#include "Piece.hpp"
// #include "Pawn.hpp"

class Chessboard {
private:
    std::array<std::unique_ptr<Piece>, 64> m_board;

    // Pieces
    // std::vector<Pawn> m_pawns;
    /*std::vector<Rook> m_rooks;*/
    /*std::vector<Bishop> m_bishop;*/
    /*std::vector<Knight> m_knights;*/
    /*Queen m_queen;*/
    /*King m_king;*/

public:
    Chessboard()
    {
        create_board();
    };
    void                   draw_cell(int cell_position, const Color& color, const std::unique_ptr<Piece>& piece) const;
    void                   create_board();
    void                   display_board() const;
    Color                  get_piece_color(const PiecePosition& piece_position, int cell_position);
    std::unique_ptr<Piece> create_piece(const Color& piece_color, const PiecePosition& piece_position);
};