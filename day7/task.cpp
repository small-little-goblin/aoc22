#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>


class Dir{
    public:
        int size;
        std::string name;
        Dir *parent;
        std::vector<Dir *> children;
        Dir(){
            this->size = 0;
        }
        void accDirSize(){
            int sum;
            for (auto child : children){
                child->accDirSize();
            }
            for (auto child: children){
                size += child->size;
            }
        }
        
        int task1(){
            static int totalSum = 0;
            if(this->size < 100000)
                totalSum += this->size;

            for (auto child : this->children){
                child->task1();
            }
            return totalSum;
        }

        int task2(int s){
            int rootSize = s;
            static int smallestPossileSize = 70000000;
            if((this->size + 70000000 - rootSize) > 30000000){
                if (this->size < smallestPossileSize){
                    smallestPossileSize = this->size;
                }
            }
            for (auto child : this->children){
                child->task2(rootSize);
            }
            return smallestPossileSize;
        }
};

int main(){
    std::ifstream file("input");  
    std::string cmd;
    Dir *currDir;
    Dir *root = new Dir();
    root->name = "/";
    root->parent = NULL;
    currDir = root;

    std::getline(file, cmd);
    while(std::getline(file, cmd)){
        if(cmd.substr(0,4) == "$ cd"){
            if(cmd.substr(5) == ".."){
                currDir = currDir->parent;
            }
            else {
                for (size_t i = 0; i < currDir->children.size(); i++)
                {
                    if(currDir->children[i]->name == cmd.substr(5)){
                       currDir = currDir->children[i];
                       break;
                    }
                }
                
            }
        }
        else if (cmd.substr(0,4) == "$ ls"){}
        else if (cmd.substr(0,3) == "dir"){
            Dir *newDir = new Dir();
            newDir->parent = currDir;
            newDir->name = cmd.substr(4);
            currDir->children.push_back(newDir);
        }
        else {
            currDir->size += stoi(cmd.substr(0, cmd.find(" ")));
        }
        std::cout << currDir->name << " " << currDir->size << " " << currDir->children.size() <<" \n"  ;
    }
    root->accDirSize();

    for(auto child : root->children){
        std::cout << child->name << " " << child->size << " " << child->children.size() <<" \n"  ;
    }

    std::cout << "Task 1: " << root->task1() << std::endl;
    std::cout << root->size << std::endl;
    std::cout << (70000000 - root->size) << std::endl;
    std::cout << "Task 2: " << root->task2(root->size) << std::endl;

    return 0;
}
