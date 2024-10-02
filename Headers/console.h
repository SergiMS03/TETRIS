#pragma once
#define WIN32_LEAN_AND_MEAN // Evita incluir algunas partes innecesarias de windows.h
#define NOMINMAX            // Evita conflictos con la macro min y max
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class Console{
    private:
    static HANDLE hConsole;

    public:
    static void EraseCursor();
    static void TextColor(string colorStr);
    static void TextColor(int colorNum);
};

class CmdColors{
    public:
    static int MIN_COLOR_VALUE;
    static int MAX_COLOR_VALUE;
    static int dark_blue;
    static int dark_green;
    static int dark_sky_blue;
    static int red;
    static int dark_purple;
    static int dark_yellow;
    static int light_grey;
    static int grey;

    static int blue;
    static int green;
    static int sky_blue;
    static int light_red;
    static int light_purple;
    static int beige;
    static int white;
};

