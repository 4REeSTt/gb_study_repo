#include <iostream>
#include <experimental/optional>
#include <ostream>
#include <utility>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <tuple>


struct Person{
    std::string lastName;
    std::string firstName;
    std::experimental::optional<std::string> patronymic;

    bool operator< (Person& other){
        if(patronymic && other.patronymic)
            return std::tie(lastName, firstName, patronymic) < std::tie(other.lastName, other.firstName, other.patronymic);
        return std::tie(lastName, firstName)  < std::tie(other.lastName, other.firstName);
    }
    bool operator== (Person& other){
        if(patronymic && other.patronymic)
            return std::tie(lastName, firstName, patronymic) == std::tie(other.lastName, other.firstName, other.patronymic);
        return std::tie(lastName, firstName)  == std::tie(other.lastName, other.firstName);
    }
};
//------------------------------------------------------------------------------------------------------------------------
#define ALIGN 10
std::string operator*(std::string str, int iter){ //для выравнивания текста при выводе
    for(int i = 0; i < iter; i++)
        str += " ";
    return str;
}

std::ostream& operator<<(std::ostream& out, const Person& person){
    std::string align = " ";
    if(person.patronymic.value() != "-")
        return out << ( align * (ALIGN - person.lastName.size())) + person.lastName << "\t" << ( align * (ALIGN - person.firstName.size())) + person.firstName << "\t" << ( align * (ALIGN - person.patronymic.value().size())) + person.patronymic.value_or("");
    return out << ( align * (ALIGN - person.lastName.size())) + person.lastName << "\t" << ( align * (ALIGN - person.firstName.size())) + person.firstName <<  "\t" << align * ALIGN;
}

//------------------------------------------------------------------------------------------------------------------------
struct PhoneNumber{
    int countryCode;
    int cityCode;
    std::string number;
     std::experimental::optional<int> aditionalNumber;

    bool operator< (PhoneNumber& other){
        if(aditionalNumber && other.aditionalNumber)
            return std::tie(countryCode, cityCode, number, aditionalNumber) < std::tie(other.countryCode, other.cityCode, other.number, other.aditionalNumber);
        return std::tie(countryCode, cityCode, number) < std::tie(other.countryCode, other.cityCode, other.number);
    }
    bool operator== (PhoneNumber& other){
        if(aditionalNumber && other.aditionalNumber)
            return std::tie(countryCode, cityCode, number, aditionalNumber) == std::tie(countryCode, cityCode, number, aditionalNumber);
        return std::tie(countryCode, cityCode, number) == std::tie(countryCode, cityCode, number);
    }
};
//------------------------------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const PhoneNumber& number){
    if(number.aditionalNumber && number.aditionalNumber.value() != 0)
        return out << "+" << + number.countryCode << "(" << number.cityCode << ")" << number.number <<  "  " << number.aditionalNumber.value();
    return out << "+" << number.countryCode << "(" << number.cityCode << ")" << number.number <<  "  " ;
}

//------------------------------------------------------------------------------------------------------------------------
std::string getWord(std::ifstream& in){
    std::string str;
    if(in.is_open() && !in.eof()){
        char a;
        while(!in.eof() && (a = in.get()) != ' ' && a != '\n' && a != '\t' && a != '\r')
            str += a;
        return str;
    }
    return str = "";
}

//------------------------------------------------------------------------------------------------------------------------

class PhoneBook{
    std::vector<std::pair<Person, PhoneNumber>> pPhoneBook;

public:
    //---------------------
    PhoneBook(std::ifstream& in){
        if(in.is_open()){
            char a;
            while(!in.eof()){
                int count = 0;
                std::pair<Person, PhoneNumber> pair;
                Person pers;
                PhoneNumber num;
                while(!in.eof()){
                        pers.lastName = getWord(in);
                        pers.firstName = getWord(in);
                        pers.patronymic = getWord(in);
                        num.countryCode = atoi(getWord(in).c_str());
                        num.cityCode = atoi(getWord(in).c_str());
                        num.number = getWord(in);
                        num.aditionalNumber = atoi(getWord(in).c_str());
                    pair.first = pers;
                    pair.second = num;
                    pPhoneBook.push_back(pair);
                    }
                }
            }
        else {std::cout << "Fail reading book\nQuiting!\n"; exit(-1);}
    }

    //---------------------
    std::vector<std::pair<Person, PhoneNumber>>& GetPhoneBook(){
        return pPhoneBook;
    };
    //---------------------
    void SortByName(){
        std::sort(pPhoneBook.begin(), pPhoneBook.end(), [](std::pair<Person, PhoneNumber>& item_1, std::pair<Person, PhoneNumber>& item_2){
            return item_1.first < item_2.first;
        });
    }
    //---------------------
    void SortByPhone(){
        std::sort(pPhoneBook.begin(), pPhoneBook.end(), [](std::pair<Person, PhoneNumber>& item_1, std::pair<Person, PhoneNumber>& item_2){
            return item_1.second < item_2.second;
        });
    }
    //---------------------
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string& lastName){
        int counter = 0;
        PhoneNumber num;
        for(auto record: pPhoneBook)
            if(lastName == record.first.lastName) {
                counter++;
                num = record.second;
            }

        switch(counter){
        case 0:  return std::make_tuple("not found", num);
        case 1:  return std::make_tuple("", num);
        default: return std::make_tuple("found more then 1", num);
        }
    }

    //---------------------
    void ChangePhoneNumber(const Person& person,  PhoneNumber newPhone){
        for(int i = 0; i < pPhoneBook.size(); i++)
            if((const_cast<Person&>(person)) == pPhoneBook[i].first)
                pPhoneBook[i].second = newPhone;
    }
};
//------------------------------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, PhoneBook& book){
    std::for_each(book.GetPhoneBook().begin(), book.GetPhoneBook().end(), [&](std::pair<Person, PhoneNumber>& record){
        out << record.first << "\t" << record.second << std::endl;
    });
    return out;
}
//------------------------------------------------------------------------------------------------------------------------



int main(){
    //------------------------------------------------------------------------------------------------------------------------
    std::ifstream file("PhoneBook.txt");
    PhoneBook book(file);
    std::cout << book;

    //------------------------------------------------------------------------------------------------------------------------
    std::cout << "------------SortByPhone-------------" << std::endl;
    book.SortByPhone();
    std::cout << book;

    //------------------------------------------------------------------------------------------------------------------------
    std::cout << "------------SortByName-------------" << std::endl;
    book.SortByName();
    std::cout << book;

    //------------------------------------------------------------------------------------------------------------------------
    std::cout << "------------GetPhoneNumber-------------" << std::endl;

    auto print_phone_number = [&book](const std::string& surname){
        std::cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);

        if(std::get<0>(answer).empty())
            std::cout << std::get<1>(answer);
        else
        std::cout << std::get<0>(answer);
        std::cout << std::endl;
    };

    print_phone_number("Ivanov");
    print_phone_number("Petrov ");

    //------------------------------------------------------------------------------------------------------------------------
    std::cout << "------------ChangePhoneNumber-------------" << std::endl;
    book.ChangePhoneNumber(Person{"Kotov", "Vasilii", "Eliseevich"},
            PhoneNumber{7,123,"15344458", std::experimental::nullopt});
    book.ChangePhoneNumber(Person{"Mironova", "Margarita", "Vladimirovna"},
            PhoneNumber{16,465,"9155448", 13});
    std::cout << book;






















    return 0;
}
