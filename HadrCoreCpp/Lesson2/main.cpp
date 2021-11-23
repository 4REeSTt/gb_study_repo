#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

template <class T>
void SwapPointers(T* item_1, T* item_2){
    T* tmp = item_1;
    item_1 = item_2;
    item_2 = tmp;
}

template <class T>
void SortPointers(std::vector<T*> vec){
    std::sort(vec.begin(), vec.end(), [](T* item_1, T* item_2){
        if(item_1 && item_2)
            return *item_1 < *item_2;
        else return false;
    });
}


std::string letters = {"aeiouyAEIOUY"};

size_t CalcLetters(std::string word){

    std::ifstream in("test.txt");
    in.seekg(0);

    size_t count = 0;
    if(!in.eof()){
        for(char a = in.get(); !in.eof();){
            for(int i = 0; i < letters.size() && !in.eof(); i++, a = in.get()){
                if( letters[i] == a) count++;
                continue;
            }
        }
    }
    return count;
}



int main(){

    std::string str{"Война и мир"};
    std::cout << CalcLetters(str) << "\n";


    return 0;
}