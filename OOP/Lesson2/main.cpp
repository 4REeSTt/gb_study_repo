#include <iostream>

//1.----------------------------------------------------------------------
//Узнать как проходит присваивание при наследовании, при создании Студента должен создаваться Человек(Person)
//И ему присваиваться все данные Студенту которые были переданы
int student_counter = 0;

class Person{
    private:
        std::string name;
        bool gender;
        int weight;
        int age;    

    public:
        Person(std::string name, int age, bool gender, int weight)
        :name(name),age(age),gender(gender),weight(weight)
        {}

        void set_name(std::string name);
        void set_weight(int weight);
        void set_age(int age);
        void print_Person();

        std::string get_name();
};

class Student:public Person{
    private:
        int year_study = 0;
    public:
        Student(std::string name, int age, bool gender, int weight)
        :Person(name, age, gender, weight)
        {student_counter++;}

        void set_year(int value);
        void print_student();
};

//Functions----------------------------------------------------------
void Person::set_name(std::string name){
    this->name = name;
}
void Person::set_weight(int weight){
    this->weight = weight;
}
void Person::set_age(int age){
    this->age = age;
}
void Student::set_year(int value){
    year_study = value;
}
void Person::print_Person(){
    std::cout <<
        "Student Name: " << name << "\n" <<
        "Age: "  << age  << "\n" <<
        "Weight: " << weight << "\n";

}
std::string Person::get_name(){
    return name;
}
void Student::print_student(){
    print_Person();
    std::cout << "Years to study: " << year_study << "\n";
}

void find_student(Student** arr, std::string name){
    for(int i = 0; i < student_counter; i++){
        if(arr[i]->get_name() == name){
            arr[i]->print_student();          
            return;
        }
    }
    std::cout << "There is no such student\n";
}
//2.----------------------------------------------------------------------
class Fruit{
    private:
        std::string name;
        std::string color;
    public:
        Fruit(std::string name, std::string color)
        :name(name),color(color)
        {}

        std::string getName(){return name;}
        std::string getColor(){return color;}
};

class Apple:public Fruit{
    public:
        Apple(std::string color = "Green", std::string name = "Apple")
        :Fruit(name, color)
        {}
};
class Banana:public Fruit{
    public:
        Banana()
        :Fruit("Banana", "Yellow")
        {}
};
class GrannySmith:public Apple{
    public:
        GrannySmith()
        :Apple("Green","GrannySmith")
        {}
};



//3.----------------------------------------------------------------------
//Примерное разбиение
class Game{};
class Player{
    private:
        std::string name;
        int value;
        int bet = 0;
        int bank;
    public:
        void take_card();//когда игрок берет карту меняется value, в ручную поменять нельзя;
        int pass();
        void make_bet(int money);

        int get_value();
        std::string get_name();

        void reset_cards();
};

class Diler:public Player{
    private:
        int fliped_value;
    public:
        void flip_card();
        void get_silent_card();

        void startGame(Player** arr);
        void endGame(Player** arr);
};

class Card{
    int price;
    std::string name;
    
    public:
        void get_card();
};
class Deck:public Card{
};

int main(){
//1.----------------------------------------------------------------------
    Student* arr[20];
    Student Masha("Masha", 15, 0, 50);
    Student Dasha("Dasha", 20, 0, 100);
    Student Pasha("Pasha", 30, 0, 150);
    Student Sasha("Sasha", 40, 0, 200);

    arr[0] = &Masha;
    arr[1] = &Dasha;
    arr[2] = &Pasha;
    arr[3] = &Sasha;

    std::string input;
    std::cout << "Enter student(Masha, Dasha, Pasha, Sasha)\n> ";
    std::cin >> input;
    find_student(arr, input);

//2.----------------------------------------------------------------------
    std::cout << "\nTask2:\n";

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
