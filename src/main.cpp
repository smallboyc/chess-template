#include <imgui.h>
#include "Chessboard.hpp"
#include "quick_imgui/quick_imgui.hpp"

int main()
{
    Chessboard chessboard;

    quick_imgui::loop(
        "Chess",
        [&]() {
            // std::vector<ImFont*> fonts = load_fonts();
            // ImGui::PushFont(fonts[0]);
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