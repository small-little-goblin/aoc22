#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

int main(){

    std::ifstream file("input");
    if (file.is_open()){
        std::string line;
        std::string compartment1;
        std::string compartment2;
        int priority;
        int total_priority = 0;
        while(std::getline(file, line)){
            compartment1 = line.substr(0, line.length()/2);
            compartment2 = line.substr(line.length()/2);

            for(int i = 0; i < compartment1.length(); i++){
                for(int j = 0; j < compartment2.length(); j++){
                    if (compartment1[i] == compartment2[j]) {
                        priority = compartment1[i] >= 'a' ? compartment1[i] - '`' : compartment1[i] + (27 - 'A'); 
                        goto breakloop;
                    }   
                }
            }
            breakloop: 
            total_priority += priority;
        }
        file.close();
        printf("\n%i", total_priority);
    }
    return 0;
}