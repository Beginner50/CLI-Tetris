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

void Game::TranslateActionToPieceMovement(char key)
{
    bool pieceLanded{ false };

    switch (key)
    {
    case KEY_LEFT:
        if (m_board->IsPossibleMovement(m_pType, m_pRotation, m_pX, m_pY - 1))
            --m_pY;
        break;
    case KEY_RIGHT:
        if (m_board->IsPossibleMovement(m_pType, m_pRotation, m_pX, m_pY + 1))
            ++m_pY;
        break;
    case KEY_DOWN:
        if (m_board->IsPossibleMovement(m_pType, m_pRotation, m_pX + 1, m_pY))
            ++m_pX;
        else
            pieceLanded = true;
        break;
    case KEY_NEXT_ROTATION:
        if (m_board->IsPossibleMovement(m_pType, m_pRotation + 1 > 3 ? 0 : m_pRotation + 1, m_pX, m_pY))
        {
            if (m_pRotation == 3)
                m_pRotation = 0;
            else
                ++m_pRotation;
        }
        break;
    case KEY_DROP_PIECE:
        while (m_board->IsPossibleMovement(m_pType, m_pRotation, m_pX + 1, m_pY))
            ++m_pX;
        pieceLanded = true;
        break;
    default:
        break;
    }

    if (pieceLanded)
    {
        m_board->StorePiece(m_pType, m_pRotation, m_pX, m_pY);
        m_board->DeletePossibleLines();
        GetNewPiece();
    }
}