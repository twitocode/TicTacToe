#include "Cell.h"
#include <raylib.h>
#include <iostream>

Cell::Cell(Vector2 pos, Vector2 size, int cellNumber) : pos(pos), size(size), cellNumber(cellNumber) {}

void Cell::Draw() { DrawRectangleLines(pos.x, pos.y, size.x, size.y, WHITE); }

void Cell::Update(const Vector2 &mousePosition) {
    bool isBetweenX = mousePosition.x > pos.x && mousePosition.x < pos.x + size.x;
    bool isBetweenY = mousePosition.y > pos.y && mousePosition.y < pos.y + size.y;

    if (isBetweenX && isBetweenY) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            std::cout << TextFormat("Pressed cell: %i", cellNumber) << std::endl;
        }
    }
}