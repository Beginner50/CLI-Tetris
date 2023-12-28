#pragma once
#include <random>
#include "board.h"

/*
    The game class is meant to serve as the link between the board and the current
    and next pieces. To clear any confusion, the Pieces class is meant for lookup only
    and hence is stored by both Game and Board.

    The actual pieces are represented by indexes instead.
*/
class Game
{
public:
    Game(Board* board, Pieces* pieces);
    ~Game();

    void GetNewPiece();

    int m_pType{};
    int m_pRotation{};

    int m_pTypeNext{};
    int m_pRotationNext{};

    int m_pX{};
    int m_pY{};
private:
    void InitGame();

    Board* m_board{};
    Pieces* m_pieces{};

    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<> rand7{ 0,6 };
    std::uniform_int_distribution<> rand4{ 0,3 };

    Game(const Game& game);
    Game& operator=(const Game& game);
};