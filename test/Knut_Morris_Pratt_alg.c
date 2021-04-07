int KMP(char* text,char* keyword,int length, int len_key){
    int skip_checked = 0;
    for(int i = 0;i < length;i++){
        if(text[i] == keyword[0]){
            int j = 0;
            while(text[i] == keyword[j]){
                j++;
                i++;
                skip_checked = j;
                
                if(j == len_key ){
                    return i - j + 1;
                }
            }
        continue; 
        }
    }
    return 0;
}