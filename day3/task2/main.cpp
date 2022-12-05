#include <fstream>
#include <iostream>

int main(){

    std::ifstream file("input");
    if (file.is_open()){
        std::string line[3];
        int total_priority = 0;
        int groupIndex = 0;
        while(file >> line[0] >> line[1] >> line[2]) {
            for(auto item : line[0]){
                auto contender = line[1].find(item);
                if (contender != std::string::npos){
                    contender = line[2].find(item);
                    if (contender != std::string::npos){
                        auto sharedItem = line[2].substr(contender, 1);
                        total_priority += sharedItem[0] >= 'a' ? sharedItem[0] - '`' : sharedItem[0] + (27 - 'A'); 
                        break;
                    }
                }
            }
            
        }
        file.close();
        printf("\n%i", total_priority);
    }
    return 0;
}

//                         
