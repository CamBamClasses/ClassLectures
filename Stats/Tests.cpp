#include "Game.hpp"
#include "gtest/gtest.h"

TEST(GameTest, GetHighScore) 
{
  Game::getHighScore();
  Game game1("Cam");
  Game game2("Voltron");
  game1.play();
  game2.getHighScore();
  game2.play();
  EXPECT_EQ(game1.getHighScore(), game2.getHighScore());
  EXPECT_EQ(game1.getHighScore(), Game::getHighScore());
  game1.rageQuit();
  for (int i = 0; i < 1000; i++)
  {
    game2.play();
  }
}

TEST(GameTest, ConstTest) 
{
  const double a = 5;
  const Game game("Flash");
  game.play();
}

TEST(GameTest, ConstTest)
{
  double a = 5;

  // don't do this
  // int b = (int)a;
  // int c = int(a);
 
  int d = static_cast<int>(a);

  // what if negative?
  // what if partial number?
  if (a > 0 && std::floor(a) == a)
  {
    size_t e = static_cast<size_t>(a);
  }


}
