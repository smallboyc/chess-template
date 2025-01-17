#include "Piece.hpp"

std::string Piece::get_symbol() const
{
    if (m_type == Type::King)
        return "K";
    else if (m_type == Type::Queen)
        return "Q";
    else if (m_type == Type::Bishop)
        return "B";
    else if (m_type == Type::Knight)
        return "N";
    else if (m_type == Type::Rook)
        return "R";
    else if (m_type == Type::Pawn)
        return "P";
    return " ";
}

int Piece::direction() const
{
    return get_color() == Color::Black ? 1 : -1;
}

void Piece::move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    board[to] = std::move(board[from]);
}
