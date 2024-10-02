#include <iostream>
#include "..\Headers\vectors2d.h"
using namespace std;

Vectors2D::Vectors2D(){
    this->x = 0;
    this->y = 0;
}

Vectors2D::Vectors2D(int x, int y){
    this->x = x;
    this->y = y;
}

void Vectors2D::SetCoords(int x, int y){
    this->x = x;
    this->y = y;
}

void Vectors2D::ToString(){
    cout << "X: " << this->x << "  Y: " << this->y << "\n";
}