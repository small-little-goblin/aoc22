#include <iostream>
#include <fstream>
#include <map>
#include <set>


#define ADJACENET_X abs(headPositionX - tailPositionX) <= 1
#define ADJACENET_Y abs(headPositionY - tailPositionY) <= 1



int main()  {
    std::ifstream file("input");
    std::string line;
    std::set<std::pair<int, int>> tailPath;
    int tailPositionX = 0;
    int tailPositionY = 0;
    int headPositionX = 0;
    int headPositionY = 0;

    char direction;
    int moveDistance;
    while(std::getline(file, line)){
        sscanf(line.c_str(),"%c %d", &direction, &moveDistance);
        for(int i = 0; i < moveDistance; i++){
            switch(direction){
                case 'L': 
                    --headPositionX;
                    break;
                case 'R': 
                    ++headPositionX;
                    break;
                case 'U': 
                    ++headPositionY; 
                    break;
                case 'D': 
                    --headPositionY;
                    break;
            }
            if      ( ADJACENET_X && ADJACENET_Y) 
                    {} //do nothing
            else if ( headPositionX == (tailPositionX + 2) &&
                      headPositionY == tailPositionY)
                    {
                      tailPositionX++;
                    }
            else if ( headPositionX == (tailPositionX - 2) &&
                      headPositionY == tailPositionY)
                    {
                      tailPositionX--;
                    }
            else if ( headPositionY == (tailPositionY + 2) &&
                       headPositionX == tailPositionX)
                    {
                      tailPositionY++;
                    }
            else if ( headPositionY == (tailPositionY - 2) &&
                      headPositionX == tailPositionX)
                    {
                      tailPositionY--;
                    }
            else if  ( 
                       headPositionX > tailPositionX &&
                       headPositionY > tailPositionY)
                    {
                      tailPositionX++;
                      tailPositionY++;
                    }
            else if  ( 
                       headPositionX > tailPositionX &&
                       headPositionY < tailPositionY)
                    {
                      tailPositionX++;
                      tailPositionY--;
                    }
            else if  ( 
                       headPositionX < tailPositionX &&
                       headPositionY > tailPositionY)
                    {
                      tailPositionX--;
                      tailPositionY++;
                    }
            else if  ( 
                       headPositionX < tailPositionX &&
                       headPositionY < tailPositionY)
                    {
                      tailPositionX--;
                      tailPositionY--;   
                    }
            tailPath.insert({tailPositionX, tailPositionY});
            std::cout <<" Position HEAD (" <<headPositionX << ","<< headPositionY << "), Position TAIL (" <<tailPositionX << ","<< tailPositionY << ")\n";
        }
    }
    std::cout << tailPath.size();

}