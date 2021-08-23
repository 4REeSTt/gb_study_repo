#include "Main.hpp"

Player::Player(std::string name, bool not_computer)
:GenericPlayer(name)
{
	if(GetName() == "Linus")
		m_NotComputer = 1;
}

void Player::Win() const
{
    std::cout << GetName() << " You won" << std::endl;
}

void Player::Lose() const
{
    std::cout << GetName() << " You lost" << std::endl;
}

void Player::Push() const
{
    std::cout << GetName() << " Got draw" << std::endl;
}

bool Player::IsHitting() const
{
	if(m_NotComputer)
		std::cout << "Do you need card? (0/No : any/Yes)\n";
	else
	{
		return (GiveValue() < 16);
	}
    return secured_input();
}
