#pragma once
#include <vector>
#include "Card.hpp"

class Hand
{
public:
  Hand(){}
  virtual ~Hand();

  void Add(Card* card);
  void FlipFirst();
  void Clear();
  
  int GetSize() const;
  Card& GetCard(int idx) const;

  int GiveValue() const;
private:
  std::vector<Card*> m_collection;
};
