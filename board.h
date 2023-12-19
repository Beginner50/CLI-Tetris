#pragma once
#include "pieces.h"

constexpr int BOARD_WIDTH{ 20 };
constexpr int BOARD_LENGTH{ 10 };

class Board
{
public:
    Board(Pieces* pieces);
    Board(Board& board);
    Board& operator=(Board& board) = delete;
    ~Board();

    void InitBoard();
    int* GetRow(int bX);

    bool IsEmptyCell(int bX, int bY);
    int GetCellType(int bX, int bY);

    void StorePiece(int pType, int pRotation, int bX, int bY);
    bool IsPossibleMovement(int pType, int pRotation, int bX, int bY);

    // Position of Piece on board
    int m_pX{ };
    int m_pY{ };

    // Current and Next Pieces
    int m_pType{};
    int m_pRotation{};

    int m_pTypeNext{};
    int m_pRotationNext{};
private:
    enum { CELL_EMPTY, CELL_FILLED };
    int m_board[BOARD_LENGTH][BOARD_WIDTH];
    Pieces* m_pieces{ nullptr };
};