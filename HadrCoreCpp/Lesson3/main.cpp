#include <iostream>
#include <list>
#include <numeric>
#include <functional>
#include <cmath>

std::list<double> List;

void AddSumToList(std::list<double>& list){
    list.push_back(
		std::accumulate(list.begin(), list.end(), 0.0)
	);
}



void PrintMatrix(int** matrx, size_t size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cout << matrx[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

class Matrix{
private:
	size_t pSize;
    int** pMatrix;
	int pDef;
	
	
public:
	Matrix(int** matrix, size_t size)
	:pMatrix(matrix), pSize(size)
	{
		pDef = 0;
	}


	int** MinorCall(int** matrix, size_t size, int Currentcol){
		int** newMatrix = new int*[size -1 ];
		for(int i = 0; i < size -1; i++){
			newMatrix[i] = new int[size -1];
		}
		
		
		int colInNewMatrix = 0;	
		for(int i = 0; i < size; i++){
			if(i == Currentcol) continue;
			for(int j = 0; j < size -1; j++){
				newMatrix[colInNewMatrix][j] = matrix[i][j+1];
			}
			colInNewMatrix++;
		}
		PrintMatrix(newMatrix, size -1);
		return newMatrix;
	}
	
	int CalcDef(int** Matrix, size_t size){
		int def = 0;
		if(size == 1){ 
			int x = Matrix[0][0];
			return Matrix[0][0]; 
		}
		std::cout << "---------------------------------------------------------\n";
		
		for(int col = 0; col < size; col++)
			def += Matrix[0][col] * pow(-1, 2 + col) * CalcDef(MinorCall(Matrix, size, col), size -1);
			
		int a = def;
		std::cout << "---------------------------------------------------------\n";
		return def;
	}
	
	int GetDef(){return pDef;}
	int** GetMatrix(){return pMatrix;}
	size_t GetSize(){return pSize;}

};


int main(){
/* ///< Task 1 check

    List.push_back(20.2);
    List.push_back(30.3);
    List.push_back(40.4);
    List.push_back(50.5);

    AddSumToList(List);
	for(auto elem : List){
		std::cout << elem << "\n";
	}
*/

int** Mat;
Mat = new int*[3];
Mat[0] = new int[3];
Mat[1] = new int[3];
Mat[2] = new int[3];

for(int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
		Mat[i][j] = (i+1)*(j+1);
	}
}
//Mat[0][0] += 1;
PrintMatrix(Mat, 3);
	
Matrix matrix(Mat, 3);
PrintMatrix(matrix.GetMatrix(), matrix.GetSize());

std::cout << matrix.CalcDef(matrix.GetMatrix(), matrix.GetSize()) << "\n";


delete Mat[0];
delete Mat[0];
delete Mat[0];
delete Mat;

    return 0;
}
