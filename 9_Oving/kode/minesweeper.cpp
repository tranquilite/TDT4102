#include<iostream>

#include "minesweeper.h"

bool __debug = false;

Minesweeper::Minesweeper(int width, int height, int mines) {
    rader       = height;
    kolonner    = width;
    miner       = mines;
    aapne       = 0;
    gameOver    = false;
    tileset     = new Tile*[kolonner];
    //Dette er så uttrolig tiltak.
    //Skriv om til å gi en rute en indeks i rommet [0, (rader*kolonner)]
    //type, Imax = rader*kolonner, I = rad*kolonner + kolonne
    for(int i=0; i<kolonner; i++) {
        tileset[i] = new Tile[rader];
    }

    populateTilesetWithMines();
    for(int r=0; r < rader; ++r) {
        for(int k=0; k < kolonner; ++k) {
            buildAdjacencyIndex(r, k);
        }
    }
    if(__debug == true) {
        for(int e = 0; e < rader; ++e) {
            for(int i=0; i<kolonner; ++i) {
                tileset[i][e].open = true;
            }
        }
    }
}

Minesweeper::~Minesweeper() {
    delete tileset; //Mop-up
}

bool Minesweeper::isGameOver() const { return gameOver; }

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
    ++aapne;
    tileset[col][row].open = true;
}

int Minesweeper::numAdjacentMines(int row, int col) const {
    return tileset[col][row].numAdjMines;
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
        }

        if(radFlag and colFlag and not tileset[_kol][_rad].mine) {
            tileset[_kol][_rad].mine = true;
            placedMines++;
        }

        radFlag = true;
        colFlag = true;
    }
}

void Minesweeper::buildAdjacencyIndex(int row, int col) {
    //Gyldige offsets. Med klokka fra midnatt.
    int _kol[8] = { 0,  1, 1, 1, 0, -1, -1, -1};
    int _rad[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
    int e = 0;
    for(int i=0; i < 8; ++i) {
        int x1 = (col+_kol[i]);// x2 = (col-_kol[i]);
        int y1 = (row+_rad[i]);// y2 = (row-_rad[i]);
        if( (y1 >= 0) && (y1 < rader) &&
            (x1 >= 0) && (x1 < kolonner) ) {
            e += isTileMine((row+_rad[i]),(col+_kol[i]));
            //                  0           5
        }
    }

    tileset[row][col].numAdjMines = e;
}

void Minesweeper::modeDebug() {
    //flip the switch
    if(__debug == false) {
        __debug = true;
    } else {
        __debug = false;
    }

    for(int e = 0; e < rader; ++e) {
        for(int i=0; i<kolonner; ++i) {
            tileset[i][e].open = true;
        }
    }
}
