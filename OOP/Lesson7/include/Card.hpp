#pragma once
#include <iostream>

class Card
{
public:
  enum Suit{
	DIAMONDS, HEARTS, CLUBS, SPADES
  };
  enum Rank{
	ACE = 1,
	TWO, THREE, FOUR,  FIVE, 
	SIX, SEVEN, EIGHT, NINE, 
	TEN, JACK,  QUEEN, KING
  };

  Card(Rank rank, Suit suit, bool IsFliped = 0);
  virtual ~Card(){}

  void Flip();
  int GetValue() const;
  
  Rank GetRank() const;
  Suit GetSuit() const;
  bool GetFlip() const;

private:

  Suit m_suit;
  Rank m_rank;
  bool m_IsFliped;
};