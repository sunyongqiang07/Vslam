#ifndef __MAP_H__
#define __MAP_H__
#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>
#include <vector>
// Eigen 部分
#include "/usr/include/eigen3/Eigen/Core"
// 稠密矩阵的代数运算（逆，特征值等）
#include "/usr/include/eigen3/Eigen/Dense"
#include <fstream>
using namespace Eigen;
using namespace std;

class point{
public: 
    int x;
    int y; 
};
class Map_class
{
public:
    MatrixXd matrix_200_200 = MatrixXd::Zero(200,200);
    MatrixXd matrix_200_200_clone = MatrixXd::Zero(200,200);

    Map_class();
    Map_class(string);

    int get_weight(point target_point);
    vector<point> get_back_point();
    vector<point> get_fig_point();
    vector<point> get_border();
    bool del_fig(vector<point>& borders,vector<int> modle);
    /* Vector<point> */

    /* ~Map_class(); */

    vector<int> A0 = {3,6,7,12,14,15,24,28,30,31,48,56,60,62,63,96,112,120,124,126,127,129,131,135,143,159,191,192,193,195,199,207,223,224,225,227,231,239,240,241,243,247,248,249,251,252,253,254};
    vector<int> A1 ={7,14,28,56,112,131,193,224};
    vector<int> A2 = {7,14,15,28,30,56,60,112,120,131,135,193,195,224,225,240};
    vector<int> A3 = {7,14,15,28,30,31,56,60,62,112,120,124,131,135,143,193,195,199,224,225,227,240,241,248};
    vector<int> A4 = {7,14,15,28,30,31,56,60,62,63,112,120,124,126,131,135,143,193,195,199,224,225,227,240,241,248};
    vector<int> A5 = {7,14,15,28,30,31,56,60,62,63,112,120,124,126,131,135,143,159,191,193,195,199,207,224,225,227,231,239,240,241,243,248,249,251,252,254};
    vector<int> A6 = {3,6,7,12,14,15,24,28,30,31,48,56,60,62,63,96,112,120,124,126,127,129,131,135,143,159,191,192,193,195,199,207,223,224,225,227,231,239,240,241,243,247,248,249,251,252,253,254};
private:
};

#endif

