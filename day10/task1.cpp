#include <fstream>
#include <iostream>

int main(){
    int input;
    std::cin >> input;
    std::string fileName = input == 1 ? "input" : "testinput"; 
    std::ifstream file(fileName);
    
    int registerX = 1;
    int cycle = 0;
    int sum = 0;
    std::string cmd;
    
    while(file >> cmd){
        cycle++;
        if((cycle-20)%40 == 0){
            sum += cycle*registerX;
        }

        if (cmd != "noop" && cmd != "addx"){
            registerX += stoi(cmd);
        }
    }
    std::cout << sum;
}