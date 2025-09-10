#include "raylib.h"
#include "raymath.h"

int main()
{
    InitWindow(800, 800, "Physics-1");

    Vector2 circle_position = { 400.0f, 400.0f };
    float circle_radius = 25.0f;
    Color circle_color = PURPLE;

    float a = 1.0f;
    float b = 50.0f;

    while (!WindowShouldClose())
    {
        float t = GetTime();
        float dt = GetFrameTime();

        circle_position.x = circle_position.x + (-sinf(t * a)) * a * b * dt;
        circle_position.y = circle_position.y + (cosf(t * a)) * a * b * dt;

        BeginDrawing();
            ClearBackground(WHITE);
            DrawText(TextFormat("Total Time: %f", t), 750, 0, 20, BLUE);
            DrawCircleV(circle_position, circle_radius, circle_color);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
