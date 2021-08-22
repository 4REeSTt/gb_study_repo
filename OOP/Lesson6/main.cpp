#include <iostream>
#include <vector>
//include <Card.hpp> <Hand.hpp> <GenericPlayer.hpp>
enum Suit{
    Diamonds,
    Hearts,
    Clubs,
    Spades
};
enum Rank{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine, 
    Ten,
    Jack,
    Queen,
    King,
    
};
class Card
{
    Suit suit;
    Rank rank;
    bool IsFliped;
public:
    Card(Rank rank)
    :rank(rank)
    {} 

    std::ostream& operator<<(std::ostream &out);
    void Flip();
    int GetValue();
    void printCard();
};

std::ostream& Card::operator<<(std::ostream &out)
{
    if(IsFliped == 1)
        return out << "XX\n";

    return out << suit << " " << rank << "\n";
}

void Card::Flip()
{
    if(IsFliped)
        IsFliped = 0;
    else
        IsFliped = 1;
}

int Card::GetValue()
{
    if((rank == Jack) || (rank == Queen) || (rank == King))
        return 11;
    else
        return rank;
}

void Card::printCard()
{
    std::cout << GetValue() << "\n";
}

class Hand
{
private:
    std::vector<Card*> collection;
public:

    void ADD(Card* card)
    {
        collection.push_back(card);
    }
    void FlipFist()
    {
        collection[0]->Flip();
    }
    void Clear()
    {
        collection.clear();
    }
    

    int GiveValue() const
    {
        bool ace_flag = 0;
        int counter = 0;
        for(auto value : collection)
        {
            if(value->GetValue() == 1)
                ace_flag = 1;
            counter += value->GetValue();
        }
        if(counter <= 10 && ace_flag)
            counter += 10;
        return counter;
    }
};
class GenericPlayer:public Hand
{
private:
    std::string name;
public:
    virtual bool IsHitting() = 0;
    bool IsBoosted();
    void Bust();
    std::string Get_name() const {return name;}
};


bool GenericPlayer::IsBoosted()
{
    if(this->GiveValue() > 21)
        return true;
    return false;
}

void GenericPlayer::Bust()
{
    std::cout << name << " Your hand has overflow\n";
}


//1.------------------------------------------------------------
int secured_input()
{
    int value;
    std::cout << "Please enter the value\n> ";
    while(!(std::cin >> value) || (std::cin.peek()) == 113)
    {
        std::cout << "Please enter the value\n> ";
        std::cin.clear();
        std::cin.sync();
    }
    return value;
}
//2.------------------------------------------------------------
namespace std
{
    ostream& endll(ostream &out)
    {
        out << "\n\n";
        out.flush();
        return out;
    }
}
//3.------------------------------------------------------------
class Player:public GenericPlayer
{
private:

public:
    virtual bool IsHitting() const;

    void Win()  const{std::cout << Get_name() << " You won"  << std::endl;}
    void Lose() const{std::cout << Get_name() << " You lost" << std::endl;}
    void Push() const{std::cout << Get_name() << " Got draw" << std::endl;}
};

bool Player::IsHitting() const
{
    std::cout << "Do you need card?( 0/No : any/Yes )\n";
    return (secured_input())? true : false;
}

class House:public GenericPlayer
{
private:
public:
    virtual bool IsHitting() const;
    void FlipFirstCard();
};

bool House::IsHitting() const
{
    return (GiveValue() < 16);
}
void House::FlipFirstCard()
{
    FlipFist();
}

int main()
{
//1.------------------------------------------------------------
    int value = secured_input();
    std::cout << value << "\n";

//2.------------------------------------------------------------
    std::cout << "New endll" << std::endll;

//3.------------------------------------------------------------
    return 0;
}
