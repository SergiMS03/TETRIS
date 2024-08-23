#include <iostream>
#include "Headers\table.h"
#include "Headers\doubleLinkedList.h"
#include "Headers\form.h"
#include "Headers\console.h"
using namespace std;

Table::Table(){
    RebootTable();
}

bool Table::Fall(Form *fallingForm){
    bool canFall = true;
    int maxY = -1;//Buscamos el punto mas bajo de la pieza (la Y mas grande)
    for (int i = 0; i < fallingForm->pieces.length; i++)
    {
        Vectors2D vec = fallingForm->pieces.Get(i);
        if(maxY < vec.y){
            maxY = vec.y;
        }
    }
    List<Vectors2D> *bottomPieces = new List<Vectors2D>();//Pasamos Vector2D, no una referencia, así después podemos modificar y eliminar valores
    for (int i = 0; i < fallingForm->pieces.length; i++)
    {
        Vectors2D vec = fallingForm->pieces.Get(i);
        bottomPieces->Add(vec);
    }
    
    for (int i = 0; i < bottomPieces->length; i++)//Bottom pieces han de detectar el suelo, linea 9, si esta en el suelo no cae ninguna pieza mas
    {
        if (bottomPieces->Get(i).y >= table_height - 1)
        {
            canFall = false;
        }
    }
    if(canFall){
        for (int i = 0; i < fallingForm->pieces.length; i++)
        {
            fallingForm->PieceFall(i);
        }
        
    }
    bottomPieces->~List();
    return canFall;
}

void Table::CalcTable(List<Form*> *forms, Form *fallingForm){    
    ptr_table = tableStart;
    if(forms->length > 0){
        for (int y = 0; y < table_height; y++)
        {
            for (int x = 0; x < table_width; x++)
            {
                if(GetMatches(x, y, forms)){
                    
                    *ptr_table = "x";
                }else{

                }
                ptr_table++;
            }
            
        }
    }

    //Borrar luego y implementar bien si funciona
    ptr_table = tableStart;
    if(fallingForm != nullptr){
        for (int y = 0; y < table_height; y++)
        {
            for (int x = 0; x < table_width; x++)
            {
                for (int i = 0; i < fallingForm->pieces.length; i++)
                {
                    if(fallingForm->pieces.Get(i).x == x && fallingForm->pieces.Get(i).y == y){
                        *ptr_table = "x";
                    }
                }
                
                ptr_table++;
            }
            
        }
    }
    //Borrar luego y implementar bien si funciona
    
}

bool Table::GetMatches(int x, int y, List<Form*> *forms){
    for (int i = 0; i < forms->length; i++)
    {
        for (int j = 0; j < forms->Get(i)->pieces.length; j++)
        {
            if(forms->Get(i)->pieces.Get(j).x == x && forms->Get(i)->pieces.Get(j).y == y){
                return true;//Si encuentra la pieza salimos
            }
        }
    }
    return false;
}

void Table::RenderTable(){
    
    ptr_table = tableStart;
    for (int i = 0; i < table_height; i++)
    {
        for (int j = 0; j < table_width; j++)
        {
            
            if(*ptr_table == "x"){
                Console::TextColor(CmdColors::red);
                cout << *ptr_table << " ";
                Console::TextColor(CmdColors::light_grey);
            }
            else{
                cout << *ptr_table << " ";
            }
            
            ptr_table++;
        }
        cout << "\n";
    }
}

void Table::RebootTable(){
    
    ptr_table = tableStart;
    for (int i = 0; i < table_height * table_width; i++)
    {
        *ptr_table = "o";
        ptr_table++;
    }
}

bool Table::QuickCalc(List<Form*> *forms, Form *fallingForm){    
    for (int i = 0; i < forms->length; i++)
    {
        Form *form = forms->Get(i);
        for (int j = 0; j < form->pieces.length; j++)
        {
            ptr_table = tableStart;
            Vectors2D *vec = form->pieces.GetMem(j);
            int position = CoordsToPosition(vec->x, vec->y);
            ptr_table = ptr_table + position; 
            *ptr_table = "x";
        }
    }
    
    return ColisionCalc(forms, fallingForm);
}

bool Table::ColisionCalc(List<Form*> *forms, Form *fallingForm){
    const int ROW_OPERATOR = table_height;
    const int COLUMN_OPERATOR = 1;
    bool canFall = true;
    for (int i = 0; i < fallingForm->pieces.length && canFall; i++)
    {
        ptr_table = tableStart;
        Vectors2D *vec = fallingForm->pieces.GetMem(i);
        int position = CoordsToPosition(vec->x, vec->y);
        ptr_table = ptr_table + (position + ROW_OPERATOR);
        if(*ptr_table == "x" || position + ROW_OPERATOR > 100){
            canFall = false; //Si tiene una pieza abajo no cae (mira todas las pieza de la forma)
        }
    }

    Form *formToPaint = fallingForm;
    if(canFall){
        fallingForm->PieceFall();
    }

    for (int i = 0; i < formToPaint->pieces.length; i++)
    {
        ptr_table = tableStart;
        Vectors2D *vec = formToPaint->pieces.GetMem(i);
        int position = CoordsToPosition(vec->x, vec->y);
        if(position >= 0){
            ptr_table = ptr_table + position; 
            *ptr_table = "x";
        }
    }
    
    formToPaint = nullptr;
    return canFall;
}

int Table::CoordsToPosition(int x, int y){
    if(x < 0 || y < 0){
        return -1;
    }
    return ((y * table_width) + x);
}