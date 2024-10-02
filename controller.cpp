#include <iostream>
#include <chrono>
#include <conio.h> 
#include "Headers\controller.h"
#include "Headers\table.h"
#include "Headers\form.h"
#include "Headers\square.h"
#include "Headers\elRight.h"
#include "Headers\doubleLinkedList.h"

using namespace std;

Controller::Controller(){       // Constructor
    auto start = chrono::system_clock::now();
    table = new Table();
        while (!gameOver)
        {
            if(_kbhit()){//IMPLEMENTAR FUNCIONES SEPARADAS PARA CADA ACCIÓN Y ACTUALIZAR Tabla (renderTable)
                switch (_getch())
                {
                case L_ARROW_INPUT: //Left
                    direction = 'L';
                    break;
                
                case R_ARROW_INPUT://Right
                    direction = 'R';
                    break;

                case 114://Spin
                    direction = 'S';
                    break;
                }
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
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
    //system("cls");
    cout << points << "\n";
    table->RebootTable();

    if(fallingForm == nullptr){

        fallingForm = newForm();
    }
    bool formContact = table->QuickCalc(&listPieces, fallingForm, direction);
    if(!formContact){
        listPieces.Add(fallingForm);
        fallingForm = nullptr;
        points += table->CheckForLine(&listPieces);
        gameOver = table->CheckGameOver(&listPieces);
    }
    table->RenderTable();
    return gameOver;
}


Form* Controller::newForm(){
    Random *rand = new Random();
    int form = rand->RandomIntBtw(1, 2);
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
    }
    delete rand;
    return chosedForm;
}


