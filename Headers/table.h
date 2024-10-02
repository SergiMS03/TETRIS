#pragma once
#include "doubleLinkedList.h"
#include "piece.h"
#include "form.h"

#define TABLE_HEIGHT 15
#define TABLE_WIDTH 10
#define EMPTY_BOX -1
#define MOVE_LEFT -1
#define MOVE_RIGHT 1

class Table {
public:
    Piece *table[TABLE_HEIGHT][TABLE_WIDTH];
    Piece **tableStart = &table[0][0];
    Piece **ptr_table;

    Table();
 
    bool MoveLeft(Form *fallingForm);
    bool MoveRight(Form *fallingForm);
    bool Spin(Form *fallingForm);
    bool Fall(Form *fallingForm);

    void DeleteRow(int y, List<Form*> *forms);

    void AssembleTable(List<Form*> *forms, Form *fallingForm);
    void PlaceFallingForm(Form *fallingForm);

    int CheckForLine(List<Form*> *forms);
    bool CheckGameOver(List<Form*> *forms);
    
    int CoordsToPosition(int x, int y);

    void RenderTable();
    void RebootTable();
};