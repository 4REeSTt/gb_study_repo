#include <iostream>
#include <vector>
#include "class.h"

//1.--------------------------------------------------------------------
template <class T>
class Pair1
{
private:
    T value1;
    T value2;
public:
    Pair1(T value1, T value2)
    :value1(value1), value2(value2)
    {}

    T first() const {return value1;}
    T second() const {return value2;}
};


//2.--------------------------------------------------------------------
template <class T1, class T2>
class Pair
{
private:
    T1 value1;
    T2 value2;
public:
    Pair(T1 value1, T2 value2)
    :value1(value1), value2(value2)
    {}

    T1 first() const {return value1;}
    T2 second() const {return value2;}
};

//3.--------------------------------------------------------------------
template <class T3>
class StringValuePair:public Pair<std::string, T3>
{
public:
    StringValuePair(std::string name, T3 value)
    :Pair<std::string, T3>(name, value)
    {}
};
//4.--------------------------------------------------------------------
class GenericPlayer:public Hand
{
private:
    std::string name;
public:
    virtual IsHitting() = 0;
    bool IsBoosted();
    void Bust();
};


bool GenericPlayer::IsBoosted()
{
    if(this->GiveValue() > 21)
        return true;
    return false;
}

void GenericPlayer::Bust()
{
    std::cout << name << " Your hand has overflow\n";
}

int main()
{
//1.--------------------------------------------------------------------
    Pair1<int> p11(6, 9);
    std::cout << "Pair: " << p11.first() << ' ' << p11.second() << '\n';

    const Pair1<double> p21(3.4, 7.8);
    std::cout << "Pair: " << p21.first() << ' ' << p21.second() << '\n';

//2.--------------------------------------------------------------------
    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
//3.--------------------------------------------------------------------

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
