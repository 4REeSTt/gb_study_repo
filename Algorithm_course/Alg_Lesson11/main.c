#include <stdio.h>
#include <stdlib.h>

int key = 5;
char massage[100] = "Hello today iam good";
int i = 0;


int get_size_of_str(char* str){
    int size = 0;
    while(str[size] != '\0'){
        size++;
    }
    return size;
}

//1.-------------------------------------------------------------------------------

char* encrypt(char* str){
    char* new_str = (char*)malloc(sizeof(char) * (get_size_of_str(str)+1));
    while(str[i] != '\0'){
        new_str[i] = str[i] + key;
        i++;
    }
    new_str[i+1] = '\0';
    i = 0;
    return new_str;
}

char* decrypt(char* str){
    char* new_str = (char*)malloc(sizeof(char) * (get_size_of_str(str)+1));
    while(str[i] != '\0'){
        new_str[i] = str[i] - key;
        i++;
    }
    new_str[i+1] = '\0';
    i = 0;
    return new_str;
}

//2.-------------------------------------------------------------------------------
typedef struct Key_str{
    char* string;
    int* key;
}Key_str;

Key_str* col_change_encrypt(char* str){

    Key_str* package = (Key_str*)malloc(sizeof(Key_str));
    int size = get_size_of_str(str);
    int col_size;
    if(size%key != 0)
        col_size = (size/key)+1;
    else
        col_size = size/key;

    package->string = (char*)malloc(sizeof(char) * col_size * key + 1);
    package->string[col_size*key] = '\0';

    package->key = (int*)malloc(sizeof(int)*key);
    char** matrix = (char**)malloc(sizeof(char*) * key);
    char** matrix_tmp = (char**)malloc(sizeof(char*) * key);

    for(int i = 0; i < key; i++){
        matrix[i] = (char*)malloc(sizeof(char)*col_size);
        matrix_tmp[i] = matrix[i];
    }

    for(int i = 0; i < key; i++){
        for(int j = 0; j < col_size; j++){
            if((j +i*col_size) >= size){
                matrix[i][j] = 'x';
            }else{
                matrix[i][j] = str[j + i*col_size];
            }
        }
    }
    for(int i = 0; i < key; i++)
        package->key[i] = i;

    for(int i = 0; i < key -1; i++){
        int tmp;
        tmp = package->key[i];
        package->key[i] = package->key[i+1];
        package->key[i+1] = tmp;
    }

    
    for(int i = 0; i < key; i++){
        for(int j = 0; j < key; j++){
           if(i == package->key[j])
                matrix[i] = matrix_tmp[j];
        }
     }
    
    int l = 0;
    for(int j = 0; j < col_size; j++){
        for(int i = 0; i < key; i++){
           package->string[l] = matrix[i][j];
           l++;
        }
    }
    
    free(matrix_tmp);
    for(int i = 0; i < key; i++)
        free(matrix[i]);
    free(matrix);
    


    return package; 
}

char* col_change_decrypt(Key_str* package){

    int size = get_size_of_str(package->string);
    int col_size = size/key;
    int l = 0;
    char* string = (char*)malloc(sizeof(char)* size);
    string[size-1] = '\0';
    char** matrix2 = (char**)malloc(sizeof(char*) * key);
    for(int i = 0; i < key; i++){
        matrix2[i] = (char*)malloc(sizeof(char)*col_size);
    }
    char** matrix_tmp2 = (char**)malloc(sizeof(char*) * key);
    
    for(int i = 0; i < col_size; i++){
        for(int j = 0; j < key; j++){
            matrix2[j][i] = package->string[l];
            l++;
        }
    }
    for(int i = 0; i < key; i++)
            matrix_tmp2[i] = matrix2[i];

    for(int i = 0; i < key; i++){
        for(int j = 0; j < key; j++){
            if(i == package->key[j]){
                matrix2[j] = matrix_tmp2[i];
            }
        }
    }
    l = 0;
    for(int i = 0; i < key; i++){
        for(int j = 0; j < col_size; j++){
            string[l] = matrix2[i][j];
            l++;
        }
    }
    string[l] = '\0';

    
    free(matrix_tmp2);
//    for(int i = 0; i < key; i++)
//        free(matrix2[i]);
//    free(matrix2);

    for(int i = size-1; i > 0; i--){
        if(string[i] == 'x')
            string[i] = '\0';
        else
            return string;
    }

    return string;
}


int main(){
//1.-------------------------------------------------------------------------------

    printf("\nKey: %d\n", key);

    char* encrypted = encrypt(massage);
    char* decrypted = decrypt(encrypted);

    printf("Encripting: %s\n", encrypted);
    printf("Decripting: %s\n", decrypted);
     
    free(encrypted);
    free(decrypted);
//mem need to be freed after encrypt and decrypt dont use with printf btw
//2.-------------------------------------------------------------------------------
    
    Key_str* package = col_change_encrypt(massage);
    printf("\nEncrypted with col change: ");
    printf("%s", package->string);
    char* decrypted_col_str = col_change_decrypt(package);
    printf("\nDectypted with col change: ");
    printf("%s\n", decrypted_col_str);

    free(decrypted_col_str);
    free(package->string);
    free(package->key);
    free(package);



    return 0;
}
