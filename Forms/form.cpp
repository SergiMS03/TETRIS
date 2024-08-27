#include <iostream>
#include "..\Headers\form.h"
#include "..\Headers\table.h"
#include "..\Headers\random.h"
#include "..\Headers\square.h"
#include "..\Headers\vectors2d.h"
#include "..\Headers\console.h"
using namespace std;


Form::Form(){
    isNull = false;
    this->setForm();
}

void Form::setForm(){
    
    int form = 1;
    Random *rand = new Random();
    color = rand->RandomIntBtw(CmdColors::MIN_COLOR_VALUE, CmdColors::MAX_COLOR_VALUE);
    int xPosition = rand->RandomIntBtw(0, TABLE_WIDTH - 1);
    //int xPosition = 0;
    switch (form)
    {
    case 1:
        Square* sqr = new Square(xPosition);
        pieces = sqr->vectsSqr;
        formName = sqr->NAME;
        break;
    }
    delete rand;
}

void Form::PieceMove(int mov){
    for (int i = 0; i < this->pieces.length; i++)
    {
        Vectors2D* piece = this->pieces.GetMem(i);
        piece->x += mov;
    }
}

void Form::PieceFall(){
    for (int i = 0; i < this->pieces.length; i++)
    {
        Vectors2D* piece = this->pieces.GetMem(i);
        piece->y++;
    }
}

// Método para establecer el estado nulo
void Form::setNull(){
    isNull = true;
}

