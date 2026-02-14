#include "raylib.h"
#include <string>
using namespace std;

int main() {
    InitWindow(800, 300, "Spam Detector");
    SetTargetFPS(60);

    string msg = "";

    while (!WindowShouldClose()) {

        // --- INPUT ---
        int key = GetCharPressed();
        while (key > 0) {
            if (msg.length() < 40)
                msg += (char)key;
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && msg.length() > 0)
            msg.pop_back();

        // --- SPAM LOGIC ---
        int score = 0;
        string temp = msg;

        for (int i = 0; i < temp.length(); i++)
            temp[i] = tolower(temp[i]);

        if (temp.find("win") != string::npos) score++;
        if (temp.find("free") != string::npos) score++;
        if (temp.find("click") != string::npos) score++;
        if (temp.find("offer") != string::npos) score++;
        if (temp.find("urgent") != string::npos) score++;
        if (temp.find("gift") != string::npos) score++;

        // --- RESULT ---
        const char* result;
        Color color;

        if (score == 0) {
            result = "SAFE";
            color = GREEN;
        } else if (score == 1) {
            result = "SUSPICIOUS";
            color = YELLOW;
        } else {
            result = "SPAM";
            color = RED;
        }

        // --- DRAW ---
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Type a message:", 50, 40, 20, BLACK);
        DrawRectangleLines(50, 70, 700, 40, BLACK);
        DrawText(msg.c_str(), 60, 80, 20, BLACK);

        DrawText("Result:", 50, 140, 20, BLACK);
        DrawText(result, 50, 170, 40, color);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
