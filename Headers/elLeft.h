#pragma once
#include "form.h"
#include "piece.h"
#include "doubleLinkedList.h"



class ElLeft : public Form{
    public:
    const string NAME = "ElLeft";
    
ElLeft(int x) : Form(){
    color = 9;
    pieces.Add(new Piece(x, -2, this));
    pieces.Add(new Piece(x, -1, this, true));
    pieces.Add(new Piece(x, 0, this));
    pieces.Add(new Piece(x - 1, 0, this));
};

ElLeft(int x, int y): Form(){
    color = 9;
    pieces.Add(new Piece(x, y - 2, this));
    pieces.Add(new Piece(x, y - 1, this, true));
    pieces.Add(new Piece(x, y, this));
    pieces.Add(new Piece(1 - x, y, this));
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
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 1);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 1);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y + 1);
        break;
    case 1:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y + 1);
        break;
    case 2:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 1);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 1);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y - 1);
        break;
    case 3:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y - 1);
        break;
    }
}

};