#include "include/Main.hpp"


int main(int argv, char* argc[])
{
    std::vector<std::string> players = {"Petr", "Vasily", "Evgen", "Linus"};
    Game newGame(players);
    newGame.play();
	
    return 0;
}
