#include <iostream>
#include <chrono>
#include <conio.h> 
#include "Headers\controller.h"
#include "Headers\console.h"
#include "Headers\table.h"
#include "Headers\form.h"
#include "Headers\square.h"
#include "Headers\elRight.h"
#include "Headers\elLeft.h"
#include "Headers\line.h"
#include "Headers\zi.h"
#include "Headers\ziInverted.h"
#include "Headers\ti.h"
#include "Headers\doubleLinkedList.h"

using namespace std;

Controller::Controller(){       // Constructor
    Console::EraseCursor();
    auto start = chrono::system_clock::now();
    table = new Table();
        while (!gameOver)
        {
            if(kbhit() && fallingForm){//IMPLEMENTAR FUNCIONES SEPARADAS PARA CADA ACCIÓN Y ACTUALIZAR Tabla (renderTable)
                char input = getch(); 
                //cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
                system("cls");
                table->RebootTable();
                table->AssembleTable(&listPieces, fallingForm);
                switch (input)
                {
                case L_ARROW_INPUT: //Left
                    table->MoveLeft(fallingForm);
                    break;
                
                case R_ARROW_INPUT://Right
                    table->MoveRight(fallingForm);
                    break;

                case SPIN_ARROW_INPUT://Spin (R)
                    table->Spin(fallingForm);
                    break;
                }
                table->PlaceFallingForm(fallingForm);
                //cout << points << "\n";
                table->RenderTable();
            }
            auto now = chrono::system_clock::now();
            chrono::duration<float,milli> duration = now - start;
            if(duration.count() > GAP_TIME){
                start = now;
                
                gameOver = Go(direction);
                direction = ' ';
            }
        }
    delete table;
}

bool Controller::Go(char direction){
    //cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
    system("cls");
    table->RebootTable();

    if(fallingForm == nullptr){

        fallingForm = newForm();
    }
    table->AssembleTable(&listPieces, fallingForm);
    bool formContact = table->Fall(fallingForm);
    table->PlaceFallingForm(fallingForm);
    if(!formContact){
        listPieces.Add(fallingForm);
        fallingForm = nullptr;
        points += table->CheckForLine(&listPieces);
        gameOver = table->CheckGameOver(&listPieces);
    }
    cout << points << "\n";
    table->RenderTable();
    return gameOver;
}


Form* Controller::newForm(){
    Random *rand = new Random();
    int form = rand->RandomIntBtw(1, 7);
    int xPosition = rand->RandomIntBtw(0, TABLE_WIDTH - 1);
    Form *chosedForm;
    switch (form)
    {
        case 1:{
            chosedForm = new Square(xPosition);
            break;
            }
        case 2:{
            chosedForm = new ElRight(xPosition);
            break;
        }
        case 3:{
            chosedForm = new ElLeft(xPosition);
            break;
        }
        case 4:{
            chosedForm = new Line(xPosition);
            break;
        }
        case 5:{
            chosedForm = new Zi(xPosition);
            break;
        }
        case 6:{
            chosedForm = new ZiInverted(xPosition);
            break;
        }
        case 7:{
            chosedForm = new Ti(xPosition);
            break;
        }
    }
    delete rand;
    return chosedForm;
}


