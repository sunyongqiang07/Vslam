#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <regex>
#include "map.h"
using namespace std;

Map_class::Map_class(string file_name)
{
    ifstream infile;
    infile.open(file_name.data());
    assert(infile.is_open());

    string str_line;
    while(getline(infile,str_line)){
        regex rx_top("\\$[C|F][0-9]+,[0-9]+!");
        smatch sm;
        if(regex_search(str_line,sm,rx_top)){
            /* cout<<sm[0]<<endl; */
            string input = sm[0].str();

            regex rx("\\$[C|F]([0-9]+),([0-9]+)!");
            smatch match;
            if(regex_match(input,match,rx)){
                int x =0;
                int y =0;
                for(int i = 0;i<match.size();++i)
                {
                    ssub_match sub_match  = match[i]; 
                    string num = sub_match.str();
                    /* cout<<"i = "<<i<<"num = "<<num<<endl; */ 
                    if(i == 1){
                        y = atoi(num.c_str());
                    }
                    else if(i == 2){
                        x = atoi(num.c_str());
                    }
                    else if(i == 0){
                    }
                    else{

                        cout<<"error = "<<i<<endl;
                    }
                }
                Map_class::matrix_200_200(x,y) = 1;
                Map_class::matrix_200_200_clone(x,y)=1;
            }
        }
    }
    /* cout<<"matrix = "<<Map_class::matrix_200_200.transpose()<<endl; */
}
int Map_class::get_weight(point target_point){
    int max_row = matrix_200_200.rows();
    int max_col = matrix_200_200.cols();
    /* cout<<"row = "<<max_row<<"col = "<< max_col<<endl; */
    if( target_point.x == 0 || target_point.x == max_col-1 || target_point.y == 0 || target_point.y == max_row-1 ){
        return 0;
    }
    Eigen::Matrix<int,1,9> vector_nei_8;
    vector_nei_8 << matrix_200_200(target_point.x-1,target_point.y+1),matrix_200_200(target_point.x,target_point.y+1),matrix_200_200(target_point.x+1,target_point.y+1),matrix_200_200(target_point.x-1,target_point.y),matrix_200_200(target_point.x,target_point.y),matrix_200_200(target_point.x+1,target_point.y),matrix_200_200(target_point.x-1,target_point.y-1),matrix_200_200(target_point.x,target_point.y-1),matrix_200_200(target_point.x+1,target_point.y-1);
    Eigen::Matrix<int,1,9> vector_wight_8;
    /* vector_wight_8 << 128,1,2,64,0,4,32,16,8; */
    vector_wight_8 <<32,16,8,64,0,4,128,1,2;
    int wight_value = vector_nei_8 * vector_wight_8.transpose();
    return wight_value;
}


vector<point> Map_class::get_border(){
    int max_row = matrix_200_200.rows();
    int max_col = matrix_200_200.cols();
    vector<point> borders;
    /* cout<<"row = "<<max_row<<"col = "<< max_col<<endl; */
    for(int i = 0;i<Map_class::matrix_200_200.rows();++i){
        for(int j = 0;j<Map_class::matrix_200_200.cols();++j){
            /* int value = matrix_200_200(i,j); */
            /* if(count(A0.begin(),A0.end(),value)){ */
            point new_point;
            new_point.x = i;
            new_point.y = j;
            int weight = get_weight(new_point);
            if(count(A0.begin(),A0.end(),weight)){
                borders.push_back(new_point); 
                /* cout<<"weight = "<<weight<<endl; */
            }
            /* borders.push_back(new_point); */
            /* } */
        } 

    }
    return borders;
}
bool Map_class::del_fig(vector<point>& borders,vector<int> modle){
    bool is_change = false;
    for(int i = 0;i<borders.size();++i){
        if(matrix_200_200(borders[i].x,borders[i].y)==1){
            int weight = Map_class::get_weight(borders[i]);
            if(count(modle.begin(),modle.end(),weight)){
                matrix_200_200(borders[i].x,borders[i].y) = 0;
                /* cout << "del i j"<<borders[i].x<<" "<<borders[i].y<<endl; */
                is_change = true;
            }
        }

    }  
    return is_change;
}
vector<point> Map_class::get_back_point(){
    vector<point> resutl ;
    for(int i = 0;i<matrix_200_200.rows();++i){
        for(int j = 0;j<matrix_200_200.cols();++j){
            if(matrix_200_200(i,j) == 0){
                point newpoint; 
                newpoint.x = i;
                newpoint.y = j;
                resutl.push_back(newpoint);
            }    
        }

    }
    return resutl;
};

vector<point> Map_class::get_fig_point(){
    vector<point> resutl ;
    for(int i = 0;i<matrix_200_200.rows();++i){
        for(int j = 0;j<matrix_200_200.cols();++j){
            if(matrix_200_200(i,j) == 1){
                point newpoint; 
                newpoint.x = i;
                newpoint.y = j;
                resutl.push_back(newpoint);
            }    
        }
    }
    return resutl;
};
