#pragma once
#include <memory>
#include "Piece.hpp"
#include "utils.hpp"

class Chessboard {
private:
    std::array<std::unique_ptr<Piece>, 64> m_board;
    Color                                  m_color_piece_turn        = Color::White;
    int                                    m_selected_piece_position = -1;

public:
    Chessboard()
    {
        create_board();
    };
    // Create
    void                   create_board();
    void                   set_piece_on_board(const PiecePositions& piece_positions, const Color& piece_color);
    std::unique_ptr<Piece> create_piece(const Type& piece_type, const Color& piece_color);
    // Display
    void display_board();
    void draw_cell(int cell_position, const Color& color);
    // check
    void   clear_selection() { m_selected_piece_position = -1; };
    bool   piece_selected() const;
    bool   piece_can_be_selected(int cell_position);
    void   set_piece_turn();
    ImVec4 get_piece_icon_color(int cell_position);

    //end_game?
    int get_king_position();
    bool king_is_in_check();
    bool checkmate();
};