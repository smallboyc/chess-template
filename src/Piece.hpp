#pragma once
#include <imgui.h>
#include <string>
#include <vector>
#include "utils.hpp"

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

struct PiecePositions {
    Name             piece_name;
    std::vector<int> white_position;
    std::vector<int> black_position;
};

class Piece {
public:
    explicit Piece(const Name name = Name::None, const Color color = Color::None)
        : m_name(name), m_color(color){};
    virtual ~Piece()               = default;
    Piece(const Piece&)            = delete;
    Piece& operator=(const Piece&) = delete;
    Piece(Piece&&)                 = default; // :o
    Piece& operator=(Piece&&)      = default;

    Name         get_name() const { return m_name; };
    Color        get_color() const { return m_color; };
    std::string  get_symbol() const;
    void         select() { m_selected = true; }
    bool         is_selected() const { return m_selected; };
    int          direction() const;
    virtual void move() = 0;

private:
    Name  m_name;
    Color m_color;
    bool  m_selected = false;
};
