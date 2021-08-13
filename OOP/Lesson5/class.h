#pragma once
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
    bool placement;
public:
    Card(Rank rank)
    :rank(rank)
    {} 

    void Flip();
    int GetValue();
    void printCard();
};

void Card::Flip()
{
    if(placement)
        placement = 0;
    else
        placement = 1;
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

    void Clear()
    {
        collection.clear();
    }

    int GiveValue()
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
