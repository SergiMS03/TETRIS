#include "..\Headers\square.h"
#include "..\Headers\form.h"
#include "..\Headers\vectors2d.h"
#include <iostream>
using namespace std;

Square::Square(int x){
    while (x > MAX_COLUMN)
    {
        x--;
    }
    Vectors2D *vect1 = new Vectors2D(0 + x, -1);
    Vectors2D *vect2 = new Vectors2D(1 + x, -1);
    Vectors2D *vect3 = new Vectors2D(0 + x, 0);
    Vectors2D *vect4 = new Vectors2D(1 + x, 0);
    vectsSqr.Add(*vect1);//x y
    vectsSqr.Add(*vect2);
    vectsSqr.Add(*vect3);
    vectsSqr.Add(*vect4);
    delete vect1;
    delete vect2;
    delete vect3;
    delete vect4;
};

Square::Square(int x, int y){
    Vectors2D *vect1 = new Vectors2D(x, y);
    Vectors2D *vect2 = new Vectors2D(1 + x, y);
    Vectors2D *vect3 = new Vectors2D(x, 1 + y);
    Vectors2D *vect4 = new Vectors2D(1 + x, 1 + y);
    vectsSqr.Add(*vect1);//x y
    vectsSqr.Add(*vect2);
    vectsSqr.Add(*vect3);
    vectsSqr.Add(*vect4);
    delete vect1;
    delete vect2;
    delete vect3;
    delete vect4;
};

void Square::ToString(){
    for (int i = 0; i < vectsSqr.length; i++)
    {
        vectsSqr.Get(i).ToString();
    }
    
}