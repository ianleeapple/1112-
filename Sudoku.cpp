#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{

}
void Sudoku::print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void Sudoku::generate()
{
    srand(time(0));
    board = vector<vector<int>>(9, vector<int>(9, 0));
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < 9; i++)
    {
        int j = rand() % 9;
        swap(nums[i], nums[j]);
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = nums[(i * 3 + i / 3 + j) % 9];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (rand() % 2 == 0)
            {
                board[i][j] = 0;
            }
        }
    }

}
bool Sudoku::isValid(int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }
    int box_row = row / 3 * 3;
    int box_col = col / 3 * 3;
    for (int i = box_row; i < box_row + 3; i++)
    {
        for (int j = box_col; j < box_col + 3; j++)
        {
            if (board[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool Sudoku::solve()
{
    int row, col;
    if (!findEmptyCell(row, col))
    {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(row, col, num))
        {
            board[row][col] = num;
            if (solve())
            {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

bool Sudoku::findEmptyCell(int& row, int& col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}
void Sudoku::play()
{
    int row, col, num;
    while (findEmptyCell(row, col))
    {
        cout << "第" << row + 1 << "列" << col + 1 << "行";
        cin >> num;

        if (num < 1 || num > 9)
        {
            cout << "請輸入數字1到9" << endl;
            continue;
        }

        if (!isValid(row, col, num))
        {
            cout << "輸入的數字不符合數獨規則，請重新輸入" << endl;
            continue;
        }

        board[row][col] = num;
        print();

        Sudoku tempBoard = *this;
        if (!tempBoard.solve())
        {
            cout << "請重新輸入" << endl;
            board[row][col] = 0;
            print();
            continue;
        }
    }
    if (solve())
    {
        cout << "太棒了" << endl;
        print();
    }
    else
    {
        cout << "請重新輸入" << endl;
    }
}

