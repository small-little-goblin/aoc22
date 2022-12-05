#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>

int main(){
    std::ifstream file("input");
    int currentCalories = 0;
    int maxCalories = 0;
    std::string line;

    if (file.is_open()) {
        while(std::getline(file, line)){
            if (line == ""){
                if (currentCalories > maxCalories){
                    maxCalories = currentCalories;
                }
                currentCalories = 0;
            }
            else {
                currentCalories += stoi(line);
            }
        } 
        file.close();
        printf("%i", maxCalories);
    }
    return 0;
}
