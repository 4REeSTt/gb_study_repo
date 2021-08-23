#pragma once
#include "Hand.hpp"

class GenericPlayer:public Hand
{
public:
  GenericPlayer(std::string name, bool not_compuer = 0);
  virtual ~GenericPlayer(){}

  virtual bool IsHitting() const = 0;
  bool IsBoosted() const;
  void Bust() const;
  std::string GetName() const;
  
  bool GetHuman() const;

private:
  std::string m_name;
  bool m_NotComputer = 0;
  
};
