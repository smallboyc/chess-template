#include "Cell.hpp"
#include <iostream>
#include <string>

ImVec4 Cell::color_to_rgba() const
{
    return get_color() == Color::Black ? ImVec4(0.541f, 0.518f, 0.761f, 1.0f) : ImVec4(0.859f, 0.839f, 0.792f, 1.0f);
}

void Cell::draw() const
{
    ImVec4 text_color = {0.851f, 0.243f, 0.69f, 1.f};
    ImGui::PushID(get_position());
    ImGui::PushStyleColor(ImGuiCol_Button, color_to_rgba());
    ImGui::PushStyleColor(ImGuiCol_Text, text_color);

    if (ImGui::Button(std::to_string(get_position()).c_str(), ImVec2(50.0f, 50.0f)))
        std::cout << "Clicked button + " + std::to_string(get_position()) + "\n";

    ImGui::PopStyleColor(2);
    ImGui::PopID();
}
