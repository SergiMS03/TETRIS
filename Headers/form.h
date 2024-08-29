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

    void setForm();

    void PieceMove(int PiecePosition);
    void PieceFall();
    // Método para establecer el estado nulo
    void setNull();
};