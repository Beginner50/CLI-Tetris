#include "board.h"
#include <iostream>

Board::Board(Pieces* pieces)
{
    m_pieces = pieces;

    m_pType = 1;
    m_pRotation = 3;

    m_pX = m_pieces->GetXPieceInitial(m_pType, m_pRotation);
    m_pY = (BOARD_WIDTH / 2) + m_pieces->GetYPieceInitial(m_pType, m_pRotation);

    InitBoard();
}

Board::Board(Board& board)
{
    this->m_pieces = board.m_pieces;

    this->m_pX = board.m_pX;
    this->m_pY = board.m_pY;

    this->m_pType = board.m_pType;
    this->m_pRotation = board.m_pRotation;

    this->m_pTypeNext = board.m_pTypeNext;
    this->m_pRotationNext = board.m_pRotationNext;

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