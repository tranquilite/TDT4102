#pragma once
#include<iostream>


struct Tile {
    //en rute er alltid lukket og ~mine, mm. annet er sagt.
    bool open       =   false;
    bool mine       =   false;
    bool flagged    =   false;
    int numAdjMines =   0;
};

class Minesweeper {
private:
    // Legg til de medlemsvariablene og hjelpefunksjonene du trenger
    int rader, kolonner, miner, aapne = 0;
    Tile** tileset = nullptr;
    bool gameOver;

    void populateTilesetWithMines();
    void buildAdjacencyIndex(int row, int col);

public:
    //              kolonner     rader    miner
    Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;

    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;

    void openTile(int row, int col);
    int numAdjacentMines(int row, int col) const;

    void modeDebug();

    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};

/*const std::ostream& operator<<(std::ostream& stream, const Tile& T_) {
    stream << T_.open;
    return stream;
}*/
