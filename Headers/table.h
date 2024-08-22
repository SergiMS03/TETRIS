#pragma once
#include "doubleLinkedList.h"
#include "form.h"

class Table {
public:
    static const int table_height = 10;
    static const int table_width = 10;
    string table[table_height][table_width];
    string* ptr_table;

    Table();

    bool Fall(Form *fallingForm);

    void CalcTable(List<Form*> *pieces, Form *fallingForm);  

    bool GetMatches(int x, int y, List<Form*> *forms);

    void RenderTable();

    void RebootTable();
};