#pragma once
#include <vector>
#include <iostream>
#include <raylib.h>

class Grid{
  public:
    Grid(int w, int h, int s) : rows(h/s), columns(w/s), cellsize(s){
        for (int i=0;i<200;i++){
            cells.push_back({0});
            for (int j=0;j<199;j++){
                cells[i].push_back({0});
            }
        }
    };
    void randomize(){
        for (int r=0;r<200;r++){
            for (int c=0;c<200;c++){
                if (2==GetRandomValue(1,5)){
                    cells[r][c]=1;
                }
                else {
                    cells[r][c]=0;
                }
            }
        }
    }
    void update(){
        std::vector<std::vector<int>> next_cells = cells;
        for (int r=0;r<200;r++){
            for (int c=0;c<200;c++){
                int alive=0;
                int dead=0;
                for (int row_offset=-1;row_offset<=1; row_offset++){
                    for (int column_offset=-1;column_offset<=1;column_offset++){
                        if (row_offset==0 && column_offset==0){
                            continue;
                        }
                        if (cells[(r+row_offset+200)%200][(c+column_offset+200)%200] == 1){
                            alive++;
                        }
                        else if (cells[(r+row_offset+200)%200][(c+column_offset+200)%200] == 0){
                            dead++;
                        }
                        else {
                            continue;
                        }
                    }
                }
                if (cells[r][c]==1){
                    next_cells[r][c] = (alive == 2 || alive == 3) ? 1:0;
                }
                else {
                    next_cells[r][c] = (alive == 3 ) ? 1:0;
                }
            }
        }
        cells = next_cells;
    }
    void draw(){
        for (int r=0;r<200;r++){
            for (int c=0;c<200;c++){
                if (cells[r][c]==1){
                    DrawRectangle((c)*5,(r)*5,5,5,GREEN);
                }
            }
        }
    }
  private:
  int rows;
  int columns;
  int cellsize;
  std::vector<std::vector<int>> cells;
};