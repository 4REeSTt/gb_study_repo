#include "include/Card.hpp"

Card::Card(Rank rank, Suit suit, bool IsFliped)
:m_rank(rank), m_suit(suit), m_IsFliped(IsFliped)
{}

bool Card::GetFlip()const
{
	return m_IsFliped;
}

Card::Rank Card::GetRank() const
{
	return m_rank;
}

Card::Suit Card::GetSuit() const
{
	return m_suit;
}

void Card::Flip()
{
    m_IsFliped = !m_IsFliped;
}

int Card::GetValue() const
{
    if((m_rank == JACK) || (m_rank == QUEEN) || (m_rank == KING))
        return 11;
    return m_rank;
}

