#include <imgui.h>
#include <iostream>
#include <string>
#include <vector>
#include "Pawn.hpp"
#include "quick_imgui/quick_imgui.hpp"

struct Cell {
    int         position{};
    std::string piece{};
    bool        piece_on_cell{};
};

std::vector<Cell> create_board(int board_size)
{
    std::vector<Cell> board;
    for (int i{0}; i < board_size; i++)
    {
        Cell new_cell{i, " ", false};
        board.push_back(new_cell);
    }
    return board;
}

void draw_cell(const Cell& cell, bool& toggle, const ImVec2 positions, Pawn& pawn)
{
    ImVec4 current_color;
    ImVec4 text_color = {0.851f, 0.243f, 0.69f, 1.f};
    if (toggle)
    {
        current_color = {0.859f, 0.839f, 0.792f, 1.0f};
        toggle        = false;
    }
    else
    {
        current_color = {0.278f, 0.267f, 0.231f, 1.0f};
        toggle        = true;
    }

    ImGui::PushID(cell.position);
    ImGui::PushStyleColor(ImGuiCol_Button, current_color);
    ImGui::PushStyleColor(ImGuiCol_Text, text_color);

    std::string label         = cell.piece;
    std::string cell_position = std::to_string(cell.position);
    if (ImGui::Button((label.c_str()), positions))
        pawn.move(cell.position);
    // std::cout << "Clicked button + " + cell_position + "\n";

    ImGui::PopStyleColor(2);
    ImGui::PopID();
}

std::vector<ImFont*> load_fonts()
{
    ImGuiIO&                       io = ImGui::GetIO();
    std::vector<ImFont*>           loaded_fonts;
    float                          font_size{16.0f};
    std::string                    fonts_path    = "../../assets/fonts/";
    const std::vector<std::string> fonts_to_load = {
        fonts_path + "roboto.ttf",
        fonts_path + "chess.TTF"
    };

    for (const std::string& font_path : fonts_to_load)
    {
        ImFont* font = io.Fonts->AddFontFromFileTTF(font_path.c_str(), font_size);
        if (!font)
            std::cerr << "Failed to load font: " << font_path << " :(" << "\n";
        else
        {
            loaded_fonts.push_back(font);
            std::cout << "Font successfully loaded : " << font_path << "\n";
        }
    }
    return loaded_fonts;
}

int main()
{
    ImGui::CreateContext();
    // ImGuiIO& io   = ImGui::GetIO();
    // ImFont*  font = io.Fonts->AddFontFromFileTTF("../../assets/fonts/roboto.ttf", 16.0f);
    // std::vector<ImFont*> custom_fonts = load_fonts();
    // if (!custom_fonts.empty())
    // ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);

    // TODO : Cell doit prendre aussi des pièces pour pouvoir afficher la position relative.
    std::vector<Cell> board = create_board(64);

    bool  toggle = true; // switch color print on board!
    float size   = 50.f; // cell size

    Pawn pawn;
    std::cout << pawn.get_symbol() << "\n";

    quick_imgui::loop(
        "Chess",
        [&]() {
            // std::vector<ImFont*> fonts = load_fonts();
            // ImGui::PushFont(fonts[0]);
        },
        [&]() {
            ImGui::Begin("Chess Board");

            for (Cell& cell : board)
            {
                draw_cell(cell, toggle, {size, size}, pawn);
                if ((cell.position + 1) % 8 != 0)
                    ImGui::SameLine();
                else
                    toggle = !toggle;
            }
            ImGui::End();
        }
    );
}