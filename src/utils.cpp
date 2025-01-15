#include <imgui.h>
#include <iostream>
#include <string>
#include <vector>

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