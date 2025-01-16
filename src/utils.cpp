#include "utils.hpp"
#include <imgui.h>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

ImVec4 color_to_rgba(const Color& color)
{
    return color == Color::Black ? ImVec4(0.541f, 0.518f, 0.761f, 1.0f) : ImVec4(0.859f, 0.839f, 0.792f, 1.0f);
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

// TODO(smallboyc): on main function
//  ImGui::CreateContext();
// ImGuiIO& io   = ImGui::GetIO();
// ImFont*  font = io.Fonts->AddFontFromFileTTF("../../assets/fonts/roboto.ttf", 16.0f);
// std::vector<ImFont*> custom_fonts = load_fonts();
// if (!custom_fonts.empty())
// ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);