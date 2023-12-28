#include "game.h"

Game::Game(Board* board, Pieces* pieces)
    : m_board{ board }, m_pieces{ pieces }
{
    InitGame();
}

Game::~Game() {}

void Game::InitGame()
{
    // Randomising current piece
    m_pType = rand7(mt);
    m_pRotation = rand4(mt);

    m_pX = m_pieces->GetXPieceInitial(m_pType, m_pRotation);
    m_pY = (BOARD_WIDTH / 2) + m_pieces->GetYPieceInitial(m_pType, m_pRotation);

    // Randomising next piece
    m_pTypeNext = rand7(mt);
    m_pRotationNext = rand4(mt);
}

void Game::GetNewPiece()
{
    // Get new current piece
    m_pType = m_pTypeNext;
    m_pRotation = m_pRotationNext;

    m_pX = m_pieces->GetXPieceInitial(m_pType, m_pRotation);
    m_pY = (BOARD_WIDTH / 2) + m_pieces->GetYPieceInitial(m_pType, m_pRotation);

    // Randomise new piece
    m_pTypeNext = rand7(mt);
    m_pRotationNext = rand4(mt);
}