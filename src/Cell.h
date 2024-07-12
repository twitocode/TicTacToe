#pragma once
#include <raylib.h>

class Cell {
private:
    Vector2 size;
    Vector2 pos;
    int cellNumber;
public:
    Cell(Vector2 pos, Vector2 size, int cellNumber);
    Cell() {}

    void Draw();
    void Update(const Vector2 &mousePosition);
};