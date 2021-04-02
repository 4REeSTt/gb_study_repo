namespace Task5{

    //3.---
    //Функцию можно оптимизировать, если сделать расчет от центра и в зависимости от разности сторон двигаться в сторону с
    //меньшей суммой. center_sum_pointer = length/2; не получается адекватно реализовать пока что, воможно позже вернусь,
    //упираюсь в зацикливаемость, либо слишком большое количество условных операторов выходит. Работать в таком случае
    //функция будет быстрее

    bool checkBalance(int * Array, int length){
        int leftside = 0,rightside = 0, center_sum_pointer;
        center_sum_pointer = 1; 

        while(center_sum_pointer < length){
            for(int i = 0; i < center_sum_pointer;i++){
                leftside += Array[i];
            }for (int j = center_sum_pointer;j < length; j++){
                rightside += Array[j];
            }
            
            if( leftside == rightside){
                return true;
            }
            leftside = 0; rightside = 0;
            center_sum_pointer++;
        }
        return false;
    }
}
