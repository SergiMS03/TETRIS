#pragma once
#include "form.h"
#include "piece.h"
#include "doubleLinkedList.h"



class Ti : public Form{
    public:
    const string NAME = "Ti";
    const int MAX_COLUMN = 7;
    
Ti(int x) : Form(){
    color = 13;
    while (x > MAX_COLUMN)
    {
        x--;
    }
    pieces.Add(new Piece(x, -1, this));
    pieces.Add(new Piece(x + 1, -1, this, true));
    pieces.Add(new Piece(x + 2, -1, this));
    pieces.Add(new Piece(x + 1, 0, this));
};

Ti(int x, int y): Form(){
    pieces.Add(new Piece(x, y, this));
    pieces.Add(new Piece(x + 1, y, this, true));
    pieces.Add(new Piece(x + 2, y, this));
    pieces.Add(new Piece(x + 1, y + 1, this));
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
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 1);
        break;
    case 1:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 1);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 1);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y);
        break;
    case 2:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x + 1, mainPiece->vector2d->y);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 1);
        break;
    case 3:
        pieces.Get(0)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y + 1);
        pieces.Get(2)->vector2d->SetCoords(mainPiece->vector2d->x, mainPiece->vector2d->y - 1);
        pieces.Get(3)->vector2d->SetCoords(mainPiece->vector2d->x - 1, mainPiece->vector2d->y);
        break;
    }
}

};