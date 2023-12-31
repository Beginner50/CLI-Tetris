#include "board.h"

Board::Board(Pieces* pieces)
{
    m_pieces = pieces;
    InitBoard();
}

Board::Board(Board& board)
{
    this->m_pieces = board.m_pieces;

    for (int bX{}; bX < BOARD_LENGTH; ++bX)
        for (int bY{}; bY < BOARD_WIDTH; ++bY)
            this->m_board[bX][bY] = board.m_board[bX][bY];
}

Board::~Board() {}

void Board::InitBoard()
{
    for (int bX{}; bX < BOARD_LENGTH; ++bX)
        for (int bY{}; bY < BOARD_WIDTH; ++bY)
            m_board[bX][bY] = CELL_EMPTY;
}

int* Board::GetRow(int bX)
{
    return m_board[bX];
}

bool Board::IsEmptyCell(int bX, int bY)
{
    return m_board[bX][bY] == 0 ? true : false;
}

int Board::GetCellType(int bX, int bY)
{
    return m_board[bX][bY];
}

void Board::StorePiece(int pType, int pRotation, int bX, int bY)
{
    for (int i1{ bX }, i2{}; i1 < bX + PIECE_SIZE; ++i1, ++i2)
        for (int j1{ bY }, j2{}; j1 < bY + PIECE_SIZE; ++j1, ++j2)
        {
            // Skip empty blocks
            if (m_pieces->GetCellType(pType, pRotation, i2, j2) != 0 && i1 >= 0)
                m_board[i1][j1] = CELL_FILLED;
        }
}

bool Board::IsPossibleMovement(int pType, int pRotation, int bX, int bY)
{
    for (int i1{ bX }, i2{}; i1 < bX + PIECE_SIZE; ++i1, ++i2)
        for (int j1{ bY }, j2{}; j1 < bY + PIECE_SIZE; ++j1, ++j2)
        {
            // Checks for filled blocks outside matrix
            if ((i1 > BOARD_LENGTH - 1 || (j1 < 0 || j1 > BOARD_WIDTH - 1))
                && m_pieces->GetCellType(pType, pRotation, i2, j2) != 0)
                return false;
            if (i1 >= 0)
                if (!IsEmptyCell(i1, j1) && m_pieces->GetCellType(pType, pRotation, i2, j2) != 0)
                    return false;
        }
    return true;
}

void Board::DeleteLine(int BX)
{
    for (int bY{ }; bY < BOARD_WIDTH; ++bY)
        for (int bX{ BX - 1 }; bX > 0; --bX)
            m_board[bX + 1][bY] = m_board[bX][bY];
}

void Board::DeletePossibleLines()
{
    bool isPrevBlockEmpty{ true };

    for (int bX{ BOARD_LENGTH - 1 }; bX > 0; --bX)
    {
        for (int bY{}; bY < BOARD_WIDTH; ++bY)
        {
            if (isPrevBlockEmpty && !IsEmptyCell(bX, bY))
                isPrevBlockEmpty = false;
            else if (!isPrevBlockEmpty && IsEmptyCell(bX, bY))
            {
                isPrevBlockEmpty = true;
                bY = BOARD_WIDTH;
            }
            if (bY == BOARD_WIDTH - 1 && !IsEmptyCell(bX, bY))
            {
                DeleteLine(bX);
                ++bX;
            }
        }
        if (isPrevBlockEmpty)
            break;
    }
}


bool Board::IsGameOver()
{
    for (int j{}; j < BOARD_WIDTH; ++j)
        if (!IsEmptyCell(0, j))
            return true;
    return false;
}
