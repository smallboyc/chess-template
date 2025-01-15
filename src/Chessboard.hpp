#include <vector>
#include "Pawn.hpp"

class Chessboard {
private:
    std::vector<Pawn> m_pawns;
    /*std::vector<Rook> m_rooks;*/
    /*std::vector<Bishop> m_bishop;*/
    /*std::vector<Knight> m_knights;*/
    /*Queen m_queen;*/
    /*King m_king;*/

public:
    Chessboard() = default;
    void draw();
};