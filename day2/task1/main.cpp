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
                    score++;
                    switch (line[0]){
                        case 'A': score += 3;
                                  break;
                        case 'B': score += 0;
                                  break; 
                        case 'C': score += 6;
                                  break;
                    }
                    break;
                }
                case 'Y': {
                    score += 2;
                    switch (line[0]){
                        case 'A': score += 6;
                                  break;
                        case 'B': score += 3;
                                  break;
                        case 'C': score += 0;
                                  break;
                    }
                    break;
                }
                case 'Z': {
                    score += 3;
                    switch (line[0]){
                        case 'A': score += 0;
                                  break;
                        case 'B': score += 6; 
                                  break;
                        case 'C': score += 3;
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