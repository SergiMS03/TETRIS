#include <iostream>
#include "..\Headers\form.h"
#include "..\Headers\table.h"
#include "..\Headers\random.h"
#include "..\Headers\square.h"
#include "..\Headers\elRight.h"
#include "..\Headers\vectors2d.h"
#include "..\Headers\piece.h"
#include "..\Headers\console.h"
using namespace std;


Form::Form(){
    isNull = false;
    //this->setForm();
}

Form::Form(int x, int y){
    isNull = false;
    //this->setForm(x, y);
}

void Form::setForm(){
    
    //int form = 1;
    Random *rand = new Random();
    color = rand->RandomIntBtw(CmdColors::MIN_COLOR_VALUE, CmdColors::MAX_COLOR_VALUE);
    //int xPosition = rand->RandomIntBtw(0, TABLE_WIDTH - 1);
    //int xPosition = 0;
    /* switch (form)
    {
        case 1:{
            Square* sqr = new Square(xPosition, this);
            pieces = sqr->piecesSquare;
            formName = sqr->NAME;
            break;
            }
        case 2:{
            ElRight* LRight = new ElRight(xPosition, this);
            pieces = LRight->piecesElRight;
            formName = LRight->NAME;
            break;
        }
    } */
    delete rand;
}

void Form::setForm(int x, int y){
    
    //int form = 1;
    Random *rand = new Random();
    color = rand->RandomIntBtw(CmdColors::MIN_COLOR_VALUE, CmdColors::MAX_COLOR_VALUE);
    /* switch (form)
    {
    case 1:
        Square* sqr = new Square(x, y, this);
        pieces = sqr->piecesSquare;
        formName = sqr->NAME;
        break;
    } */
    delete rand;
}

void Form::MovePieces(int mov){
    for (int i = 0; i < this->pieces.length; i++)
    {
        Piece* piece = this->pieces.Get(i);
        piece->vector2d->x += mov;
    }
}

void Form::FallPieces(){
    for (int i = 0; i < this->pieces.length; i++)
    {
        Piece* piece = this->pieces.Get(i);
        piece->vector2d->y++;
    }
}

// Método para establecer el estado nulo
void Form::setNull(){
    isNull = true;
}

void Form::ToString(){
    for (int i = 0; i < pieces.length; i++)
    {
        pieces.Get(i)->ToString();
    }
}

void Form::UndoSpin(){
    orientation--;
}

void Form::RotateForm() {
    // Implementación de la rotación
}
