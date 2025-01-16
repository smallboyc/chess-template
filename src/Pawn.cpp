#include "Pawn.hpp"

// void Pawn::move(int position)
// {

//     int current_position = get_position();
//     if (special_start())
//     {
//         if (current_position + direction() * 16 == position) // move x2 (only on start)
//             set_position(position);
//         cancel_special_start();
//     }
//     else
//     {
//         if (current_position + direction() * 8 == position) // classic move
//             set_position(position);
//     }
// }