#pragma once
#include <imgui.h>
#include "utils.hpp"

class Cell {
public:
    explicit Cell(int position = 0, Color color = Color::None)
        : m_position(position), m_color(color){};
    void   draw() const;
    int    get_position() const { return m_position; };
    Color  get_color() const { return m_color; };
    ImVec4 color_to_rgba() const;

    void fill() { m_empty = false; };
    bool is_empty() const { return m_empty; };

private:
    int   m_position;
    Color m_color;
    bool  m_empty = true;
};
