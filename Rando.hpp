#ifndef THIS___RANDO_HPP
#define THIS___RANDO_HPP

#include <random>

class Rando {
public:
    Rando();
    unsigned int operator()();

    using result_type = unsigned int;
    result_type min();
    result_type max();
private:
    std::mt19937 engine;
};

#endif