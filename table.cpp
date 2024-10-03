#include <iostream>
#include "Headers\table.h"
#include "Headers\doubleLinkedList.h"
#include "Headers\form.h"
#include "Headers\console.h"
using namespace std;

Table::Table(){
    RebootTable();
}

int Table::CheckForLine(List<Form*> *forms){
    ptr_table = tableStart;
    int obtainedPoints = 0;
    for (int y = 0; y < TABLE_HEIGHT; y++)    
    {
        bool line = true; 
        for (int x = 0; x < TABLE_WIDTH && line; x++)
        {
            int position = CoordsToPosition(x, y);
            Piece *piece = *(ptr_table + position);
            if(piece == nullptr){
                line = false;
            }
        }
        if(line){
            DeleteRow(y, forms);
            obtainedPoints += 10;
        }
    }
    return obtainedPoints;
}

bool Table::CheckGameOver(List<Form*> *forms){
    //Repasar fila 0, a ver si hay alguna forma tocando
    bool gameOver = false;
    for (int i = 0; i < forms->length && !gameOver; i++)
    {
        Form *currentForm = forms->Get(i);
        for (int j = 0; j < currentForm->pieces.length && !gameOver; j++)
        {
            Piece *piece = currentForm->pieces.Get(j);
            if(piece->vector2d->y == 0){
                gameOver = true;
            }
        }
    }
    return gameOver;
}

void Table::DeleteRow(int y, List<Form*> *forms){
    for (int x = 0; x < TABLE_WIDTH; x++)
    { 
        //Eliminamos y remplazamos por nullptr en la tabla
        int position = CoordsToPosition(x, y);
        Piece *piece = *(ptr_table + position);
        piece->form->pieces.RemoveByMem(piece);
        *(ptr_table + position) = nullptr;
        if(piece->form->pieces.length == 0){
            forms->RemoveByMem(piece->form);
            delete (piece->form);
        }

        //Bajamos la posicion de las piezas 1 de altura
        for (int i = y; i >= 1; i--)
        {
            int currentPosition = CoordsToPosition(x, i);
            Piece *currentPiece = *(ptr_table + currentPosition);
            if (currentPiece != nullptr)
            {
                currentPiece->vector2d->y++;
            }
            *(ptr_table + currentPosition) = *(ptr_table + (currentPosition - TABLE_WIDTH));
        }
        int x0 = CoordsToPosition(x, 0);
        *(ptr_table + x0) = nullptr;
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

bool Table::MoveLeft(Form *fallingForm){
    bool canMove = true;
    ptr_table = tableStart;
    for (int i = 0; i < fallingForm->pieces.length && canMove; i++)
    {
        Piece *piece = fallingForm->pieces.Get(i);
        int position = CoordsToPosition(piece->vector2d->x, piece->vector2d->y);

        
        if(piece->vector2d->x == 0 || *(ptr_table + (position + MOVE_LEFT)) != nullptr){
            canMove = false;
        }
    }
    if(canMove){
        fallingForm->MovePieces(MOVE_LEFT);
    }
    return canMove;
} 

bool Table::MoveRight(Form *fallingForm){
    bool canMove = true;
    ptr_table = tableStart;
    for (int i = 0; i < fallingForm->pieces.length && canMove; i++)
    {
        Piece *piece = fallingForm->pieces.Get(i);
        int position = CoordsToPosition(piece->vector2d->x, piece->vector2d->y);

        if(piece->vector2d->x == (TABLE_WIDTH - 1) || *(ptr_table + (position + MOVE_RIGHT)) != nullptr){
            canMove = false;
        }
    }
    if(canMove){
        fallingForm->MovePieces(MOVE_RIGHT);
    }
    return canMove;
}

bool Table::Spin(Form *fallingForm){
    bool canSpin = true;
    List<Vectors2D*> *OldPositions = new List<Vectors2D*>;
    for (int i = 0; i < fallingForm->pieces.length; i++)
    {
        OldPositions->Add(new Vectors2D(fallingForm->pieces.Get(i)->vector2d->x, fallingForm->pieces.Get(i)->vector2d->y));
    }
    
    fallingForm->RotateForm();//Rotamos la pieza
    for (int i = 0; i < fallingForm->pieces.length && canSpin; i++)
    {
        ptr_table = tableStart;
        Piece *piece = fallingForm->pieces.Get(i);
        int position = CoordsToPosition(piece->vector2d->x, piece->vector2d->y);

        //Comprobamos que realmente pueda rotar de esa manera
        ptr_table += position;
        if((piece->vector2d->x < 0 || piece->vector2d->x > (TABLE_WIDTH - 1) || piece->vector2d->y < 0 || piece->vector2d->y > (TABLE_HEIGHT - 1)) || *(ptr_table) != nullptr){
            canSpin = false;
        }
    }
    if(!canSpin){//Si no puede la dejamos igual que al inicio
        for (int i = 0; i < fallingForm->pieces.length; i++)
        {
            fallingForm->pieces.Get(i)->vector2d->SetCoords(OldPositions->Get(i)->x, OldPositions->Get(i)->y);
        }
        fallingForm->UndoSpin();
    }
    delete OldPositions;
    OldPositions = nullptr;
    return canSpin;
}

void Table::AssembleTable(List<Form*> *forms, Form *fallingForm){    
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
}

bool Table::Fall(Form *fallingForm){
    //Intenta que la forma siga cayendo si es que aún tiene sitio
    ptr_table = tableStart;
    const int ROW_LENGTH = TABLE_WIDTH;
    bool canFall = true;

    for (int i = 0; i < fallingForm->pieces.length && canFall; i++)
    {
        Piece *piece = fallingForm->pieces.Get(i);
        int position = CoordsToPosition(piece->vector2d->x, piece->vector2d->y);

        if(position + ROW_LENGTH <= (TABLE_HEIGHT * TABLE_WIDTH)){
            if(*(ptr_table + (position + ROW_LENGTH)) != nullptr) canFall = false;
        }else{
            canFall = false;
        }
    }
    if(canFall){
        fallingForm->FallPieces();
    }

    return canFall;
}

void Table::PlaceFallingForm(Form *fallingForm){
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
