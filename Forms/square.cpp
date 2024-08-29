#include "..\Headers\square.h"
#include "..\Headers\form.h"
#include "..\Headers\piece.h"
#include <iostream>
using namespace std;

Square::Square(int x, Form *form){
    while (x > MAX_COLUMN)
    {
        x--;
    }
    piecesSquare.Add(new Piece(0 + x, -1, form));//x y
    piecesSquare.Add(new Piece(1 + x, -1, form));
    piecesSquare.Add(new Piece(0 + x, 0, form));
    piecesSquare.Add(new Piece(1 + x, 0, form));
};

Square::Square(int x, int y, Form *form){
    piecesSquare.Add(new Piece(x, y, form));//x y
    piecesSquare.Add(new Piece(1 + x, y, form));
    piecesSquare.Add(new Piece(x, 1 + y, form));
    piecesSquare.Add(new Piece(1 + x, 1 + y, form));
};

void Square::ToString(){
    for (int i = 0; i < piecesSquare.length; i++)
    {
        piecesSquare.Get(i)->ToString();
    }
    
}