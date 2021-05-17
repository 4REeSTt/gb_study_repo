#include <iostream>
//1.-----------------------------------------------------------------------------------------------------
#define CHECK_DIAPOSON(number,folow_num) ((number >= 0)&&(number < folow_num))?true:false
//2.-----------------------------------------------------------------------------------------------------
#define ARRAY_ELEMENT(Array,i,j) (*(*(Array + i) + j))
//3.-----------------------------------------------------------------------------------------------------
#define ARR_SIZE(index,type) sizeof(index)/sizeof(type)


int main(){
    
    //1.
    std::cout << (CHECK_DIAPOSON(5,10)) << std::endl;

    //2.
    int ** Arr_dinamic,
        N = 5,
        M = 5;

    Arr_dinamic = new int*[N];
	Arr_dinamic[0] = new int[M*N];
	for(int i{0}; i < N; i++){
		Arr_dinamic[i] = Arr_dinamic[0] + M*i;
	}
	
    Arr_dinamic[2][2] = 33;
    std::cout << ARRAY_ELEMENT(Arr_dinamic, 2,2) << '\n';

	delete[] Arr_dinamic[0];
	delete[] Arr_dinamic;

    //3.
    int Array[10] = {0};
    std::cout << ARR_SIZE(Array,int);
    return 0;
}
