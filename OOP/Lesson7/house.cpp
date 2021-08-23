#include "include/House.hpp"

House::House()
:GenericPlayer("Dealer")
{}

bool House::IsHitting() const
{
	if(IsBoosted())
		Bust();
    return (GiveValue() < 16);
}

void House::FlipFirstCard()
{
    FlipFirst();
}
