#pragma once
#include "GenericPlayer.hpp"

class Player:public GenericPlayer
{
public:
  Player(std::string name, bool not_compuer = 0);
  ~Player(){}

  virtual bool IsHitting() const;

  void Win()  const;
  void Lose() const;
  void Push() const;
  
private:

};
