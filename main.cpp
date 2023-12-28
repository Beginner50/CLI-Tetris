#include "game.h"
#include "IO.h"

int main()
{
    Pieces pieces{};
    Board board{ &pieces };
    Game game{ &board, &pieces };

    while (true)
    {
        system("clear");
        IO::PrintBoard(board, game.m_pType, game.m_pRotation, game.m_pX, game.m_pY);

        char in{};
        std::cin >> in;

        if (!std::cin)
        {
            std::cin.ignore('\n', 10000);
            std::cin.clear();
        }

        switch (in)
        {
        case 'a':
            if (board.IsPossibleMovement(game.m_pType, game.m_pRotation, game.m_pX, game.m_pY - 1))
                --game.m_pY;
            break;
        case 'd':
            if (board.IsPossibleMovement(game.m_pType, game.m_pRotation, game.m_pX, game.m_pY + 1))
                ++game.m_pY;
            break;
        case 's':
            if (board.IsPossibleMovement(game.m_pType, game.m_pRotation, game.m_pX + 1, game.m_pY))
                ++game.m_pX;
            else
            {
                board.StorePiece(game.m_pType, game.m_pRotation, game.m_pX, game.m_pY);
                board.DeletePossibleLines();
                game.GetNewPiece();
            }
            break;
        case 'x':
            while (board.IsPossibleMovement(game.m_pType, game.m_pRotation, game.m_pX + 1, game.m_pY))
                ++game.m_pX;
            board.StorePiece(game.m_pType, game.m_pRotation, game.m_pX, game.m_pY);
            board.DeletePossibleLines();
            game.GetNewPiece();
            break;
        case 'n':
            if (board.IsPossibleMovement(game.m_pType, game.m_pRotation + 1, game.m_pX, game.m_pY))
            {
                if (game.m_pRotation == 3)
                    game.m_pRotation = 0;
                else
                    ++game.m_pRotation;
            }
            break;
        default:
            break;
        }
    }

    std::cout << "Tetris By Prashant\n";
    return 0;
}