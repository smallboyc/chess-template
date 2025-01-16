#include <imgui.h>
#include "Chessboard.hpp"
#include "quick_imgui/quick_imgui.hpp"

int main()
{
    Chessboard chessboard;

    quick_imgui::loop(
        "Chess",
        [&]() {
            ImGui::GetStyle().ItemSpacing = ImVec2(0.0f, 0.0f);
        },
        [&]() {
            ImGui::Begin("Chess Board");
            /**/
            chessboard.display_board();
            /**/
            ImGui::End();
        }
    );
}