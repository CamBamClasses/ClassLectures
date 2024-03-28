#include "Random.hpp"

#include <iostream>
#include <chrono>

#include <cstdio>
#include <random>
#include <algorithm>
#include <chrono>

int getRandNum_Old()
{
  static bool init = false;
  if (!init)
  {
    std::srand(time(nullptr)); // Seed std::rand
    init = true;
  }

  return std::rand() % 6;
}

int getRandNum_New()
{
  static bool init = false;
  static std::random_device rd;
  static std::mt19937 eng;
  static std::uniform_int_distribution<int> dist(0, 5);
  if (!init)
  {
    eng.seed(rd()); // Seed random engine
    init = true;
  }

  return dist(eng);
}

template <typename T>
double mean(T* data, int n)
{
  double m = 0;
  std::for_each(data, data + n, [&](T x) { m += x; });
  m /= n;
  return m;
}

template <typename T>
double stdDev(T* data, int n)
{
  double m = mean(data, n);
  double sd = 0.0;
  std::for_each(data, data + n, [&](T x) { sd += ((x - m) * (x - m)); });
  sd /= n;
  sd = sqrt(sd);
  return sd;
}

void doWork()
{
  const int N = 960000; // Number of trials
  const int M = 1000;   // Number of simulations
  const int D = 6;      // Num sides on die

  /* Do the things the "old" way (blech) */

  int freqList_Old[D];
  double stdDevList_Old[M];
  double timeTakenList_Old[M];

  for (int j = 0; j < M; j++)
  {
    auto start = std::chrono::high_resolution_clock::now();
    std::fill_n(freqList_Old, D, 0);
    for (int i = 0; i < N; i++)
    {
      int roll = getRandNum_Old();
      freqList_Old[roll] += 1;
    }
    stdDevList_Old[j] = stdDev(freqList_Old, D);
    auto end = std::chrono::high_resolution_clock::now();
    auto dur =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    double timeTaken = dur.count() / 1000.0;
    timeTakenList_Old[j] = timeTaken;
  }

  /* Do the things the cool new way! */

  int freqList_New[D];
  double stdDevList_New[M];
  double timeTakenList_New[M];

  for (int j = 0; j < M; j++)
  {
    auto start = std::chrono::high_resolution_clock::now();
    std::fill_n(freqList_New, D, 0);
    for (int i = 0; i < N; i++)
    {
      int roll = getRandNum_New();
      freqList_New[roll] += 1;
    }
    stdDevList_New[j] = stdDev(freqList_New, D);
    auto end = std::chrono::high_resolution_clock::now();
    auto dur =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    double timeTaken = dur.count() / 1000.0;
    timeTakenList_New[j] = timeTaken;
  }

  /* Display Results */

  printf("[OLD WAY]\n");
  printf("Spread\n");
  printf("       mean:  %.6f\n", mean(stdDevList_Old, M));
  printf("    std dev:  %.6f\n", stdDev(stdDevList_Old, M));
  printf("Time Taken (ms)\n");
  printf("       mean:  %.6f\n", mean(timeTakenList_Old, M));
  printf("    std dev:  %.6f\n", stdDev(timeTakenList_Old, M));
  printf("\n");
  printf("[NEW WAY]\n");
  printf("Spread\n");
  printf("       mean:  %.6f\n", mean(stdDevList_New, M));
  printf("    std dev:  %.6f\n", stdDev(stdDevList_New, M));
  printf("Time Taken (ms)\n");
  printf("       mean:  %.6f\n", mean(timeTakenList_New, M));
  printf("    std dev:  %.6f\n", stdDev(timeTakenList_New, M));
}