#include <iostream>
#include <cmath>
#include <cstdint>

//1.------------------------------------------------------
class Power{
    private:
        int a;
        int b;
    public:
        Power()
        :a(3),b(4)
        {}

        void SetNums(int val1, int val2){
            a = val1;
            b = val2;
        }

        int calculate(){
            return pow(a, b);
        }
};

//2.------------------------------------------------------
class RGBA{
    private:
        uint8_t m_red   = 0;
        uint8_t m_blue  = 0;
        uint8_t m_green = 0;
        uint8_t m_alpha = 255;;
    public:
        RGBA(){}
        RGBA(uint8_t m_alpha, uint8_t m_green, uint8_t m_blue, uint8_t m_red)
        :m_red(m_red),m_blue(m_blue),m_green(m_green),m_alpha(m_alpha)
        {}
        void print(){
            std::cout << 
                "Red:\t"   << (int)m_red   << "\n" <<
                "Green:\t" << (int)m_green << "\n" <<
                "Blue:\t"  << (int)m_blue  << "\n" <<
                "Alpha:\t" << (int)m_alpha << std::endl;
        }
};

//3.------------------------------------------------------

const size_t size = 10;

class Stack{
    private:
        int array[size]{0};
        int top = -1;
    public:
        void reset();
        bool push(int value);
        int  pop();
        void print();
};

//Funcs-----------------------------
void Stack::reset(){
    for(int i = 0; i < size; i++)
        array[i] = 0;
    top = -1;
}
bool Stack::push(int value){
    if((top >= size) and (top != -1)){
        std::cout << "Stack is full\n" << "top = " << top << "\n";
        return false;
    }
    array[++top] = value;
    return true;
}
int Stack::pop(){
    if(top == -1){
        std::cout << "Array is empty\n";
        return 0;
    }
    return array[top--];
}
void Stack::print(){
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}


int main(){

//1.------------------------------------------------------
    Power power;
    power.SetNums(2,3);
    std::cout << "Tast1: "<< power.calculate() << std::endl << std::endl;
//2.------------------------------------------------------
    std::cout << "Tast2:"  << "\n";
    RGBA light(192,168,0,151);
    light.print();
//3.------------------------------------------------------
    std::cout << "\nTast3:"  << "\n";
    Stack stack1;
    stack1.push(15);
    stack1.push(15);
    stack1.push(13);
    stack1.print();

    std::cout << "Pop: " << stack1.pop() << "\n";

    std::cout << "Reset: " << "\n";
    stack1.reset();
    stack1.print();

    return 0;
}
