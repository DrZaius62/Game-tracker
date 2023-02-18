// Game.cpp -- Definition of class Game

#include "Game.hpp"
#include "utils.hpp"
#include <iostream>

Game::Game(){
    setName("default");
    setStart(0);
    setBeat(0);
    setReview(0);
    setRelease(0);
    setStatus("Backlog");
    setPlatform("PC");
}

// Saves the day when the game was started
// i should implement a "button" to start counting the time when the game is
// started, because a game can be add to wishlist or backlog, meaning it doesn't
// someone doesn't start playing when is added in one of those cases
void Game::setName(std::string name){
    Game::name = name;
}

void Game::setStart(time_t current){
    /*
    time_t today = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
    d_start = today;
    */
    d_start = current;
}

void Game::setBeat(time_t current){
    d_beat = current;
}

void Game::setRelease(time_t current){
    d_release = current;
}

void Game::setReview(int review){
    Game::review = review;
}

void Game::setStatus(std::string status)
{
    Game::status = status;
    //enum p_status {Beat, Playing, Quit, Paused, Wishlist, Backlog};
}

void Game::setPlatform(std::string platform)
{
    Game::platform = platform;
}

void Game::print(){
    time_t current = getStart();
    time_t beat = getBeat();
    time_t release = getRelease();

    //std::string current_str = std::string str(buffer); 
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Date Started: " << printDate(current)<< std::endl;
    std::cout << "Date Beat: " << printDate(beat) << std::endl;
    std::cout << "Date Release: " << printDate(release) << std::endl;
    std::cout << "Review: " + std::to_string(getReview()) << std::endl;
    std::cout << "Status: " + getStatus() << std::endl;
    std::cout << "Platform: " + getPlatform() << std::endl;
}
