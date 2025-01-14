#include <imgui.h>
#include <string>
#include <utility>

enum class Color {
    White,
    Black,
};

enum class Name {
    King,
    Queen,
    Bishop,
    Knight,
    Rook,
    Pawn,
};

class Piece {
public:
    explicit Piece(const Name name = Name::Pawn, const Color color = Color::White, const int position = 0)
        : m_name(name), m_color(color), m_position(position){};
    std::string get_symbol() const;
    ImVec4      get_color() const;

private:
    Name  m_name;
    Color m_color;
    int   m_position;
};