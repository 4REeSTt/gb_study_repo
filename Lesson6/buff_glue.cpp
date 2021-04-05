#include <iostream>
#include <fstream>

 
std::string buff;

int main(){
   
//Считываем текст из первого файла, записываем в buff
    std::ifstream fin; 
    fin.open("textholder1.txt");
    if(!fin.is_open()){
        std::cerr << "Cant open the file" << std::endl;
    }
    std::string prebuff;
    while(fin >> prebuff){
        buff += prebuff;
        buff += " ";
    }

    fin.close();

//Считываем тескст их 2ого файла, записываем так же в buff(обьединяя)
    std::ifstream fin2; 
    fin2.open("textholder2.txt");
    if(!fin2.is_open()){
        std::cerr << "Cant open the file" << std::endl;
                        
    }
    while(fin2 >> prebuff){
          buff += prebuff;
          buff += " ";
                            
    }
    fin2.close();


//Записываем все в новый файл, в 1 строку.
    std::ofstream fout;
    fout.open("glued.txt");
    fout << buff;
    fout.close();
    return 0;
}
