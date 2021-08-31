#pragma once
#include <iostream>
#include <vector>

#include "Card.hpp"
#include "Hand.hpp"
#include "GenericPlayer.hpp"
#include "Player.hpp"
#include "House.hpp"
#include "Game.hpp"
#include "Deck.hpp"


bool secured_input();
std::ostream& operator<<(std::ostream& out, const Card& card);


std::ostream& operator<<(std::ostream& out, const Card::Rank& card);
std::ostream& operator<<(std::ostream& out, const Card::Suit& card);
