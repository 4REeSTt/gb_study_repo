project(BlackJack)

cmake_minimum_required(VERSION 3.14)

add_executable(${PROJECT_NAME} main.cpp card.cpp hand.cpp genericplayer.cpp player.cpp house.cpp deck.cpp game.cpp global_foo.cpp)
