#pragma once
#include <iostream>
#include <ctime>

class Date
{
public:
  Date(Date* today);
  Date(size_t date, size_t month, size_t year);
  virtual ~Date();


  Date& compareDates(Date& other);
  std::ostream& operator<<(std::ostream& out) const;
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
  
  Date* today = nullptr;
  Date* date  = nullptr;
};
