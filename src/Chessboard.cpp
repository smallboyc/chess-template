#include "Chessboard.hpp"
#include <imgui.h>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <memory>
#include "Bishop.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Piece.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "utils.hpp"

// Create
void Chessboard::create_board()
{
    std::array<PiecePositions, 6> initial_positions = {
        PiecePositions{Type::Pawn, {8, 9, 10, 11, 12, 13, 14, 15}, {48, 49, 50, 51, 52, 53, 54, 55}},
        PiecePositions{Type::Rook, {0, 7}, {56, 63}},
        PiecePositions{Type::Knight, {1, 6}, {57, 62}},
        PiecePositions{Type::Bishop, {2, 5}, {58, 61}},
        PiecePositions{Type::Queen, {3}, {59}},
        PiecePositions{Type::King, {4}, {60}}
    };

    for (const PiecePositions& piece_positions : initial_positions)
    {
        set_piece_on_board(piece_positions, Color::White);
        set_piece_on_board(piece_positions, Color::Black);
    }
}

void Chessboard::set_piece_on_board(const PiecePositions& piece_positions, const Color& piece_color)
{
    std::vector<int> current_piece_color = piece_positions.white_position;
    if (piece_color == Color::Black)
        current_piece_color = piece_positions.black_position;

    for (const int& piece_position : current_piece_color)
        m_board[piece_position] = create_piece(piece_positions.piece_type, piece_color);
}

std::unique_ptr<Piece> Chessboard::create_piece(const Type& piece_type, const Color& piece_color)
{
    if (piece_type == Type::Pawn)
        return std::make_unique<Pawn>(piece_color);
    else if (piece_type == Type::Knight)
        return std::make_unique<Knight>(piece_color);
    else if (piece_type == Type::Bishop)
        return std::make_unique<Bishop>(piece_color);
    else if (piece_type == Type::Rook)
        return std::make_unique<Rook>(piece_color);
    else if (piece_type == Type::King)
        return std::make_unique<King>(piece_color);
    else if (piece_type == Type::Queen)
        return std::make_unique<Queen>(piece_color);
    return nullptr;
}

// Display
void Chessboard::display_board()
{
    bool  toggle_color_row_start = false;
    Color current_color_cell     = Color::None;
    for (int i{0}; i < m_board.size(); i++)
    {
        toggle_color_row_start = i % static_cast<int>(std::sqrt(m_board.size())) == 0;

        if (!toggle_color_row_start)
            current_color_cell = current_color_cell == Color::Black ? Color::White : Color::Black;
        draw_cell(i, current_color_cell);
    }
}

void Chessboard::draw_cell(int cell_position, const Color& color)
{
    const char* cell_label = "";
    if (m_board[cell_position] != nullptr)
        cell_label = m_board[cell_position]->get_symbol().c_str();

    ImGui::PushID(cell_position);
    ImGui::PushStyleColor(ImGuiCol_Button, color_to_rgba(color));
    ImVec4 cell_color;

    if (m_board[cell_position] != nullptr)
        cell_color = m_board[cell_position]->get_color() == Color::Black ? ImVec4(0.0f, 0.0f, 0.0f, 1.0f) : ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

    ImGui::PushStyleColor(ImGuiCol_Text, cell_color);
    if (ImGui::Button(cell_label, ImVec2(70.0f, 70.0f)))
    {
        if (piece_can_be_selected(cell_position))
        {
            m_selected_piece_position = cell_position;
            std::cout << m_selected_piece_position << "\n";
        }
        else if (piece_selected() && m_board[m_selected_piece_position]->can_move(m_selected_piece_position, cell_position, m_board))
        {
            m_board[m_selected_piece_position]->move(m_selected_piece_position, cell_position, m_board);
            clear_selection();
            set_piece_turn();
        }
    }

    // On dessine le SCOPE de la pièce sélectionnée :
    // A chaque draw d'une cellule on regarde si celle-ci correspond à la cellule où le user click, et on fait des trucs!
    // if (m_selected_piece_position != -1)
    //     m_board[m_selected_piece_position]->draw_scope(m_selected_piece_position, cell_position, m_board);

    ImGui::PopStyleColor(2);
    ImGui::PopID();

    if ((cell_position + 1) % static_cast<int>(std::sqrt(m_board.size())) != 0)
        ImGui::SameLine(0.0f, 0.0f);
}

bool Chessboard::piece_can_be_selected(int cell_position)
{
    return m_board[cell_position] != nullptr && m_board[cell_position]->get_color() == m_color_piece_turn;
}

void Chessboard::set_piece_turn()
{
    m_color_piece_turn = m_color_piece_turn == Color::White ? Color::Black : Color::White;
}

bool Chessboard::piece_selected() const
{
    return (m_selected_piece_position != -1);
}