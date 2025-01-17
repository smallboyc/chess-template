#pragma once
#include <imgui.h>
#include <array>
#include <string>
#include <vector>
#include "utils.hpp"

enum class Type {
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
    Type             piece_type;
    std::vector<int> black_position;
    std::vector<int> white_position;
};

class Piece {
public:
    explicit Piece(const Type type = Type::None, const Color color = Color::None)
        : m_type(type), m_color(color){};
    virtual ~Piece()               = default;
    Piece(const Piece&)            = delete;
    Piece& operator=(const Piece&) = delete;
    Piece(Piece&&)                 = default; // :o
    Piece& operator=(Piece&&)      = default;

    Type         get_type() const { return m_type; };
    Color        get_color() const { return m_color; };
    std::string  get_symbol() const;
    int          direction() const;
    virtual bool can_move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board) = 0;
    void         move(int from, int to, std::array<std::unique_ptr<Piece>, 64>& board);

private:
    Type  m_type;
    Color m_color;
};
