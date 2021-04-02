#include <iostream>
#include <iostream>


union difetent_types{
    int integer;
    char character;
    float floater;
};

struct type_ident{
    difetent_types value;
    int is_int  :1;
    int is_char :1;
    int is_float:1;

};
int main(){
    type_ident inte;
    inte.value = 15;
    inte.is_int = 1;
    inte.is_char = 0;
    inte.is_float = 0;
    return 0;
}
