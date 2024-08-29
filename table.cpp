#include <iostream>
#include "Headers\table.h"
#include "Headers\doubleLinkedList.h"
#include "Headers\form.h"
#include "Headers\console.h"
using namespace std;

Table::Table(){
    RebootTable();
}

void Table::CheckForLine(){
    ptr_table = tableStart;
    int y = 0;
    while (y < TABLE_HEIGHT)
    {
        bool line = true; 
        for (int x = 0; x < TABLE_WIDTH && line; x++)
        {
             Piece* piece = *(ptr_table + x);
            if(piece != nullptr){
                line = false;
            }
        }
        if(line){
            for (int x = 0; x < TABLE_WIDTH && line; x++)
            {
                /*Implementar en DLL borrar por posicion de memoria, y usarlo para eliminar las piezas de la fila. 
                Después tendremos que bajar las piezas de las filas superiores*/
            }
        }
    }
    
    
}

void Table::RenderTable(){
    
    ptr_table = tableStart;
    for (int i = 0; i < TABLE_HEIGHT; i++)
    {
        for (int j = 0; j < TABLE_WIDTH; j++)
        {
            
            if(*ptr_table != nullptr){
                Piece *piece = *ptr_table;
                Console::TextColor(piece->form->color);
                cout << "@ ";
                Console::TextColor(CmdColors::light_grey);
            }
            else{
                cout << "o ";
            }
            ptr_table++;
        }
        cout << "\n";
    }
}

void Table::RebootTable(){
    
    ptr_table = tableStart;
    for (int i = 0; i < TABLE_HEIGHT * TABLE_WIDTH; i++)
    {
        *ptr_table = nullptr;
        ptr_table++;
    }
}

bool Table::QuickCalc(List<Form*> *forms, Form *fallingForm, char direction){    
    //Carga las piezas en la tabla 
    for (int i = 0; i < forms->length; i++)
    {
        Form *form = forms->Get(i);
        for (int j = 0; j < form->pieces.length; j++)
        {
            ptr_table = tableStart;
            Piece *piece = form->pieces.Get(j);
            int position = CoordsToPosition(piece->vector2d->x, piece->vector2d->y);
            ptr_table = ptr_table + position; 
            *ptr_table = piece;
        }
    }
    
    bool canFall = ColisionCalc(fallingForm, direction);

    FallingFormCalc(fallingForm);
    
    return canFall;
}

bool Table::ColisionCalc(Form *fallingForm, char direction){
    ptr_table = tableStart;
    const int ROW_LENGTH = TABLE_WIDTH;
    bool canFall = true;
    bool canMove = true;

    int rowOperator = 0;
    if(direction == 'L'){
        rowOperator = MOVE_LEFT;
        
    }
    else if(direction == 'R'){
        rowOperator = MOVE_RIGHT;
        
    }

    //Comprueba si la pieza puede moverse
    if (rowOperator == 0) canMove = false;
    for (int i = 0; i < fallingForm->pieces.length && canMove; i++)
    {
        Piece *piece = fallingForm->pieces.Get(i);
        int position = CoordsToPosition(piece->vector2d->x, piece->vector2d->y);

        if(position + rowOperator <= 100 && position + rowOperator > 0){
            if (position % TABLE_WIDTH == 0 && rowOperator == MOVE_LEFT) canMove = false;
            if (position % TABLE_WIDTH == 9 && rowOperator == MOVE_RIGHT) canMove = false;
            if (*(ptr_table + (position + rowOperator)) != nullptr) canMove = false;
        }else{
            canMove = false;
        }
    }
    if(canMove){
        fallingForm->PieceMove(rowOperator);
    }
    
    //Comprueba si la pieza puede caerse despues de (si lo ha hecho) moverse
    for (int i = 0; i < fallingForm->pieces.length && canFall; i++)
    {
        Piece *piece = fallingForm->pieces.Get(i);
        int position = CoordsToPosition(piece->vector2d->x, piece->vector2d->y);

        if(position + ROW_LENGTH <= 100){
            if(*(ptr_table + (position + ROW_LENGTH)) != nullptr) canFall = false;
        }else{
            canFall = false;
        }
    }
    if(canFall){
        fallingForm->PieceFall();
    }

    return canFall;
}

void Table::FallingFormCalc(Form *fallingForm){
for (int i = 0; i < fallingForm->pieces.length; i++)
    {
        ptr_table = tableStart;
        Piece *piece = fallingForm->pieces.Get(i);
        int position = CoordsToPosition(piece->vector2d->x, piece->vector2d->y);
        if(position >= 0){
            ptr_table = ptr_table + position; 
            *ptr_table = piece;
        }
    }
}

int Table::CoordsToPosition(int x, int y){
    if(x < 0 || y < 0){
        return -1;
    }
    return ((y * TABLE_WIDTH) + x);
}