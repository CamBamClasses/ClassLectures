#include "Threads.hpp"
#include "gtest/gtest.h"

// context switching

#include <thread>
//#include <atomic>
#include <mutex>
#include <vector>

TEST(ThreadTest, FirstTest)
{
  // doWork();

  // myFunction();
  // std::thread t1(myFunction);

  std::vector<std::thread> threads;

  std::mutex m;
  int myInt = 0;
  std::vector<int> myLastInts(100);
  for (int i = 0; i < 100; i++)
  {
    threads.push_back(std::thread(
      [&myInt, &m, i, &myLastInts]()
      {
        for (int j = 0; j < 10000; j++)
        {
          std::scoped_lock<std::mutex> lock(m);
          myInt++;
          //std::cout << myInt << std::endl; // intensive
          //std::cout << i << std::endl;
        }
        myLastInts[i] = myInt;
        // std::cout << "In Thread " << myInt << std::endl;
      }));
  }

  // doWork();
  // i++;

  // t1.join();

  for (int i = 0; i < 100; i++)
  {
    threads[i].join();
    std::cout << myLastInts[i] << std::endl;
  }
  std::cout << myInt << std::endl;
}
