#pragma once
#include "form.h"
#include "piece.h"
#include "doubleLinkedList.h"



class Square{
    public:
    const string NAME = "square";
    const int MAX_COLUMN = 8;
    List<Piece*> piecesSquare;
    
    Square(int x, Form *form);

    Square(int x, int y, Form *form);

    void ToString();

};