#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>

void checkCalories(int max[], int cur){
    if (cur > max[0]){
        max[0] = cur;
        for(int i = 0; i < 2; i++){
            if (max[i] > max[i+1]){
                int tmp = max[i+1];
                max[i+1] = max[i];
                max[i] = tmp;
            }
        }
    }      
}

int main(){
    std::ifstream file("input");
    int currentCalories = 0;
    int maxCalories[] = {0, 0, 0};
    int result = 0;
    std::string line;

    if (file.is_open()) {
        while(std::getline(file, line)){
            if (line == ""){
                checkCalories(maxCalories, currentCalories);
                currentCalories = 0;
            }
            else {
                currentCalories += stoi(line);
            }
        } 
        file.close();    
    }
    for(int i = 0; i < 3; i++){
        result += maxCalories[i];
    }
    printf("%i", result);
    return 0;
}
