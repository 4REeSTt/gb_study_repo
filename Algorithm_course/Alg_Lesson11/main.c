#include <stdio.h>
#include <stdlib.h>

int key;
char massage[100];
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
    char* new_str = (char*)calloc(0,sizeof(char) * (get_size_of_str(str)));
    while(str[i] != '\0'){
        new_str[i] = str[i] + key;
        i++;
    }
    i = 0;
    return new_str;
}

char* decrypt(char* str){
    char* new_str = (char*)calloc(0,sizeof(char) * (get_size_of_str(str)));
    while(str[i] != '\0'){
        new_str[i] = str[i] - key;
        i++;
    }
    i = 0;
    return new_str;
}

//2.-------------------------------------------------------------------------------
typedef struct Key_str{
    char** string;
    int* key;
}Key_str;

void random_mix(int* arr){
    int k = rand()%100;
    for(int i = 0; i < k - 1; i++){
        int tmp;
        tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
    }
}

Key_str* col_change_encrypt(char* str){

    Key_str* package = (Key_str*)malloc(sizeof(Key_str));
    char** matrix = (char**)malloc(sizeof(char*) * key);
    char** matrix_tmp = (char**)malloc(sizeof(char*) * key);
    int size = get_size_of_str(str);

    for(int i = 0; i < key; i++){
        matrix[i] = (char*)malloc(sizeof(char)* (get_size_of_str(str)/key));
        matrix_tmp[i] = matrix[i];
    }
    package->string = matrix;
    package->key = (int*)malloc(sizeof(int)* key);
    for(int i = 0; i < key; i++)
        package->key[i] = i;

    for(int i = 0; i < key; i++){
        for(int j = 0; j < key; j++){
            if((j + i*key) >= size){
                matrix[i][j] = '/0';
            } 
            matrix[i][j] = str[j + i*key];
        }
    }
    exit:

    if(key <= 2)
        return NULL;

    random_mix(package->key);

    for(int i = 0; i < key; i++){
        matrix[i] = matrix_tmp[package->key[i]];
    }

    package->string = matrix;
    return package;
}

Key_str* col_change_decrypt(Key_str* package){
    char** tmp = (char**)malloc(sizeof(char*)* key);
    for(int i = 0; i < key; i++)
        tmp[i] = package->string[i];
    for(int i = 0; i < key; i++){
        for(int j = 0; j < key; j++){
            if(i == package->key[j]){
                package->string[i] = tmp[j];
            }
        }
    }
    return package;
}

void print_package_matrix(Key_str* package){
    for(int i = 0; i < key; i++){
        for(int j = 0; j < key; j++){
            printf("%c", package->string[i][j]);
        }
    }
}

int main(){
//1.-------------------------------------------------------------------------------

    printf("Enter key:\n> ");
    scanf("%d", &key);

    printf("Enter massage:\n> ");
    scanf("%s", &massage);

    printf("Encripting: %s\n", encrypt(massage));
    char* password;
    password = encrypt(massage);
    printf("Decripting: %s\n", decrypt(password));
     
    free(password);
//mem need to be freed after encrypt and decrypt dont use with printf btw
//2.-------------------------------------------------------------------------------
    
    Key_str* package = col_change_encrypt(massage);
    print_package_matrix(package);
    printf("\n");
    col_change_decrypt(package);
    print_package_matrix(package);





    return 0;
}
