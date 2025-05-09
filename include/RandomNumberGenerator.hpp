#ifndef GLOBALRANDOM_HPP
#define GLOBALRANDOM_HPP

#include <random>
#include <ctime>

extern std::random_device rd;
extern std::mt19937 gen;

int generateRandomNumber(int min, int max);

#endif // GLOBALRANDOM_HPP