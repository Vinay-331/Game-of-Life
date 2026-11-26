#include <raylib.h>
#include "GameOfLife.hpp"

int main(){
    Grid grid(1000,1000,5);
    int WINDOW_WIDTH = 1000;
    int WINDOW_HEIGHT = 1000;
    InitWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"Conway's Game Of Life");
    SetTargetFPS(12);
    grid.randomize();
    while (WindowShouldClose()==false){
        BeginDrawing();
        ClearBackground(BLACK);
        grid.update();
        grid.draw();
        EndDrawing();
    }
    CloseWindow();
}