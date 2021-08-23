#include "include/Main.hpp"

#ifdef _WIN32
    #include <windows.h>

    void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>
    
    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif





Player::Player(std::string name, bool not_computer)
:GenericPlayer(name, not_computer)
{}

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
	if(IsBoosted()){
		Bust();
		sleep(1000);
		return false;
	}

	if(GetHuman())
		std::cout << "Do you need card? (Yes/No)\n";
	else
	{
		return (GiveValue() < 16);
	}
    return secured_input();
}
