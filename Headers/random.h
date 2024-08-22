#pragma once
#include <cstdlib>  // Para rand(), srand()
#include <ctime>    // Para time()

class Random{       // The class
        public:             // Access specifier
        bool seeded = false;
        int RandomIntBtw(int min, int max);
};