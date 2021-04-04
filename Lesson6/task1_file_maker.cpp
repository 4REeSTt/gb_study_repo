#include <iostream>
#include <fstream>

int main(){
    std::ofstream fout; 
    fout.open ((char*) "textholder1.txt");

    for(int i = 0;i < 30;i++){
        fout << "print some text" << std::endl;
    }
    fout.close();

    std::ofstream fout2;
    fout.open ((char*) "textholder2.txt", std::ios_base::ate);

    for(int i = 0;i < 30;i++){
        fout << "print new text" << std::endl;
    }
    fout2.close();
    
    return 0;
}
