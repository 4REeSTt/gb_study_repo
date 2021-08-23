#pragma once
#include "Hand.hpp"

class GenericPlayer:public Hand
{
public:
  GenericPlayer(std::string name);
  virtual ~GenericPlayer(){}

  virtual bool IsHitting() const = 0;
  bool IsBoosted();
  void Bust();
  std::string GetName() const;

private:
  std::string m_name;
  
};
