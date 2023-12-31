#pragma once
#include "board.h"
#include <iostream>

namespace IO {
    template <typename T>
    std::string SerialiseArray(T* arrPtr, int arrSize);

    std::string SerialiseCharacterSequence(char character, int iterations);

    std::string SerialiseCharacterSequence(const std::string& character, int iterations);

    void PrintBoard(Board board, int pType, int pRotation, int pX, int pY);
}