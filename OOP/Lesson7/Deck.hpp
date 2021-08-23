#pragma once
#include <queue>
#include "Main.hpp"
#include "Game.hpp"

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
