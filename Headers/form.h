#pragma once
#include "doubleLinkedList.h"
#include "vectors2d.h"
#include "..\Headers\random.h"

class Form{       
    public:             
    bool isNull;
    List<Vectors2D> pieces;
    string formName;

    virtual ~Form() {}

    // Constructor predeterminado que establece el estado nulo
    Form();

    void setForm();

    void PieceFall(int PiecePosition);
    // Método para establecer el estado nulo
    void setNull();
};