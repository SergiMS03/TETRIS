#pragma once
#include "form.h"
#include "piece.h"
#include "doubleLinkedList.h"



class ElRight{
    public:
    const string NAME = "ElRight";
    const int MAX_COLUMN = 8;
    int orientation = 0;
    List<Piece*> piecesElRight;
    
    ElRight(int x, Form *form);

    ElRight(int x, int y, Form *form);

    void ChangeOrientation();

    void ToString();

};