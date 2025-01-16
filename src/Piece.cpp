#include "Piece.hpp"

std::string Piece::get_symbol() const
{
    if (m_name == Name::King)
        return "K";
    else if (m_name == Name::Queen)
        return "Q";
    else if (m_name == Name::Bishop)
        return "B";
    else if (m_name == Name::Knight)
        return "N";
    else if (m_name == Name::Rook)
        return "R";
    else if (m_name == Name::Pawn)
        return "P";
    return " ";
}

// void Piece::set_position(int position)
// {
//     if (position >= 0 && position < 64)
//         m_position = position;
// }

int Piece::direction() const
{
    return get_color() == Color::Black ? -1 : 1;
}