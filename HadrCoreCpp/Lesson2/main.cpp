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

size_t CalcLetters(std::string letters){

    std::ifstream in("war.txt");
    in.seekg(0);

    size_t count = 0;
    if(!in.eof()){
        for(char a; !in.eof();){
                a = in.get();
            for(int i = 0; i < letters.size() && !in.eof(); i++){
                if( letters[i] == a) count++;
            }
        }
    }
    return count;
}



int main(){
    std::cout << CalcLetters(letters) << "\n";


    return 0;
}
