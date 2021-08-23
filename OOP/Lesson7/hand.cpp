#include "Hand.hpp"

Hand::~Hand(){}

void Hand::Add(Card* card)
{
    m_collection.push_back(card);
}

void Hand::FlipFirst()
{
    m_collection[0]->Flip();
}

void Hand::Clear()
{
	for(auto card : m_collection)
		delete card;
    m_collection.clear();
}

int Hand::GiveValue() const
{
    bool ace_flag = 0;
    int counter = 0;
    for(auto value: m_collection)
    {
        if(value->GetValue() == 1)
            ace_flag = 1;
        counter += value->GetValue();
    }
    if(counter <= 10 && ace_flag)
        counter += 10;
    return counter;
}

int Hand::GetSize() const
{
	return m_collection.size();
}

Card& Hand::GetCard(int idx) const
{
	return *m_collection[idx];
}