#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

int main(){
    std::ifstream file("input");
    int score = 0;
    if (file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            std::cout << line[2] << " " << line[0] << std::endl;
            switch(line[2]){
                case 'X': {
                    switch (line[0]){
                        case 'A': score += 3;
                                  break;
                        case 'B': score += 1;
                                  break; 
                        case 'C': score += 2;
                                  break;
                    }
                    break;
                }
                case 'Y': {
                    score += 3;
                    switch (line[0]){
                        case 'A': score += 1;
                                  break;
                        case 'B': score += 2;
                                  break;
                        case 'C': score += 3;
                                  break;
                    }
                    break;
                }
                case 'Z': {
                    score += 6;
                    switch (line[0]){
                        case 'A': score += 2;
                                  break;
                        case 'B': score += 3; 
                                  break;
                        case 'C': score += 1;
                                  break;
                    }
                    break;
                }
            }
        }

        file.close();
    }
    std::cout << score;
    return 0;
}