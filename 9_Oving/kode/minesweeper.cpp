#include<iostream>

#include "minesweeper.h"

Minesweeper::Minesweeper(int width, int height, int mines) {
    rader       = height;
    kolonner    = width;
    miner       = mines;
    tileset     = new Tile*[kolonner];

    for(int i=0; i<kolonner; i++) {
        tileset[i] = new Tile[rader];
    }

}

Minesweeper::~Minesweeper() {
    delete tileset; //Mop-up
}

bool Minesweeper::isGameOver() const {
    return false;
}

bool Minesweeper::isTileOpen(int row, int col) const {
    return tileset[col][row].open;
}

bool Minesweeper::isTileMine(int row, int col) const {
    return tileset[col][row].mine;
    return false;
}

void Minesweeper::openTile(int row, int col) {
    tileset[col][row].open = true;
}

int Minesweeper::numAdjacentMines(int row, int col) const {
    return 0;
}
