#pragma once
class Game;
#include "Main.hpp"
#include "Deck.hpp"

class Game
{
public:
  Game(std::vector<std::string>& player_list);
  virtual ~Game();

  void play();
  void printCardStatment() const;
  void printPlayerStatment(GenericPlayer* player) const;
private:
  Deck* m_deck;
  House* m_dealer;
  std::vector<Player*> m_players;

};
