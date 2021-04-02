namespace Task5{

    //4.---
    int Array_sideslide(int * Array, int length,int n){
        int tmp1, tmp2;
        if(n < 0){

            while (n != 0){
                for(int i = length - 1; i > -1; i--){
                    if (i == length - 1){
                        tmp1 = Array[i];
                        Array[i] = Array[0];
                        continue;
                    }
                    tmp2 = Array[i];
                    Array[i] = tmp1;
                    tmp1 = tmp2;
                }      
                n++;
            }
        }else{
            while(n != 0){
                for(int i = 0; i < length; i++){
                    if(i == 0){ 
                        tmp1 = Array[i];
                        Array[i] = Array[length - 1];
                        continue;
                    }
                    tmp2 = Array[i];
                    Array[i] = tmp1;
                    tmp1 = tmp2;
                }
                n--;
            }
        }

        for(int i = 0; i < length; i++){
            std::cout << " " << Array[i] << " ";
        }
        return 0;
    }
}
