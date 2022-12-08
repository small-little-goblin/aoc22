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

    int scenicScoreLeft, scenicScoreRight, scenicScoreTop, scenicScoreBottom, scenicScore, maxScenicScore;
    for (int i = 1; i < woods.size()-1; i++){
        for(int j = 1; j < woods[i].size()-1; j++){
            scenicScoreLeft = 0;
            scenicScoreRight = 0;
            scenicScoreTop = 0; 
            scenicScoreBottom = 0;
            for(int l = j-1; l >= 0; l--){
                scenicScoreLeft++;
                if (woods[i][j] <= woods[i][l]) break;
            }
            for(int r = j+1; r < woods[i].size(); r++){
                scenicScoreRight++;
                if (woods[i][j] <= woods[i][r]) break;
            }
            for(int t = i-1; t >= 0; t--){
                scenicScoreTop++;
                if (woods[i][j] <= woods[t][j]) break;
            }
            for(int b = i+1; b < woods.size(); b++){
                scenicScoreBottom++;
                if (woods[i][j] <= woods[b][j]) break;
            }
            scenicScore = scenicScoreLeft * scenicScoreRight * scenicScoreTop * scenicScoreBottom;
            std::cout << scenicScoreLeft <<" "<<scenicScoreRight<<" "<< scenicScoreTop<<" "<<scenicScoreBottom <<"\n";
            maxScenicScore = maxScenicScore > scenicScore ? maxScenicScore : scenicScore;
        }
    }
    std::cout << maxScenicScore;
}
/*
For each (inner grid-)point:
    create 4 vectors (left, right, over- under)
    if point is biggest on either side: result++    
*/
