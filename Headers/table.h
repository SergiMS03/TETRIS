#pragma once
#include "doubleLinkedList.h"
#include "form.h"

class Table {
public:
    static const int table_height = 10;
    static const int table_width = 10;
    string table[table_height][table_width];
    string *tableStart = &table[0][0];
    string* ptr_table;

    Table();

    bool Fall(Form *fallingForm);

    void CalcTable(List<Form*> *pieces, Form *fallingForm);  
    bool QuickCalc(List<Form*> *pieces, Form *fallingForm); 
    bool ColisionCalc(List<Form*> *pieces, Form *fallingForm);
    int CoordsToPosition(int x, int y);

    bool GetMatches(int x, int y, List<Form*> *forms);

    void RenderTable();

    void RebootTable();
};