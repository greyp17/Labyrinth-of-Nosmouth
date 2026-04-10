//Anywhere in the game where we would use random we can instead use this function just like randomInt(min,max);
#include "Headers/RandomUtil.h"
#include <random>

int randomInt(int min, int max) {

static std::random_device rd;
static std::default_random_engine engine{rd()};
std::uniform_int_distribution<int> randomI(min, max);

return randomI(engine);
}