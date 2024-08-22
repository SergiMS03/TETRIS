#include "..\Headers\random.h"
#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

using namespace std;

int Random::RandomIntBtw(int min, int max){//Problemas con random
        // Generar el número aleatorio en el rango deseado
        int random = min + (rand() % (max - min + 1));
        return random;
}
