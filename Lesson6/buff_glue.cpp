#include <iostream>
#include <fstream>

 
char buff[sizeof("textholder1.txt")];

int main(){
    
    std::ifstream fin; 
    fin.open("textholder1.txt");
    if(!fin.is_open()){
        std::cerr << "Cant open the file" << std::endl;
    }
    
        fin.getline(buff,30);
        std::cout << buff;
        fin.close();
    std::cout <<sizeof("textholder1.txt");
    return 0;
}
