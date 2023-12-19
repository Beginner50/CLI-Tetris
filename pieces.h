#pragma once

/*
=================
Pieces class is meant to be a reference to all combinations of pieces and their rotations,
facilitating the selection of a specific piece by another object
=================
*/
constexpr int PIECE_SIZE{ 5 };

class Pieces
{
public:
    int GetXPieceInitial(int pType, int pRotation);
    int GetYPieceInitial(int pType, int pRotation);

    int GetCellType(int pType, int pRotation, int pX, int pY);
};