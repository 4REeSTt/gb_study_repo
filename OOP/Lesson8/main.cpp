#include <iostream>

//1.-----------------------------------------------------
template<class T>
T div(T& value1 , T& value2){
    if((int)value2 == 0)
        throw 0;
    return value1/value2;
}
//2.-----------------------------------------------------
class Ex{
public:
    Ex(double x)
    :x(x)
    {}
    double GetX(){return x;}
private:
    double x;
};

class Bar{
public:
    void set(double a){
        if(a + y > 100){
            throw Ex(a*y);
        }else{
            y = a;
        }
    }
private:
    double y = 0;
};
//3.-----------------------------------------------------
class IlligalCommand{
public:
    IlligalCommand(int curr_x, int curr_y, int direct_x, int direct_y)
    :m_curr_x(curr_x), m_curr_y(curr_y), m_direct_x(direct_x), m_direct_y(direct_y)
    {}

    int GetCurX(){ return m_curr_x; }
    int GetDirX(){ return m_direct_x; }
    int GetCurY(){ return m_curr_y; }
    int GetDirY(){ return m_direct_y; }
private:
    int m_curr_x;
    int m_curr_y;
    int m_direct_x;
    int m_direct_y;
};
class OffTheField{
public:
    OffTheField(int curr_x, int curr_y, int direct_x, int direct_y)
    :m_curr_x(curr_x), m_curr_y(curr_y), m_direct_x(direct_x), m_direct_y(direct_y)
    {}
    int GetCurX(){ return m_curr_x; }
    int GetDirX(){ return m_direct_x; }
    int GetCurY(){ return m_curr_y; }
    int GetDirY(){ return m_direct_y; }
private:
    int m_curr_x;
    int m_curr_y;
    int m_direct_x;
    int m_direct_y;
};
class Robot{
public:
    void move(int x, int y){
        if(x < -1 || x > 1 || y < -1 || y > 1)
            throw IlligalCommand(m_x, m_y, x, y);
        if((x + m_x) < 0 || (x + m_x) > 9 || (y + m_y) < 0 || (y + m_y) > 9)
            throw OffTheField(m_x, m_y, x, y);
        m_x += x;
        m_y += y;
    }
    int GetX(){ return m_x; }
    int GetY(){ return m_y; }
private:
    int m_x = 0;
    int m_y = 0;
};

int main(){
//1.-----------------------------------------------------
    int a{15};
    int b{0};

    try{
        std::cout << div<int>(a,b) << "\n";
    }
    catch(...){
        std::cout << "Devision by 0\n";
    }
//2.-----------------------------------------------------
    double n = -1;
    Bar bar;
    std::cout << "Task2:  Enter number(0 to exit)\n> ";
    while(n){
        std::cin >> n;
        try{
            bar.set(n);
        }
        catch(Ex ex){
            std::cout << "Expression x = "<< ex.GetX() << std::endl; 
        }
    }
//3.-----------------------------------------------------
    int dirX;
    int dirY;
    Robot robot;

    while(true){
        std::cout << "Enter X\n> ";
        std::cin >> dirX;
        std::cout << "Enter Y\n> ";
        std::cin >> dirY;
        std::system("clear");
        try{
           robot.move(dirX, dirY); 
        }
        catch(IlligalCommand illig){ 
            std::cout << "ERROR: Illigal comand\n" << "Robot can move only 1 block forward or backward\n" << "Direction for X = " << illig.GetDirX() << "\nDirection for Y = " << illig.GetDirY() << std::endl; 
        }
        catch(OffTheField off){
            std::cout << "ERROR: Robot can't go off the field\n" << "Current position (" << off.GetCurX() << ", " << off.GetCurY() << ")\n" << "Direction for X = " << off.GetDirX()<< "\nDirection for Y = " << off.GetDirY() << std::endl; 
        }
        
        for(int x = 0; x < 10; x++){
            for(int y = 0; y < 10; y++){
                if(x == robot.GetX() && y == robot.GetY())
                    std::cout << " R ";
                else
                    std::cout << " . ";
            }
            std::cout << '\n';
        }
        std::cout << "\n\n";
    }
    return 0;
}
