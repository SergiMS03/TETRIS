#include <iostream>
#include "..\Headers\piece.h"
#include "..\Headers\form.h"
#include "..\Headers\vectors2d.h"

using namespace std;

Piece::Piece(Vectors2D *vec, Form *form)
{
    this->vector2d = vec;
    this->me = this;
    this->form = form;
}

Piece::Piece(int x, int y, Form *form)
{
    this->vector2d = new Vectors2D(x, y);
    this->me = this;
    this->form = form;
}

Piece::Piece(){

}

Piece::~Piece()
{
    delete vector2d;
    vector2d = nullptr;
    me = nullptr;
    form = nullptr;
}

void Piece::ToString(){
    cout << "This "<< me << "\nVector2D:\n\tx: "<< vector2d->x <<"\n\ty: " << vector2d->y <<"\nForm: " << form << "\n";
};


