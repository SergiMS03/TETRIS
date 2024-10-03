#pragma once
#include "form.h"
#include "piece.h"
#include "doubleLinkedList.h"



class Line : public Form{
    public:
    const string NAME = "Line";
    
Line(int x) : Form(){
    color = 11;
    pieces.Add(new Piece(x, -3, this));
    pieces.Add(new Piece(x, -2, this, true));
    pieces.Add(new Piece(x, -1, this));
    pieces.Add(new Piece(x, 0, this));
};

Line(int x, int y): Form(){
    pieces.Add(new Piece(x, y - 1, this));
    pieces.Add(new Piece(x, y, this, true));
    pieces.Add(new Piece(x, y + 1, this));
    pieces.Add(new Piece(x, y + 2, this));
};

void RotateForm() override{
    orientation++;
    if(orientation > 3){
        orientation = 0;
    }
    
    Piece *mainPiece = pieces.Get(1);  
    switch (orientation)
    {
    case 0:
        mainPiece->vector2d->y--;
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 1);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 1);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 2);
        break;
    case 1:
        mainPiece->vector2d->x++;
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x - 2, mainPiece->vector2d->y);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y);
        break;
    case 2:
        mainPiece->vector2d->y++;
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 2);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 1);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 1);
        break;
    case 3:
        mainPiece->vector2d->x--;
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x + 2, mainPiece->vector2d->y);
        break;
    }
}

    void ToString();

};