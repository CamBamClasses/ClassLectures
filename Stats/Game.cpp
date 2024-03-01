#include "Game.hpp"

#include <iostream>

Game::Game(std::string name) : m_name(name), m_hasQuit(false) { }

int Game::play() const
{
  std::cout << "You played the game! Good Job " << m_name << std::endl;
  int score = rand() % 10;

  // cyclomatic complexity
  highScore = std::max(score, highScore);

  // doesn't compile
  //m_name += " is a nerd";
  return score;
}

int Game::getHighScore()
{
  // std::cout << m_name << std::endl;
  return highScore;
}

void Game::rageQuit()
{
  m_hasQuit = true;
}

int Game::highScore = 0;
