#include <iostream>
#define PI 3.14

//1.--------------------------------------------------------
class Figure
{
public:
    double virtual area() = 0;
};

class Parallelogram:public Figure
{
private:
    double height;
    double side;
public:
    double area()
    {
        return height*side;
    }
};

class Circle:public Figure
{
private:
    double radius;
public:
    double area()
    {
        return PI*(radius*radius);
    }
};

class Rectangle:public Figure
{
private:
    double height;
    double width;
public:
    double area()
    {
        return height*width;
    }
};

class Square:public Figure
{
private:
    double side;
public:
    double area()
    {
        return side*side;
    }
};

class Rhombus:public Figure
{
private:
    double diagonal_1;
    double diagonal_2;
public:
    double area()
    {
        return diagonal_1 * diagonal_2 / 2;
    }
};

//2.--------------------------------------------------------
class Car
{
private:
    std::string company;
    std::string model;
public:
    Car(std::string company = "Trash", std::string model = "OKA")
    :company(company), model(model)
    {
        std::cout << "Car~\n";
    }
};

class PassangerCar:virtual public Car
{
public:
    PassangerCar()
    :Car()
    {
        std::cout << "PassangerCar~\n";
    }
};

class Bus:virtual public Car
{
public:
    Bus()
    :Car()
    {
        std::cout << "Bus~\n";
    }
};

class Minivan:public PassangerCar,public Bus
{
public:
    Minivan()
    :PassangerCar()
    {
        std::cout << "Minivan~\n";
    }
};
//3.--------------------------------------------------------
class Fraction
{
private:
    int numerator;
    int denominator;
public:
    void print_f()
    {
        std::cout << numerator << "/" << denominator;
    }
    int get_num(){return numerator;}
    int get_den(){return denominator;}

    Fraction(int numerator, int denominator)
    :numerator(numerator), denominator(denominator)
    {
        if(denominator == 0){
            std::cout << "Denominator Can't be 0\n";
            exit(0);
        }
        for(int i = 2; i < 10; i++){
            if(((numerator % i) == 0) && ((denominator % i) == 0)){
                numerator /= i;
                denominator /= i;
                this->numerator = numerator;
                this->denominator = denominator;
            }
        }
    }

    Fraction operator+(Fraction &other)
    {
        return Fraction((numerator* other.get_den()) + (other.get_num()* denominator),(denominator * other.get_den()));
    }

    Fraction operator-(Fraction &other)
    {
            return Fraction(((get_num()* other.get_den()) - (other.get_num()* get_den())),(get_den() * other.get_den()));
    }

    Fraction operator*( Fraction &other)
    {
        return Fraction((get_num() * other.get_num()),(get_den() * other.get_den()));
    }

    Fraction operator/(Fraction &other)
    {
        return Fraction((get_num() * other.get_den()),(get_den() * other.get_num()));
    }

    Fraction operator-()
    {
        return Fraction(get_num() * -1, get_den());
    }

    bool operator==(Fraction &other)
    {
        if(((double)get_num()/get_den()) == ((double)other.get_num()/other.get_den()))
            return true;
        return false;
    }

    bool operator!=(Fraction &other)
    {
        if(((double)get_num()/get_den()) != ((double)other.get_num()/other.get_den()))
            return true;
        return false;
    }

    bool operator>(Fraction &other)
    {
        if(((double)get_num()/get_den()) > ((double)other.get_num()/other.get_den()))
            return true;
        return false;
    }

    bool operator<(Fraction &other)
    {
        if(other > (*this))
            return true;
        return false;
    }

    bool operator>=(Fraction &other)
    {
        if(((double)get_num()/get_den()) >= ((double)other.get_num()/other.get_den()))
            return true;
        return false;
    }

    bool operator<=(Fraction &other)
    {
        if(other >= (*this))
            return true;
        return false;
    }
};

//4.--------------------------------------------------------------------------------------
enum Suit{
    Diamonds,
    Hearts,
    Clubs,
    Spades
};
enum CardName{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine, 
    Ten,
    Jack,
    Queen,
    King,
    
};
class Card
{
    Suit suit;
    CardName name;
    bool placement;
public:
    Card(CardName name)
    :name(name)
    {} 

    void Flip();
    int GetValue();
    void printCard();
};

void Card::Flip()
{
    if(placement)
        placement = 0;
    else
        placement = 1;
}

int Card::GetValue()
{
    if((name == Jack) || (name == Queen) || (name == King))
        return 11;
    else
        return name;
}

void Card::printCard()
{
    std::cout << GetValue() << "\n";
}
int main()
{
//2.--------------------------------------------------------
    Car car;
    std::cout << "\n";
    Bus bus;
    std::cout << "\n";
    PassangerCar pas;
    std::cout << "\n";
    Minivan mini;
//3.--------------------------------------------------------
    std::cout << "\n";
    Fraction a(3,7);
    Fraction b(9,2);
    Fraction c = a + b;
    std::cout << "Task3: \n";
    a.print_f();
    std::cout << " + ";
    b.print_f();
    std::cout << " = ";
    c.print_f();
    std::cout << "\n";

    a.print_f();
    std::cout << " - ";
    b.print_f();
    std::cout << " = ";
    c = a - b;
    c.print_f();
    std::cout << "\n";

    a.print_f();
    std::cout << " * ";
    b.print_f();
    std::cout << " = ";
    c = a * b;
    c.print_f();
    std::cout << "\n";

    a.print_f();
    std::cout << " / ";
    b.print_f();
    std::cout << " = ";
    c = a / b;
    c.print_f();
    std::cout << "\n";

    a.print_f();
    std::cout << " *- 1 = ";
    c = -a;
    c.print_f();
    std::cout << "\n";

    a.print_f();
    std::cout << " < ";
    b.print_f();
    std::cout << " = ";
    if(a < b)
        std::cout << "true";
    else
        std::cout << "fasle";
    std::cout << "\n";

    a.print_f();
    std::cout << " >= ";
    b.print_f();
    std::cout << " = ";
    if(a >= b)
        std::cout << "true";
    else
        std::cout << "fasle";
    std::cout << "\n";

//4.--------------------------------------------------------
    std::cout << "Task4: \n";
    
    Card jack(Jack);
    jack.printCard();

    

    return 0;
}
