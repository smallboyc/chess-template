#include "Chessboard.hpp"
#include <cmath>
#include <cstddef>
#include <iostream>
#include <memory>
#include "Bishop.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
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
    ImGui::PushID(cell_position);
    ImGui::PushStyleColor(ImGuiCol_Button, color_to_rgba(color));
    ImGui::PushStyleColor(ImGuiCol_Text, {0.0f, 0.0f, 0.0f, 1.0f});
    const char* cell_label = "";
    if (m_board[cell_position] != nullptr)
        cell_label = m_board[cell_position]->get_symbol().c_str();

    if (ImGui::Button(cell_label, ImVec2(70.0f, 70.0f)))
    {
        // si je click sur une pièce, sa position devient m_selected_cell_position
        if (!empty_cell(cell_position))
            m_selected_piece_position = cell_position;

        if (piece_selected() && empty_cell(cell_position))
        {
            // Checker si le move est legit pour la pièce sélectionnée = m_board[m_selected_cell_position]
            // si oui alors std::move :
            m_board[cell_position] = std::move(m_board[m_selected_piece_position]);
            std::cout << "Case " + std::to_string(cell_position) + " => " + cell_label << "\n";
        }
    }
    ImGui::PopStyleColor(2);
    ImGui::PopID();

    if ((cell_position + 1) % static_cast<int>(std::sqrt(m_board.size())) != 0)
        ImGui::SameLine(0.0f, 0.0f);
}

bool Chessboard::empty_cell(int cell_position)
{
    return m_board[cell_position] == nullptr;
}

bool Chessboard::piece_selected() const
{
    return (m_selected_piece_position != -1);
}