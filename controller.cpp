#include <iostream>
#include <chrono>
#include <random>
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
            auto now = chrono::system_clock::now();
            chrono::duration<float,milli> duration = now - start;
            if(duration.count() > gapTime){
                start = now;
                gameOver = Render();
            }
        }
    delete table;
}

bool Controller::Render(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";  
    table->RebootTable();

    if(fallingForm == nullptr){
        fallingForm = new Form();
    }
    bool continueSameForm = table->QuickCalc(&listPieces, fallingForm);
    if(!continueSameForm){
        listPieces.Add(fallingForm);
        fallingForm = nullptr;
    }
    table->RenderTable();
    return false;
}


