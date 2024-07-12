#include "Cell.h"
#include <iostream>
#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tic Tac Toe");

    static const int cellRowSize = 9;
    static const int cellColSize = 9;
    Cell cells[cellRowSize][cellColSize];

    SetTargetFPS(60);

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            float offset = GetScreenWidth() / 4 + 100;
            Vector2 pos{offset + (100 * (float)col + 1), 10 + (100 * (float)row + 1)};
            Vector2 size{100, 100};

            int cellNumber;
            switch (row) {
            case 0:
                cellNumber = 1 + col;
                break;
            case 1:
                cellNumber = 4 + col;
                break;
            case 2:
                cellNumber = 7 + col;
                break;
            }
            cells[row][col] = Cell(pos, size, cellNumber);
        }
    }

    while (!WindowShouldClose()) {
        // Updating the game
        Vector2 mousePosition = GetMousePosition();

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                cells[row][col].Update(mousePosition);
            }
        }

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                cells[row][col].Draw();
            }
        }

        EndDrawing();
    }

    CloseWindow();
}