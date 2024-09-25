#pragma once
#include "table.h"
#include "form.h"
#include "square.h"
#include "doubleLinkedList.h"

#define GAP_TIME 500
#define L_ARROW_INPUT 75
#define R_ARROW_INPUT 77

class Controller{       // The class
    public:             // Access specifier
    bool gameOver = false;
    int points = 0;
    char direction = ' ';
    Form* fallingForm = nullptr;
    List<Form*> listPieces;
    Table* table = nullptr;

    Controller();

    bool Go(char direction);
};