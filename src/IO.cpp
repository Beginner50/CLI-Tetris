#include "IO.h"

template <typename T>
std::string IO::SerialiseArray(T* arrPtr, int arrSize)
{
    std::string rs{};
    for (int i{}; i < arrSize; ++i)
        if (arrPtr[i] != 0)
            rs.push_back('#');
        else
            rs.push_back(' ');
    return rs;
}

std::string IO::SerialiseCharacterSequence(char character, int iterations)
{
    std::string rs{};
    for (int i{}; i < iterations; ++i)
        rs.push_back(character);
    return rs;
}

std::string IO::SerialiseCharacterSequence(const std::string& character, int iterations)
{
    std::string rs{};
    for (int i{}; i < iterations; ++i)
        rs += character;
    return rs;
}

void IO::PrintBoard(Board board, int pType, int pRotation, int pX, int pY)
{
    board.StorePiece(pType, pRotation, pX, pY);

    for (int row{}; row < BOARD_LENGTH; ++row)
        std::cout << SerialiseCharacterSequence(' ', BOARD_WIDTH)
        << "■" << SerialiseArray(board.GetRow(row), BOARD_WIDTH) << "■ \n";
    std::cout << SerialiseCharacterSequence(' ', BOARD_WIDTH)
        << SerialiseCharacterSequence("■", BOARD_WIDTH + 2) << '\n';
}