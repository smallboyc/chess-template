#include <imgui.h>
#include <string>

enum class Color {
    White,
    Black,
    /*default*/
    None,
};

enum class Name {
    King,
    Queen,
    Bishop,
    Knight,
    Rook,
    Pawn,
    /*default*/
    None,
};

class Piece {
public:
    explicit Piece(const Name name = Name::None, const Color color = Color::None, const int position = 0)
        : m_name(name), m_color(color), m_position(position){};

    Name  get_name() const { return m_name; };
    Color get_color() const { return m_color; };
    int   get_position() const { return m_position; };
    //
    std::string get_symbol() const;
    void        set_position(int position);
    void        select() { m_selected = true; }
    bool        is_selected() const { return m_selected; };
    bool        is_alive() const { return m_alive; };
    int         direction() const;

private:
    Name  m_name;
    Color m_color;
    int   m_position;
    bool  m_selected = false;
    bool  m_alive    = true;
};