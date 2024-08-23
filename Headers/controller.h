#pragma once
#include "table.h"
#include "form.h"
#include "square.h"
#include "doubleLinkedList.h"

class Controller{       // The class
    public:             // Access specifier
    const float gapTime = 500;
    bool gameOver = false;
    Form* fallingForm = nullptr;
    List<Form*> listPieces;
    Table* table = nullptr;

    Controller();

    bool Render();
};