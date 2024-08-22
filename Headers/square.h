#pragma once
#include "form.h"
#include "vectors2d.h"
#include "doubleLinkedList.h"



class Square{
    public:
    const string NAME = "square";
    const int MAX_COLUMN = 8;
    List<Vectors2D> vectsSqr;
    
    Square(int x);

    Square(int x, int y);

    void ToString();

};