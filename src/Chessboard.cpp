#include "Chessboard.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <memory>
#include "Pawn.hpp"
#include "Piece.hpp"
#include "utils.hpp"

void Chessboard::draw_cell(int cell_position, const Color& color, const std::unique_ptr<Piece>& piece) const
{
    ImVec4 text_color = {0.851f, 0.243f, 0.69f, 1.f};
    ImGui::PushID(cell_position);
    ImGui::PushStyleColor(ImGuiCol_Button, color_to_rgba(color));
    ImGui::PushStyleColor(ImGuiCol_Text, text_color);
    const char* cell_label = "";
    if (piece != nullptr)
        cell_label = piece->get_symbol().c_str();

    if (ImGui::Button(cell_label, ImVec2(50.0f, 50.0f)))
        std::cout << "Clicked button + " + std::to_string(cell_position) + "\n";
    ImGui::PopStyleColor(2);
    ImGui::PopID();

    // new line if endline.
    if ((cell_position + 1) % static_cast<int>(std::sqrt(m_board.size())) != 0)
        ImGui::SameLine();
}

void Chessboard::create_board()
{
    std::array<PiecePosition, 6> initial_positions = {
        PiecePosition{Name::Pawn, {8, 9, 10, 11, 12, 13, 14, 15}, {48, 49, 50, 51, 52, 53, 54, 55}},
        PiecePosition{Name::Rook, {0, 7}, {56, 63}},
        PiecePosition{Name::Knight, {1, 6}, {57, 62}},
        PiecePosition{Name::Bishop, {2, 5}, {58, 61}},
        PiecePosition{Name::Queen, {3}, {59}},
        PiecePosition{Name::King, {4}, {60}}
    };

    for (int i{0}; i < m_board.size(); i++)
    {
        for (const PiecePosition& piece_position : initial_positions)
        {
            Color piece_color = get_piece_color(piece_position, i);
            if (piece_color != Color::None)
            {
                m_board[i] = create_piece(piece_color, piece_position);
                break;
            }
        }
    }
}

Color Chessboard::get_piece_color(const PiecePosition& piece_position, int cell_position)
{
    if (std::find(piece_position.black_position.begin(), piece_position.black_position.end(), cell_position) != piece_position.black_position.end())
        return Color::Black;
    else if (std::find(piece_position.white_position.begin(), piece_position.white_position.end(), cell_position) != piece_position.white_position.end())
        return Color::White;
    return Color::None;
}

void Chessboard::display_board() const
{
    bool  toggle_color_row_start = false;
    Color current_color_cell     = Color::None;
    for (int i{0}; i < m_board.size(); i++)
    {
        toggle_color_row_start = i % static_cast<int>(std::sqrt(m_board.size())) == 0;

        if (!toggle_color_row_start)
            current_color_cell = current_color_cell == Color::Black ? Color::White : Color::Black;
        draw_cell(i, current_color_cell, m_board[i]);
    }
}

std::unique_ptr<Piece> Chessboard::create_piece(const Color& piece_color, const PiecePosition& piece_position)
{
    if (piece_position.piece_name == Name::Pawn)
        return std::make_unique<Pawn>(piece_color);
    return nullptr;
    // TODO(smallboyc): implémenter la suite pour les autre pièces.
}