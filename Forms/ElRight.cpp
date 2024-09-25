#include "..\Headers\elRight.h"
#include "..\Headers\form.h"
#include "..\Headers\piece.h"
#include <iostream>
using namespace std;

ElRight::ElRight(int x, Form *form){
    while (x > MAX_COLUMN)
    {
        x--;
    }
    piecesElRight.Add(new Piece(x, -2, form));//x y
    piecesElRight.Add(new Piece(x, -1, form, true));
    piecesElRight.Add(new Piece(x, 0, form));
    piecesElRight.Add(new Piece(1 + x, 0, form));
};

ElRight::ElRight(int x, int y, Form *form){
    piecesElRight.Add(new Piece(x, y, form));//x y
    piecesElRight.Add(new Piece(x, 1 + y, form, true));
    piecesElRight.Add(new Piece(x, 2 + y, form));
    piecesElRight.Add(new Piece(1 + x, 2 + y, form));
};

void ElRight::ChangeOrientation(){
    orientation++;
    if(orientation > 3){
        orientation = 0;
    }
    switch (orientation)
    {
    case 0:
        /* code */
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    }
}

void ElRight::ToString(){
    for (int i = 0; i < piecesElRight.length; i++)
    {
        piecesElRight.Get(i)->ToString();
    }
    
}