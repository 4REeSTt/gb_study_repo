#include "include/GenericPlayer.hpp"

GenericPlayer::GenericPlayer(std::string name, bool not_compuer)
:m_name(name)
{	
	if(GetName() == "Linus")
	m_NotComputer = 1;
}

bool GenericPlayer::IsBoosted() const
{
    return (GiveValue() > 21);
}

void GenericPlayer::Bust() const
{
    std::cout << m_name << " your hand is overflowed\n";
}

std::string GenericPlayer::GetName() const
{
    return m_name;
}

bool GenericPlayer::GetHuman() const
{
	return m_NotComputer;
}