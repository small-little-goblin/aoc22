#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
    std::ifstream file("input");
    std::vector<std::vector<int>> woods;
    std::string line;
    int row = 0;
  
    //fill woods vector
    while(getline(file, line)){
        std::vector<int> rowVec;
        for(int i = 0; i < line.length(); i++)
        {   
            rowVec.push_back((int) line[i] - '0');
        }
        woods.push_back(rowVec);
        row++;
    }

        std::vector<int> left;
        std::vector<int> right;
        std::vector<int> top;
        std::vector<int> bottom;
        int visible = pow(woods.size(),2) - pow(woods.size()-2,2);
        bool vis;
    for (int i = 1; i < woods.size()-1; i++){
        for(int j = 1; j < woods[i].size()-1; j++){
            
            vis = false;
            left.clear(); right.clear(); top.clear(); bottom.clear();
            //fill vector for each side from current point
            for(int l = 0; l < j; l++){
                left.push_back(woods[i][l]);
            }
            for(int r = j+1; r < woods[i].size(); r++){
                right.push_back(woods[i][r]);
            }
            for(int t = 0; t < i; t++){
                top.push_back(woods[t][j]);
            }
            for(int b = i+1; b < woods.size(); b++){
                bottom.push_back(woods[b][j]);
            }
            //compare current point with highest point on either side
            if( woods[i][j] > *max_element(left.begin(), left.end())) vis=true;   
            if( woods[i][j] > *max_element(right.begin(), right.end())) vis=true; 
            if( woods[i][j] > *max_element(top.begin(), top.end())) vis=true;       
            if( woods[i][j] > *max_element(bottom.begin(), bottom.end())) vis=true;             
            
            if(vis) visible++;
        }
    }
    std::cout << visible;
}
/*
For each (inner grid-)point:
    create 4 vectors (left, right, over- under)
    if point is biggest on either side: result++    
*/
