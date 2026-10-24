#include "../../source/util.h"

int main()
{
    std::cout << biteutil::Random::code(16) << std::endl;
    std::cout << biteutil::Random::code(6, biteutil::UuidType::DIGIT) << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << biteutil::Random::number(50, 100) << std::endl;
    }
    return 0;
}