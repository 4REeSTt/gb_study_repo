#include "include/Deck.hpp"

Deck::Deck()
{
    Populate();
}

Deck::~Deck()
{
    for(auto card : m_deck)
        delete card;
}

void Deck::Populate()
{
    for(int rank = 1; rank < 14; rank++)
        for(int suit = 0; suit < 4; suit++)
            m_deck.push_back(new Card((Card::Rank)rank, (Card::Suit)suit));
}

void Deck::Shuffle()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0, m_deck.size());
	
    for(int i = 0; i < dist(mt); i++)
        for(int j = 0; j < m_deck.size(); j++)
            std::swap(m_deck[dist(mt)], m_deck[dist(mt)]); 
}

void Deck::Deal(Hand& aHand)
{
    if(!m_deck.size()){
        std::cout << "Deck is empty\n";
        return;
    }
    aHand.Add(m_deck[m_deck.size() -1]);
    m_deck.pop_back();
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer, Game& current)
{
    while(aGenericPlayer.IsHitting())
    {
        if(!m_deck.size()){
            std::cout << "Deck is empty\n";
            break;
        }
        aGenericPlayer.Add(m_deck[m_deck.size() -1]);
        m_deck.pop_back();
		
		if(aGenericPlayer.GetHuman())
			current.printPlayerStatment(&aGenericPlayer);
    }
}
