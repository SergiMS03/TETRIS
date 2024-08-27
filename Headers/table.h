#pragma once
#include "doubleLinkedList.h"
#include "form.h"

#define TABLE_HEIGHT 10
#define TABLE_WIDTH 10
#define EMPTY_BOX -1
#define MOVE_LEFT -1
#define MOVE_RIGHT 1

class Table {
public:
    int table[TABLE_HEIGHT][TABLE_WIDTH];
    int *tableStart = &table[0][0];
    int* ptr_table;

    Table();

    bool Fall(Form *fallingForm);
 
    bool QuickCalc(List<Form*> *pieces, Form *fallingForm, char direction);
    void FallingFormCalc(Form *fallingForm);
    bool ColisionCalc(Form *fallingForm, char direction);
    int CoordsToPosition(int x, int y);

    bool GetMatches(int x, int y, List<Form*> *forms);

    void RenderTable();

    void RebootTable();
};