#include "Pawn.hpp"
#include <iostream>
#include "Piece.hpp"

bool Pawn::can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board)
{
    // Déplacement ok si : case vide OU la pièce que je remplace est de couleur différente
    if (board[to] != nullptr && board[from]->get_color() == board[to]->get_color())
    {
        std::cout << "Pas de déplacement" << "\n";
        return false;
    }

    int classic_move = 8 * direction();
    // int special_move = 2 * classic_move * direction();
    // for (int i{from}; i < to; i += classic_move)
    // {
    //     if (board[i] != nullptr)
    //         return false;
    // }

    if (from + classic_move == to) // classic move
    {
        std::cout << "De " << from << " à " << to << " pour " << board[from]->get_symbol() << "\n";
        return true;
    }
}