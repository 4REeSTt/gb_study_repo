#include <iostream>
#include <fstream>

 
char* buff;

int main(){
   
//Открываем файлы и в зависимости от их размера выделяем память
    std::ifstream fin; 
    fin.open("textholder1.txt");
    if(!fin.is_open()){
        std::cerr << "Cant open the file" << std::endl;
    }
    char* prebuff;
    fin.seekg(0, std::ios_base::end);
    size_t file1_size = fin.tellg();


//    std::ifstream fin2; 
//    fin2.open("textholder2.txt");
//    if(!fin2.is_open()){
//        std::cerr << "Cant open the file" << std::endl;
//                        
//    }
//    fin2.seekg(0, std::ios_base::end);
//    size_t file2_size = fin2.tellg();
//
//    buff = new char[file2_size + file1_size];
//    prebuff = new char[file1_size];

//Копирование данных из файла в буффер 
    fin.read(prebuff,file1_size);
    for(int i = 0; i < file1_size; i++){
        std::cout << prebuff[i];
    }
    


    //fin2.close();
    fin.close();
    delete[] prebuff;


//Записываем все в новый файл, в 1 строку.
    std::ofstream fout;
    fout.open("glued.txt");
    fout << buff;
    fout.close();
    delete[] buff;
    return 0;
}
