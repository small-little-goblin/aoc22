#include <fstream>
#include <iostream>

int main(){
    int input;
    std::cin >> input;
    std::string fileName = input == 1 ? "input" : "testinput"; 
    std::ifstream file(fileName);
    
    int registerX = 1;
    int cycle = 0;

    std::string cmd;
    
    while(file >> cmd){

        if( cycle%40 >= registerX - 1 &&
            cycle%40 <= registerX + 1 ){
                std::cout << "#";
        }
        else {
            std::cout << ".";
        }
        if (cmd != "noop" && cmd != "addx"){
            registerX += stoi(cmd);
        }
        cycle++;
        if(cycle%40 == 0) std::cout << "\n";
    }
}