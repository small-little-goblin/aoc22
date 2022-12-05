#include <fstream>
#include <iostream>

int main(){
    std::ifstream file("input");
    std::string line, section[2], sectionBegin[2], sectionEnd[2];
    int result = 0;    
    while(std::getline(file, line)){
        section[0] = line.substr(0,line.find(',')); 
        section[1] = line.substr(line.find(',')+1);

        for(int i = 0; i < 2; i++){
            sectionBegin[i] = section[i].substr(0, section[i].find('-'));
            sectionEnd[i] = section[i].substr(section[i].find('-')+1);
            std::cout << i << ": " << sectionBegin[i] << " " << sectionEnd[i] << std::endl;
        } 
        if ( stoi(sectionBegin[0]) <= stoi(sectionBegin[1]) && stoi(sectionEnd[0]) >= stoi(sectionEnd[1]) )
            result++;   
        else if( stoi(sectionBegin[1]) <= stoi(sectionBegin[0]) && stoi(sectionEnd[1]) >= stoi(sectionEnd[0]) )
            result++;
    }
    std::cout << result;
    return 0;
}