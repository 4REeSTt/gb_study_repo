#pragma once
#include "GenericPlayer.hpp"

class House:public GenericPlayer
{
public:
  House();
  virtual ~House(){}

  virtual bool IsHitting() const;
  void FlipFirstCard();

private:
};
