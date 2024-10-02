#include "..\Headers\elRight.h"
#include "..\Headers\form.h"
#include "..\Headers\piece.h"
#include <iostream>
using namespace std;

void ElRight::ToString(){
    for (int i = 0; i < pieces.length; i++)
    {
        pieces.Get(i)->ToString();
    }
    
}