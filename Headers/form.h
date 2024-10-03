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
    int orientation;
    List<Piece*> pieces;
    string formName;

    virtual ~Form() {}

    // Constructor predeterminado que establece el estado nulo
    Form();

    Form(int x, int y);

    void setForm();
    void setForm(int x, int y);

    void MovePieces(int PiecePosition);
    void FallPieces();
    virtual void RotateForm();
    void UndoSpin();
    // Método para establecer el estado nulo
    void setNull();
    void ToString();
};