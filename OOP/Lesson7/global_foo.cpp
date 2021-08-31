#include "include/Main.hpp"

bool secured_input()
{
	std::string answer;
	std::cin >> answer;
	
	if(answer[0] == 'Y' || answer[0] == 'y' || answer[0] == '1')
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, const Card::Rank& card)
{
    switch(card)
    {
        case Card::ACE:   return (out << "Ace");
        case Card::TWO:   return (out << "Two");
        case Card::THREE: return (out << "Three");
        case Card::FOUR:  return (out << "Four");
        case Card::FIVE:  return (out << "Five");
        case Card::SIX:   return (out << "Six");
        case Card::SEVEN: return (out << "Seven");
        case Card::EIGHT: return (out << "Eight");
        case Card::NINE:  return (out << "Nine");
        case Card::TEN:   return (out << "Ten");
        case Card::JACK:  return (out << "Jack");
        case Card::QUEEN: return (out << "Queen");
        case Card::KING:  return (out << "King");
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Card::Suit& card)
{
    switch(card)
    {
        case Card::DIAMONDS: return (out << "Diamonds"); 
        case Card::HEARTS:   return (out << "Hearts"); 
        case Card::CLUBS:    return (out << "Clubs"); 
        case Card::SPADES:   return (out << "Spades"); 

    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	if(card.GetFlip())
		return out << "[X X] ";
  
	return out << "[" << card.GetRank() << " " << card.GetSuit() << "]";
}