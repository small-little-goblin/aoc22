#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

struct Cell{
    int x, y, distance;
};

void BFS(std::vector<std::vector<char>> g, Cell startV, std::vector<std::vector<bool>> vis){
    std::queue<Cell> q;
    q.push(startV);
    vis[startV.x][startV.y] = true;
    while(!q.empty()){
        Cell v = q.front();
        q.pop();
        if(g[v.x][v.y] == 'a'){
            v.distance = 0;
        }
        if(g[v.x][v.y] == 'z' + 1){
            std::cout << v.distance;
            return;
        }
        if(v.x - 1 >= 0 && !vis[v.x-1][v.y] &&
           g[v.x-1][v.y] - g[v.x][v.y] <= 1){
            q.push(Cell{v.x-1, v.y, v.distance+1});     
            vis[v.x-1][v.y] = 1;
        }   
        if(v.x + 1 < g.size() && !vis[v.x+1][v.y] &&
           g[v.x+1][v.y] - g[v.x][v.y] <= 1){
            q.push(Cell{v.x+1, v.y, v.distance+1});
            vis[v.x+1][v.y] = 1;
        }
        if(v.y - 1 >= 0 && !vis[v.x][v.y-1] &&
           g[v.x][v.y-1] - g[v.x][v.y] <= 1){
            q.push(Cell{v.x, v.y-1, v.distance+1});
            vis[v.x][v.y-1] = 1;
        }
        if(v.y + 1 < g[0].size() && !vis[v.x][v.y+1] &&
           g[v.x][v.y+1] - g[v.x][v.y] <= 1){
            q.push(Cell{v.x, v.y+1, v.distance+1});
            vis[v.x][v.y+1] = 1;
        }
            for(auto r : vis){
                for(auto c : r){
                    std::cout << c;
                } std::cout << "\n";
            }std::cout << "\n"; 
    }
    return;
}

int main(){
    std::ifstream file("input");
    std::string line;
    std::vector<std::vector<char>> grid;

    while(std::getline(file, line)){
        std::vector<char> row;
        for(int c = 0; c < line.length(); c++){
            row.push_back(line[c]);
        }
        grid.push_back(row);
    }    
    std::vector<std::vector<bool>> visited;
    for(int r = 0; r < grid.size(); r++){
        std::vector<bool> row;
        for(int c = 0; c < grid[0].size(); c++){
            row.push_back(0);
        }
        visited.push_back(row);
    }
    Cell startNode;
    for(int r = 0; r < grid.size(); r++){
        for(int c = 0; c < grid[0].size(); c++){
            if ( grid[r][c] == 'S'){
                grid[r][c] = 'a' - 1;
                startNode = {r, c, 0};
            }
            if ( grid[r][c] == 'E'){
                grid[r][c] = 'z' + 1;
            }
        }
    }
    for(auto r : grid){
        for(auto c : r){
            std::cout << c;
        } std::cout << "\n";
    }
    BFS(grid, startNode, visited);
} 