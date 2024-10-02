#pragma once
#include "form.h"
#include "piece.h"
#include "doubleLinkedList.h"

using namespace std;

class Square : public Form{
    public:
    const string NAME = "square";
    const int MAX_COLUMN = 8;
    
    
    Square(int x) : Form(){
        while (x > MAX_COLUMN)
        {
            x--;
        }
        formName = NAME;
        pieces.Add(new Piece(0 + x, -1, this));
        pieces.Add(new Piece(1 + x, -1, this));
        pieces.Add(new Piece(0 + x, 0, this));
        pieces.Add(new Piece(1 + x, 0, this));
    };

    Square(int x, int y) : Form(){
        formName = NAME;
        pieces.Add(new Piece(x, y, this));
        pieces.Add(new Piece(1 + x, y, this));
        pieces.Add(new Piece(x, 1 + y, this));
        pieces.Add(new Piece(1 + x, 1 + y, this));
    };

    void RotateForm() override{}

    void ToString();

};