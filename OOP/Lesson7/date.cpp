#include <iostream>
#include <memory>
#include <ctime>

class Date
{
public:
  Date(){}
  Date(size_t date, size_t month, size_t year);
  virtual ~Date(){}


  Date& compareDates(Date& other);
  void swapDates(Date& other);

  size_t GetDate()  const;
  size_t GetMonth() const;
  size_t GetYear()  const;

  void SetDate( size_t date );
  void SetMonth(size_t month);
  void SetYear( size_t year );

private:
  size_t m_date;
  size_t m_month;
  size_t m_year;
};

Date::Date(size_t date, size_t month, size_t year)
:m_date(date), m_month(month), m_year(year)
{}

Date& Date::compareDates(Date& other)
{
    return (m_date > other.m_date)? *this : other;
}


size_t Date::GetDate() const
{
    return m_date;
}

size_t Date::GetMonth() const
{
    return m_month;
}

size_t Date::GetYear() const
{
    return m_year;
}

void Date::SetDate(size_t date)
{
    m_date = date;
}

void Date::SetMonth(size_t month)
{
    m_month = month;
}

void Date::SetYear(size_t year)
{
    m_year = year;
}
std::ostream& operator<<(std::ostream& out, Date& date_ptr){
    return out << date_ptr.GetDate() << ":" << date_ptr.GetMonth() << ":" << date_ptr.GetYear() << std::endl;
}
std::ostream& operator<<(std::ostream& out, std::unique_ptr<Date> date_ptr){
    return out << date_ptr->GetDate() << ":" << date_ptr->GetMonth() << ":" << date_ptr->GetYear() << std::endl;
}

//2.----------------------------------------------------------------------------
std::unique_ptr<Date>& CompareDates(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2){
    return (date1->GetDate() > date2->GetDate())? date1 : date2;
}
void SwapDates(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2){
    size_t tmp_date = date1->GetDate();
    date1->SetDate(date2->GetDate());
    date2->SetDate(tmp_date);
} 

int main(){
//1.----------------------------------------------------------------------------
    std::unique_ptr<Date> today(new Date(31,8,2021));
    std::unique_ptr<Date> date;
    std::cout << *today;
    date = std::move(today);

    if(date == nullptr){
        std::cout << "date is NULL\n";
    }
    if(today == nullptr){
        std::cout << "today is NULL\n";
    }
//2.----------------------------------------------------------------------------
    std::unique_ptr<Date> date1(new Date(24,12,2020));
    std::unique_ptr<Date> date2(new Date(28,12,2020));

    std::cout << *CompareDates(date1, date2) << std::endl;
    std::cout << *date1 <<  *date2 << std::endl;
    SwapDates(date1,date2);
    std::cout << *date1 <<  *date2 << std::endl;


    return 0;
}
