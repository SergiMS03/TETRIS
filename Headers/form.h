#pragma once
#include "doubleLinkedList.h"
#include "vectors2d.h"
#include "..\Headers\random.h"

class Form{       
    public:             
    bool isNull;
    int color;
    List<Vectors2D> pieces;
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