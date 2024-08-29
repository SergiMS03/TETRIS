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

    Piece(Vectors2D *vec, Form *form);
    Piece(int x, int y, Form *form);
    Piece();

    ~Piece();

    void ToString();
};


