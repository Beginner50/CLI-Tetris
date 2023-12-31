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

        char key{};
        std::cin >> key;

        if (!std::cin)
        {
            std::cin.ignore('\n', 10000);
            std::cin.clear();
        }

        game.TranslateActionToPieceMovement(key);
        if (board.IsGameOver())
            break;
    }

    system("clear");
    std::cout << "=======================\n"
        << "       GAME OVER       \n"
        << "=======================\n";
    std::cout << "   Tetris By Prashant\n";
    return 0;
}