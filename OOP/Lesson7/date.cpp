#include "Date.hpp"

Date::Date(size_t date, size_t month, size_t year)
:m_date(date), m_month(month), m_year(year)
{}

Date::Date(Date* today = nullptr)
{
    time_t now = time(0);
    struct tm* _tm = localtime(&now);
    this->today = new Date(_tm->tm_mday, _tm->tm_mon, _tm->tm_year+1900);
    date = new Date(this->today->m_date, this->today->m_month, this->today->m_year);

    std::cout << date << " " << today << std::endl;
}
Date::~Date()
{
    delete today;
    delete date;
}

std::ostream& Date::operator<<(std::ostream& out) const
{ 
    return out << m_date << ":" << m_month << ":" << m_year << std::endl;
}

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
