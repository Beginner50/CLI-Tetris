#include "board.h"
#include <iostream>

namespace IO
{
    template <typename T>
    std::string SerialiseArray(T* arrPtr, int arrSize)
    {
        std::string rs{};
        for (int i{}; i < arrSize; ++i)
            if (arrPtr[i] != 0)
                rs.push_back('#');
            else
                rs.push_back(' ');
        return rs;
    }

    std::string SerialiseCharacterSequence(char character, int iterations)
    {
        std::string rs{};
        for (int i{}; i < iterations; ++i)
            rs.push_back(character);
        return rs;
    }

    std::string SerialiseCharacterSequence(const std::string& character, int iterations)
    {
        std::string rs{};
        for (int i{}; i < iterations; ++i)
            rs += character;
        return rs;
    }

    void PrintBoard(Board board)
    {
        board.StorePiece(board.m_pType, board.m_pRotation, board.m_pX, board.m_pY);

        for (int row{}; row < BOARD_LENGTH; ++row)
            std::cout << SerialiseCharacterSequence(' ', BOARD_WIDTH)
            << "■" << SerialiseArray(board.GetRow(row), BOARD_WIDTH) << "■ \n";
        std::cout << SerialiseCharacterSequence(' ', BOARD_WIDTH)
            << SerialiseCharacterSequence("■", BOARD_WIDTH + 2) << '\n';
    }
}


int main()
{
    Pieces pieces{};
    Board board{ &pieces };

    board.StorePiece(board.m_pType, board.m_pRotation, 8, board.m_pY);
    while (board.IsPossibleMovement(board.m_pType, board.m_pRotation, board.m_pX, board.m_pY))
    {
        IO::PrintBoard(board);
        ++board.m_pX;
    }

    return 0;
}