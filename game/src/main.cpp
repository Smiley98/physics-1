#include "raylib.h"
#include "raymath.h"

int main()
{
    InitWindow(800, 800, "Physics-1");
    SetTargetFPS(60);

    Rectangle platform;
    platform.x = 0.0f;
    platform.y = 600.0f;
    platform.width = 100.0f;
    platform.height = 20.0f;

    Rectangle ground;
    ground.x = 0.0f;
    ground.y = 780.0f;
    ground.width = 800.0f;
    ground.height = 20.0f;

    float radius = 10.0f;
    Vector2 birdPosition;
    birdPosition.x = platform.x + platform.width - radius;
    birdPosition.y = platform.y - (platform.height - radius);

    float launchSpeed = 100.0f;
    float launchAngle = 0.0f;

    // Re-assign launchVelocity like so when space is pressed (for part 1)
    Vector2 launchPosition = birdPosition;
    Vector2 launchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed;
    Vector2 futureLaunchVelocity = launchVelocity;

    Vector2 birdVelocity = launchVelocity;
    Vector2 birdAcceleration = { 0.0f, 9.81f };

    // All you have to do for lab exercise 2 is add the remaining if-statements to countrol launch angle and launch speed
    // Be sure to complete the re-launch logic when space is pressed too!
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // When space is pressed (lab 2 part 1):
        if (IsKeyPressed(KEY_SPACE))
        {
            // 1. Set birdPosition to launchPosition
            // 2. Set birdVelocity based on launchAngle and launchSpeed (see initial launchVelocity assignment for reference)
        }

        if (IsKeyDown(KEY_ONE))
        {
            launchPosition.x += 100.0f * dt;
        }

        if (IsKeyDown(KEY_TWO))
        {
            launchPosition.x -= 100.0f * dt;
        }

        if (IsKeyDown(KEY_THREE))
        {
            launchPosition.y += 100.0f * dt;
        }

        if (IsKeyDown(KEY_FOUR))
        {
            launchPosition.y -= 100.0f * dt;
        }

        if (IsKeyDown(KEY_FIVE))
        {
            // Rotate counter-clockwise at 90 degrees per second
            launchAngle -= 90.0f * DEG2RAD * dt;
        }

        futureLaunchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed;
        
        birdVelocity += birdAcceleration * dt;
        birdPosition += birdVelocity * dt;

        BeginDrawing();
            ClearBackground(WHITE);

            // Where our bird should launch from when we press space
            DrawCircleV(launchPosition, radius, ORANGE);

            // Our bird's current position
            DrawCircleV(birdPosition, radius, RED);

            // Ground at the bottom of the screen, and a platform 3/4's the way down the screen
            DrawRectangleRec(platform, DARKGRAY);
            DrawRectangleRec(ground, BEIGE);

            // Show the result of user-defined launch-angle * launch-speed
            DrawLineEx(launchPosition, launchPosition + futureLaunchVelocity, 2.0f, GOLD);

            // Labels for user-defined launch values
            DrawText(TextFormat("Launch Position: %f %f", launchPosition.x, launchPosition.y), 10, 10, 20, RED);
            DrawText(TextFormat("Launch Angle: %f", launchAngle), 10, 40, 20, ORANGE);
            DrawText(TextFormat("Launch Speed: %f", launchSpeed), 10, 70, 20, GOLD);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
