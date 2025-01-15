#include "Piece.hpp"

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
    else if (m_name == Name::Pawn)
        return "P";
    return " ";
}

void Piece::set_position(int position)
{
    if (position >= 0 && position < 64)
        m_position = position;
}

int Piece::direction() const
{
    return get_color() == Color::Black ? -1 : 1;
}