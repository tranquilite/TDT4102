#include<iostream>

#include "minesweeper.h"

Minesweeper::Minesweeper(int width, int height, int mines) {
    rader       = height;
    kolonner    = width;
    miner       = mines;
    gameOver    = false;
    tileset     = new Tile*[kolonner];

    for(int i=0; i<kolonner; i++) {
        tileset[i] = new Tile[rader];
    }
    populateTilesetWithMines();
}

Minesweeper::~Minesweeper() {
    delete tileset; //Mop-up
}

bool Minesweeper::isGameOver() const {
    return gameOver;
    //return false;
}

bool Minesweeper::isTileOpen(int row, int col) const {
    return tileset[col][row].open;
}

bool Minesweeper::isTileMine(int row, int col) const {
    return tileset[col][row].mine;
    return false;
}

void Minesweeper::openTile(int row, int col) {
    if(tileset[col][row].mine == true) {
        gameOver = true;
    }
    tileset[col][row].open = true;
}

int Minesweeper::numAdjacentMines(int row, int col) const {
    if(tileset[col][row].mine == true) { return 0; }


    return 0;
}

void Minesweeper::populateTilesetWithMines() {
    // FIX MEG
    int _rad = 0, _kol = 0;
    bool radFlag = false, colFlag = false;
    int _radBrukt[this->miner], _kolBrukt[this->miner];
    int placedMines = 1;

    while (placedMines <= this->miner) {
        _rad = rand() % rader;
        _kol = rand() % kolonner;

        for(int i = 0; i < this->miner; i++) {
            if( (_radBrukt[i] == _rad) and (_kolBrukt[i] == _kol) ) {
                radFlag = false, colFlag = false;
                _radBrukt[i] = _rad, _kolBrukt[i] = _kol;
            }

            /*
            if(_radBrukt[i] == _rad) { radFlag = false; }
            if(_kolBrukt[i] == _kol) { colFlag = false; }
            if (radFlag and colFlag) {
                _radBrukt[i] = _rad;
                _kolBrukt[i] = _kol;
            } */
        }

        if(radFlag and colFlag and not tileset[_kol][_rad].mine) {
            tileset[_kol][_rad].mine = true;
            std::cout   << "\tPlaced mine at: " << _kol << ", " << _rad
                        << ", counting " << placedMines << "/" << miner << std::endl;
            placedMines++;
        }
        radFlag = true;
        colFlag = true;
    }
}

void Minesweeper::modeDebug() {
    for(int e = 0; e < rader; ++e) {
        for(int i=0; i<kolonner; ++i) {
            tileset[i][e].open = true;
        }
    }
}
