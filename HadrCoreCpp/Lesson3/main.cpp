#include <iostream>
#include <list>

std::list<double> List;

void AddSumToList(std::list<double>& list){
    double tmp = 0;
    for(auto item: list){
        tmp += item;
    }
    list.push_back(tmp);
}


class Matrix{
    int** matrix;

};

int main(){
    List.push_back(20.2);
    List.push_back(30.3);
    List.push_back(40.4);
    List.push_back(50.5);

    AddSumToList(List);


    return 0;
}
