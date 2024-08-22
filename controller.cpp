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
        while (!gameOver)
        {
            auto now = chrono::system_clock::now();
            chrono::duration<float,milli> duration = now - start;
            if(duration.count() > gapTime){
                start = now;
                gameOver = Render();
            }
        }
}

bool Controller::Render(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";  
    if(table == nullptr){   
        table = new Table();
    }else{
        table->RebootTable();
    }

    if(fallingForm == nullptr){
        fallingForm = new Form();
    }else{
        if(!table->Fall(fallingForm)){
            listPieces.Add(fallingForm);
            fallingForm = nullptr;
        }
    }
    table->CalcTable(&listPieces, fallingForm);
    table->RenderTable();
    return false;
}


