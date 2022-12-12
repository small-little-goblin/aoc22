// ugliest one so far :)
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

class  Monkey{
    public:
        std::vector<long> items;
        long totalInspections;
        std::string operation;
        long testDivision;
        long targetIfTrue;
        long targetIfFalse;

        Monkey(){
            totalInspections = 0;
        };
        ~Monkey(){};
};

int main(){
    long realInput;
    std::cin >> realInput;
    std::string fileName = realInput == 1 ? "input" : "testinput";
    std::ifstream file(fileName);
    std::string line;

    std::vector<Monkey *> monkeys;

    //fill Monkeys
    while(std::getline(file, line)){
        Monkey *monkeyD = new Monkey();
        monkeys.push_back(monkeyD);
        //get items
        std::getline(file, line);
        size_t start = 18;
        size_t end = 0;
        while((end = line.find(',', start)) != std::string::npos){
            monkeys.back()->items.push_back(stoi(line.substr(start, end - start)));
            start = end + 1;
        } 
        monkeys.back()->items.push_back(stoi(line.substr(start, start - end))); 
       //get operation
        getline(file, line);
        monkeys.back()->operation = line.substr(23);
        //get parameter for throwing the items
        getline(file, line);
        monkeys.back()->testDivision = stoi(line.substr(21));

        getline(file, line);
        monkeys.back()->targetIfTrue = stoi(line.substr(29));
        
        getline(file, line);
        monkeys.back()->targetIfFalse = stoi(line.substr(30));
        
        getline(file, line); 
    }

    //rounds

    //triple for loop lol q:^)
    int Modulo = 1;
    
    for (auto m : monkeys){
        Modulo *= m->testDivision;
    }
    for (long r = 0; r < 10000; r++){
        for(auto m : monkeys){
            for (auto i : m->items){
                char op = m->operation[0];
                long increase;
                if(m->operation.substr(2) == "old"){
                    increase = i;
                }
                else {
                    increase = stoi(m->operation.substr(2));
                }
                if(op == '+'){
                    i += increase;
                    i %= Modulo;
                }
                else if (op == '*'){
                    i *= increase;
                    i %= Modulo;
                }
                if((i % m->testDivision) == 0){
                    monkeys[m->targetIfTrue]->items.push_back(i);
                } else {
                    monkeys[m->targetIfFalse]->items.push_back(i);
                }
                m->totalInspections++;
            }
            m->items.clear();
        }
        if (r == 19){
            for(auto m : monkeys){
                std::cout << m->totalInspections << " ";
            }
        }
    }


    long monkeyBusiness[2] = {0, 0};

    for (auto m : monkeys){
        if (m->totalInspections > monkeyBusiness[0])
            monkeyBusiness[0] = m->totalInspections;
        if(monkeyBusiness[0] > monkeyBusiness[1]){
            long tmp = monkeyBusiness[1];
            monkeyBusiness[1] = monkeyBusiness[0];
            monkeyBusiness[0] = tmp;
        }
    }

    for(auto m : monkeys){
        std::cout << m->totalInspections << "\n";
    }

    std::cout << "Monkey Business: " << monkeyBusiness[0] * monkeyBusiness[1];
}
