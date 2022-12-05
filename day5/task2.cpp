#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <stack>


int main(){
    std::ifstream file("input");
    std::string line;
    std::vector< std::stack<char> > crates (10);

    // Read initial crates
    do {
        std::getline(file,line);
        for(int i = 0; i < line.length(); i++){
            if ( line[i] == '[' ){
                crates[i/4].push(line[i+1]);
            }  
        }
    } while(line.find('[') != std::string::npos);

        // POV: Stupid village-boy uses stack instead of dequeue and now has to reverse the stack
        for (int i = 0; i < crates.size(); i++){
            std::stack<char> tmpStack;
            while (!crates[i].empty())
            {
                char item = crates[i].top();
                crates[i].pop();
                tmpStack.push(item);
            }
                crates[i] = tmpStack;
        }

        // Read commands to move crates
    while( std::getline(file, line)) {
        std::stack<char> tmpStack;
        if(line.find("move") != std::string::npos){
            int amount, from, to;
            std::sscanf(line.c_str(), "%*s %d %*s %d %*s %d", &amount, &from, &to);
            from--;
            to--;
            //fill temporary stack and then, empty the tmpStack into the target 
            for (int i = 0; i < amount; i++){
                tmpStack.push(crates[from].top());
                crates[from].pop();                
            } 

            while(!tmpStack.empty()){
                crates[to].push(tmpStack.top());
                tmpStack.pop();
            }

        }     
    }
    for(int i = 0; i < crates.size(); i++){
        std::cout << " ";
        if (!crates[i].empty()) std::cout << crates[i].top();
            
    }         
    return 0;
}