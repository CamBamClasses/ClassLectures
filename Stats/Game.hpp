#ifndef GAME_HPP
#define GAME_HPP

#include <string>

class Game
{
public:
  Game(std::string name);

  int play() const;

  static int getHighScore();

  void rageQuit();

private:
  std::string m_name;
  bool m_hasQuit;

  static int highScore;
};

#endif
