namespace Task5{
    //1.---//5.
    int rqur(int * Array, int length){
         if(length > -1){
             Array[length] ^= 1;
             rqur(Array, length - 1);
         }else{ return 0;}
         return 0;
    }
}

