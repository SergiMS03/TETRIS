#include <iostream>
#include <chrono>
#include <conio.h> 
#include "Headers\controller.h"
#include "Headers\table.h"
#include "Headers\form.h"
#include "Headers\doubleLinkedList.h"

using namespace std;

Controller::Controller(){       // Constructor
    auto start = chrono::system_clock::now();
    table = new Table();
        while (!gameOver)
        {
            if(_kbhit()){
                switch (_getch())
                {
                case L_ARROW_INPUT: //Left
                    direction = 'L';
                    break;
                
                case R_ARROW_INPUT://Right
                    direction = 'R';
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
    //cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
    system("cls");
    table->RebootTable();

    if(fallingForm == nullptr){
        fallingForm = new Form();
    }
    bool continueSameForm = table->QuickCalc(&listPieces, fallingForm, direction);
    if(!continueSameForm){
        listPieces.Add(fallingForm);
        fallingForm = nullptr;
    }
    table->RenderTable();
    return false;
}


