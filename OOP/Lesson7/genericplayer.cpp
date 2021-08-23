#include "GenericPlayer.hpp"

GenericPlayer::GenericPlayer(std::string name)
:m_name(name)
{}

bool GenericPlayer::IsBoosted()
{
    return (GiveValue() > 21);
}

void GenericPlayer::Bust()
{
    std::cout << m_name << " your hand is overflowed";
}

std::string GenericPlayer::GetName() const
{
    return m_name;
}
