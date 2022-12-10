#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>

#define ADJACENET_X abs(knots[i].first - knots[i+1].first) <= 1
#define ADJACENET_Y abs(knots[i].second - knots[i+1].second) <= 1



int main()  {
    std::ifstream file("input");
    std::string line;
    std::set<std::pair<int, int>> tailPath;
    std::pair<int, int> knots[10] = {std::make_pair(0,0)};
    char direction;
    int moveDistance;
    while(std::getline(file, line)){
        sscanf(line.c_str(),"%c %d", &direction, &moveDistance);
        for(int m = 0; m < moveDistance; m++){
            switch(direction){
                case 'L': 
                    --knots[0].first;
                    break;
                case 'R': 
                    ++knots[0].first;
                    break;
                case 'U': 
                    ++knots[0].second;
                    break;
                case 'D': 
                    --knots[0].second;
                    break;
            }
            for(int i = 0; i < 9; i++){
                if      ( ADJACENET_X && ADJACENET_Y) 
                        {} //do nothing
                else if ( knots[i].first == (knots[i+1].first + 2) &&
                        knots[i].second == knots[i+1].second)
                        {
                        knots[i+1].first++;
                        }
                else if ( knots[i].first == (knots[i+1].first - 2) &&
                        knots[i].second == knots[i+1].second)
                        {
                        knots[i+1].first--;
                        }
                else if ( knots[i].second == (knots[i+1].second + 2) &&
                        knots[i].first == knots[i+1].first)
                        {
                        knots[i+1].second++;
                        }
                else if ( knots[i].second == (knots[i+1].second - 2) &&
                        knots[i].first == knots[i+1].first)
                        {
                        knots[i+1].second--;
                        }
                else if  ( 
                        knots[i].first > knots[i+1].first &&
                        knots[i].second > knots[i+1].second)
                        {
                        knots[i+1].first++;
                        knots[i+1].second++;
                        }
                else if  ( 
                        knots[i].first > knots[i+1].first &&
                        knots[i].second < knots[i+1].second)
                        {
                        knots[i+1].first++;
                        knots[i+1].second--;
                        }
                else if  ( 
                        knots[i].first < knots[i+1].first &&
                        knots[i].second > knots[i+1].second)
                        {
                        knots[i+1].first--;
                        knots[i+1].second++;
                        }
                else if  ( 
                        knots[i].first < knots[i+1].first &&
                        knots[i].second < knots[i+1].second)
                        {
                        knots[i+1].first--;
                        knots[i+1].second--;   
                        }

                std::cout << "Knot[i] " << i << " (" << knots[i].first << "," << knots[i].second << ")\n";
                }
            tailPath.insert({knots[9].first, knots[9].second});
            std::cout << "\n";
        }
    }
    std::cout << tailPath.size();

}