#pragma once
#include "vectors2d.h"
#include "..\Headers\form.h"
using namespace std;

class Form;//Dependencia circular

class Piece
{
public:
    Vectors2D *vector2d;
    Piece *me = this;
    Form *form;
    bool mainPiece;

    Piece(Vectors2D *vec, Form *form, bool mainPiece = false);
    Piece(int x, int y, Form *form, bool mainPiece = false);
    Piece();

    ~Piece();

    void ToString();
};


