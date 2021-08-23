#pragma once
#include <random>
#include <queue>
class Deck;
#include "Main.hpp"


class Deck:public Hand
{
public:
  Deck();
  virtual ~Deck();

  void Populate();
  void Shuffle();
  void Deal(Hand& aHand);
  void AdditionalCards(GenericPlayer& aGenericPlayer, Game& current);
  

private:
  std::deque<Card*> m_deck;

};
