#include "Game.hpp"

Game::Game(std::vector<std::string>& player_list)
{
    m_diler = new House;
    for(int name = 0; name < player_list.size(); name++)
        m_players.push_back(new Player(player_list[name]));


    m_deck.Shuffle();

}

Game::~Game()
{
    for(auto player : m_players)
        delete player;
}

void Game::printCardStatment() const
{
    std::cout << m_diler->GetName() << ": ";
    for(int i = 0; i < m_diler->GetSize(); i++)
        std::cout << m_diler->GetCard(i) << " ";
    std::cout << std::endl;

    for(auto player : m_players)
    {
        std::cout << player->GetName() << ": ";
        for(int card = 0; card < player->GetSize(); card++)
            std::cout << player->GetCard(card) << " ";
        std::cout << std::endl;
    }
}

void Game::printPlayerStatment(GenericPlayer* player) const
{
	std::cout << "Current cards: ";
	for(int card = 0; card < player->GetSize(); card++)
		std::cout << player->GetCard(card) << " ";
	std::cout << std::endl;
}

void Game::play()
{

    for(auto player : m_players)
    {
        m_deck.Deal(*player);
        m_deck.Deal(*player);
    }
    m_deck.Deal(*m_diler);
    m_deck.Deal(*m_diler);
    m_diler->FlipFirstCard();


    for(auto player : m_players){
		printPlayerStatment(player);
        m_deck.AdditionalCards(*player, *this);
	}

	std::cout << "\n\n";
	printCardStatment();
	std::cout << "\n\n";

    m_diler->FlipFirstCard();
    m_deck.AdditionalCards(*m_diler);
    printCardStatment();

    for(auto player : m_players)
    {
        if(player->IsBoosted())
            player->Lose();
        else if(player->GiveValue() > m_diler->GiveValue())
           player->Win(); 
        else if(player->GiveValue() < m_diler->GiveValue())
           player->Lose(); 
        else
           player->Push(); 
    }
    for(auto player : m_players)
        player->Clear();
}

