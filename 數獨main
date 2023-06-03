#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Sudoku.h"
#include "Time.h"
using namespace std;

int main()
{
    cout << "輸入你的名字";
    string a;
    cin >> a;
    Time time(a);
    time.start();
    cout << time.getname();
    Sudoku sudoku;
    sudoku.generate();
    cout << "的題目" << endl;
    sudoku.print();
    sudoku.play();
    time.stop();
    time.printTimeTaken();
    return 0;
}
