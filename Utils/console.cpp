#include "..\Headers\console.h"

int CmdColors::MIN_COLOR_VALUE = 1;
int CmdColors::MAX_COLOR_VALUE = 15;
int CmdColors::dark_blue = 1;
int CmdColors::dark_green = 2;
int CmdColors::dark_sky_blue = 3;
int CmdColors::red = 4;
int CmdColors::dark_purple = 5;
int CmdColors::dark_yellow = 6;
int CmdColors::light_grey = 7;
int CmdColors::grey = 8;
int CmdColors::blue = 9;
int CmdColors::green = 10;
int CmdColors::sky_blue = 11;
int CmdColors::light_red = 12;
int CmdColors::light_purple = 13;
int CmdColors::beige = 14;
int CmdColors::white = 15;


HANDLE Console::hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

void Console::EraseCursor(){
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cci);
}

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