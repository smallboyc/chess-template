#include <vector>
#include "Cell.hpp"
// #include "Pawn.hpp"

class Chessboard {
private:
    std::vector<Cell> m_board;
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
    void create_board();
    void display_board();
};