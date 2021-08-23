#include "Main.hpp"

int secured_input()
{
    int value;
    std::cout << "Please enter the value\n> ";
    while(!(std::cin >> value) || (std::cin.peek() != 10))
    {
        std::cout << "Please enter the value\n> ";
        std::cin.clear();
        std::cin.sync();
    }
    return value;
}

void swapDates(Date* date1, Date* date2)
{
    size_t tmp = date1->GetDate();
    date1->SetDate(date2->GetDate());
    date2->SetDate(tmp);
}

size_t compareDates(Date* date1, Date* date2)
{
    return (date1->GetDate() > date2->GetDate())? date1->GetDate() : date2->GetDate();
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


int main(int argv, char* argc[])
{
    std::vector<std::string> players = {"Petr", "Vasily", "Evgen", "Linus"};
    Game newGame(players);
    newGame.play();
	
    return 0;
}
