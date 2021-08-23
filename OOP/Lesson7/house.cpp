#include "House.hpp"

House::House()
:GenericPlayer("Diler")
{}

bool House::IsHitting() const
{
    return (GiveValue() < 16);
}

void House::FlipFirstCard()
{
    FlipFirst();
}
