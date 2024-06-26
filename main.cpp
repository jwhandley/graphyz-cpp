#include <raylib.h>
#include "simulation.hpp"



int main(void) {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Hello, raylib!");

    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircle(screenWidth / 2, screenHeight / 2, 50, MAROON);

        DrawFPS(10, 10);

        EndDrawing();
    }

    return 0;
}