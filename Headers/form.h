#pragma once
#include "doubleLinkedList.h"
#include "vectors2d.h"
#include "piece.h"
#include "..\Headers\random.h"


class Piece;//Dependencia circular

class Form{       
    public:             
    bool isNull;
    int color;
    List<Piece*> pieces;
    string formName;

    virtual ~Form() {}

    // Constructor predeterminado que establece el estado nulo
    Form();

    Form(int x, int y);

    void setForm();
    void setForm(int x, int y);

    void PieceMove(int PiecePosition);
    void PieceFall();
    // Método para establecer el estado nulo
    void setNull();
};