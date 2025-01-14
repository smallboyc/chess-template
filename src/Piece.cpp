#include "Piece.hpp"

ImVec4 Piece::get_color() const
{
    return m_color == Color::White ? ImVec4(1.0f, 1.0f, 1.0f, 1.0f) : ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
}

std::string Piece::get_symbol() const
{
    if (m_name == Name::King)
        return "♔";
    else if (m_name == Name::Queen)
        return "♕";
    else if (m_name == Name::Bishop)
        return "♗";
    else if (m_name == Name::Knight)
        return "♘";
    else if (m_name == Name::Rook)
        return "♖";
    return "♙";
}