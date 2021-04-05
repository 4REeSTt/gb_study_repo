#include <iostream>
#include <fstream>

int main(){
    std::string keyword;
    std::cout << "Enter any word to find \n";

    std::cin >> keyword;

    std::string filename;
    std::cout << "Enter name of file\n";
    std::cin >> filename;
    
    std::ifstream fin;
    fin.open(filename);
    if(!fin.is_open()){
        std::cerr << "There is no such file\n";
    }
    
    std::string key_finder;

    while(fin >> key_finder){
        if(key_finder == keyword){
            std::cout << "Your word does exist \n";
            fin.close();
            return 0;
        }
    }
    std::cout << "There is no such word \n";
    fin.close();
    return 0; 
    
}
