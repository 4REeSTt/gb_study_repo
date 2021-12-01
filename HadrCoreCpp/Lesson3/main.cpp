#include <iostream>
#include <list>
#include <numeric>
#include <functional>

std::list<double> List;

void AddSumToList(std::list<double>& list){
    list.push_back(
		std::accumulate(list.begin(), list.end(), 0.0)
	);
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
	for(auto elem : List){
		std::cout << elem << "\n";
	}

    return 0;
}
