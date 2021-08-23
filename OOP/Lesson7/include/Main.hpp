#pragma once
#include <iostream>
#include <vector>

#include "Card.hpp"
#include "Hand.hpp"
#include "GenericPlayer.hpp"
#include "Player.hpp"
#include "House.hpp"
#include "Date.hpp"
#include "Game.hpp"
#include "Deck.hpp"


bool secured_input();
size_t compareDates(Date* date1, Date* date2);
void swapDates(Date* date1, Date* date2);
std::ostream& operator<<(std::ostream& out, const Card& card);


std::ostream& operator<<(std::ostream& out, const Card::Rank& card);
std::ostream& operator<<(std::ostream& out, const Card::Suit& card);
