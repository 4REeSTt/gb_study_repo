namespace Task5{

    //3.---


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

//calculating both sides summs 
#define CALCULATE_RIGHT_AND_LEFT    \
     for(int i = 0; i < center_pointer; i++){\
        left_side_sum += Array[i];\
    }for(int i = center_pointer; i < length; i++){\
        right_side_sum += Array[i];\
    }


bool CheckBalance_update(int * Array, int length){
    int left_side_sum = 0,
        right_side_sum= 0,
        center_pointer= length/2,
        direction = 0;
    
      CALCULATE_RIGHT_AND_LEFT

    if(left_side_sum == right_side_sum) 
        return true;
    if(left_side_sum > right_side_sum)
        direction = -1;
    else 
        direction = 1;

    while(left_side_sum != right_side_sum and (center_pointer > 0 and center_pointer < length)){
        left_side_sum = 0;
        right_side_sum = 0;
        center_pointer += direction;

        CALCULATE_RIGHT_AND_LEFT

    }
    if(left_side_sum == right_side_sum) 
        return true;
    else
        return false;
}
