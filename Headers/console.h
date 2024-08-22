#define WIN32_LEAN_AND_MEAN // Evita incluir algunas partes innecesarias de windows.h
#define NOMINMAX            // Evita conflictos con la macro min y max

#pragma once
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class Console{
    private:
    static HANDLE hConsole;

    public:
    static void TextColor(string colorStr);
    static void TextColor(int colorNum);
};

class CmdColors{
    public:
    static char dark_blue;
    static char dark_green;
    static char dark_sky_blue;
    static char red;
    static char dark_purple;
    static char dark_yellow;
    static char light_grey;
    static char grey;

    static char blue;
    static char green;
    static char sky_blue;
    static char light_red;
    static char light_purple;
    static char beige;
    static char white;
};

char CmdColors::dark_blue = 1;
char CmdColors::dark_green = 2;
char CmdColors::dark_sky_blue = 3;
char CmdColors::red = 4;
char CmdColors::dark_purple = 5;
char CmdColors::dark_yellow = 6;
char CmdColors::light_grey = 7;
char CmdColors::grey = 8;
char CmdColors::blue = 9;
char CmdColors::green = 10;
char CmdColors::sky_blue = 11;
char CmdColors::light_red = 12;
char CmdColors::light_purple = 13;
char CmdColors::beige = 14;
char CmdColors::white = 15;


HANDLE Console::hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

void Console::TextColor(string colorStr){
    int colorNum = 0;
    if (colorStr == "dark_blue") {
            colorNum = CmdColors::dark_blue;
        } else if (colorStr == "dark_green") {
            colorNum = CmdColors::dark_green;
        } else if (colorStr == "dark_sky_blue") {
            colorNum = CmdColors::dark_sky_blue;
        } else if (colorStr == "red") {
            colorNum = CmdColors::red;
        } else if (colorStr == "dark_purple") {
            colorNum = CmdColors::dark_purple;
        } else if (colorStr == "dark_yellow") {
            colorNum = CmdColors::dark_yellow;
        } else if (colorStr == "light_grey") {
            colorNum = CmdColors::light_grey;
        } else if (colorStr == "grey") {
            colorNum = CmdColors::grey;
        } else if (colorStr == "blue") {
            colorNum = CmdColors::blue;
        } else if (colorStr == "green") {
            colorNum = CmdColors::green;
        } else if (colorStr == "sky_blue") {
            colorNum = CmdColors::sky_blue;
        } else if (colorStr == "light_red") {
            colorNum = CmdColors::light_red;
        } else if (colorStr == "light_purple") {
            colorNum = CmdColors::light_purple;
        } else if (colorStr == "beige") {
            colorNum = CmdColors::beige;
        } else if (colorStr == "white") {
            colorNum = CmdColors::white;
        } else {
            cout << "Color no válido\n";
            return;
        }
    SetConsoleTextAttribute(hConsole, colorNum);
}

void Console::TextColor(int colorNum){
    SetConsoleTextAttribute(hConsole, colorNum);
}