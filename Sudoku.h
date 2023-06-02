#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#ifndef SUDOKU_H
#define SUDOKU_H
class Sudoku
{
private:
    vector<vector<int>> board;
public:
    Sudoku();
    void generate();
    void print();
    bool isValid(int row, int col, int num);
    bool findEmptyCell(int& row, int& col);
    bool solve();
    void play();
};
#endif
