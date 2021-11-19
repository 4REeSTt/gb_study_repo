#include <iostream>
#include <vector>
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


std::string letters = {"аАяЯоОёЁеЕэЭиИуУыЫюЮ1"};

size_t CalcLetters(std::string word){
    size_t count = 0;
    count = std::count_if(word.begin(), word.end(), [&count](char character){
        if(std::find(letters.begin(), letters.end(), character) == letters.end()){
            std::cout << character << "\t";
            return true;
        }
        return false;
    });
    return count;
}



int main(){
    setlocale(LC_ALL, "Russian");

    std::string str{"Война и мир"};
    std::cout << CalcLetters(str) << "\n";


    return 0;
}
