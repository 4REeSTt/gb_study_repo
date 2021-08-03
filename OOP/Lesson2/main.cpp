#include <iostream>

//1.----------------------------------------------------------------------
//Узнать как проходит присваивание при наследовании, при создании Студента должен создаваться Человек(Person)
//И ему присваиваться все данные Студенту которые были переданы
int student_counter = 0;

class Person{
    public:
        std::string name;
        bool gender;
        int weight;
        int age;    

        Person(std::string name, int age, bool gender, int weight)
        :name(name),age(age),gender(gender),weight(weight)
        {}
        void set_name(std::string name);
        void set_weight(int weight);
        void set_age(int age);
        
};

class Student:Person{
    private:
        int year_study;
    public:
        Student(std::string name, int age, bool gender, int weight){
            student_counter++;
            Person::Person(name, age, gender, weight);
        }


        void set_year(int value);
        void print_student();
};

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
void Student::print_student(){
    std::cout <<
        "Student Name: " << name << "\n" <<
        "Age: "  << age  << "\n" <<
        "Weight: " << weight << "\n" <<
        "Years to study: " << year_study << "\n";
}
//2.----------------------------------------------------------------------
class Fruit{
    std::string name;
    std::string color;
};
class Apple:Fruit{};
class Banana:Fruit{};
class GrannySmith:Apple{};


//3.----------------------------------------------------------------------

int main(){
//1.----------------------------------------------------------------------
    Student Masha("Masha", 15, 0, 50);
    return 0;
}
