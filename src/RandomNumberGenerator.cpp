#include <RandomNumberGenerator.hpp>

std::random_device rd;
std::mt19937 gen(rd());

int generateRandomNumber(int min, int max) {
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
