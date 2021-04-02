
namespace Task5{

    //2.----------------------------------------------------------
    int tofeel_array(int * Array_task2, int length_of_arr){
        for (int i = 0; i < length_of_arr; i++){
            if (i == 0){
                Array_task2[i] = 1;
                continue;
            }
            Array_task2[i] = Array_task2[i - 1] + 3;
        }


        std::cout << "\n\nArray is: ";
        for(int i = 0;i < length_of_arr;i++){
            std::cout << Array_task2[i] << " ";
        }
        return 0;
    }
}
