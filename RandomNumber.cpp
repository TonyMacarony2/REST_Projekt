//
// Created by tony on 15/01/2025.
//
#include "RandomNumber.h"

using namespace std;

int getRandomNumber(int min, int max) {
    static random_device rd;  // Seed for randomness
    static mt19937 gen(rd()); // Mersenne Twister RNG
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}