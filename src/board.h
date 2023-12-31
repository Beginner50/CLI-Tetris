#pragma once
#include "pieces.h"

constexpr int BOARD_WIDTH{ 20 };
constexpr int BOARD_LENGTH{ 10 };

class Board
{
public:
    Board(Pieces* pieces);
    Board(Board& board);
    ~Board();

    void InitBoard();
    int* GetRow(int bX);

    bool IsEmptyCell(int bX, int bY);
    int GetCellType(int bX, int bY);

    void StorePiece(int pType, int pRotation, int bX, int bY);
    bool IsPossibleMovement(int pType, int pRotation, int bX, int bY);

    void DeletePossibleLines();
    void DeleteLine(int bX);

    bool IsGameOver();

    enum { CELL_EMPTY, CELL_FILLED };
    int m_board[BOARD_LENGTH][BOARD_WIDTH];
private:
    Pieces* m_pieces{ nullptr };

    Board& operator=(Board& board);
};