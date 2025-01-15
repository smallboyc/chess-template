#include "Piece.hpp"

class Pawn : public Piece {
public:
    explicit Pawn(const Color color = Color::White, const int position = 0)
        : Piece(Name::Pawn, color, position) {}
    void move(int position);
    bool special_start() const { return m_special_start; };
    void cancel_special_start() { m_special_start = false; };

private:
    bool m_special_start = true;
};