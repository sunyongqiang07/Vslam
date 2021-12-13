#include <iostream>
#include <ctime>
#include "map.h"
// Eigen 部分
#include "/usr/include/eigen3/Eigen/Core"
// 稠密矩阵的代数运算（逆，特征值等）
#include "/usr/include/eigen3/Eigen/Dense"
#include <cmath>
#include "/home/qingwa/my_Lib/matplotlib-cpp/matplotlibcpp.h"
#include <iostream>
namespace plt = matplotlibcpp;

using namespace Eigen;
using namespace std;
void plot_borders(vector<point> borders,int type,bool is_show){

    int num = borders.size();
    cout<<"borders.size"<<borders.size()<<endl;
    vector<int> x(num),y(num);
    for(int j = 0;j<borders.size(); ++j){
        y.push_back(borders[j].x);
        x.push_back(borders[j].y);
    }
    if(type ==0){
        plt::plot(x,y,"r*");
        if(is_show){
            plt::show();
        }
        /* plt::show(); */


    }
    else if(type == 1){
        plt::plot(x,y,"y*");
        if(is_show){
            plt::show();
        }

    }
    else{
        plt::plot(x,y,"g*");
        if(is_show){
            plt::show();
        }
    }

}
int main(int argv,char** argc )
{
    Map_class map(argc[1]);
    bool is_change = true;
    vector<point>back_points = map.get_back_point();
    vector<point>fig_points = map.get_fig_point();
    plot_borders(back_points,0,false);
    plot_borders(fig_points,2,false);

    /* return 1; */
    int i = 0;
    while(is_change){
        i++;
        cout<<"i = "<<i<<endl;
        vector<point> borders = map.get_border();     
        cout<<"borders count = "<<borders.size()<<" i = "<<i<<endl;
        /* plot_borders(borders,1,true); */
        /* return 1; */
        map.del_fig(borders,map.A1);
        map.del_fig(borders,map.A2);
        map.del_fig(borders,map.A3);
        map.del_fig(borders,map.A4);
        map.del_fig(borders,map.A5);
        is_change = map.del_fig(borders,map.A6);
        if(is_change == false){
            borders = map.get_fig_point();
            bool change = true;
            while(change){
                cout <<"第六步"<<endl;
                change = map.del_fig(borders,map.A6);
            }
            
            point temp_point;
            temp_point.x = 101;
            temp_point.y = 75;
            int value = map.get_weight(temp_point);
            cout <<"87 88 = " <<value<<endl;
            /* plot_borders(borders1,1,true); */
            /* vector<point> borders1 = map.get_border(); */ 
            /* vector<point>back_points = map.get_back_point(); */
            vector<point>fig_points = map.get_fig_point();
            plot_borders(back_points,0,false);
            plot_borders(fig_points,1,true);

        }
    }
    /* cout<<map.matrix_200_200.transpose()<<endl; */
    return 0;
}



