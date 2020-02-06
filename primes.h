#ifndef PRIMES_H
#define PRIMES_H
#include<stdint.h>

class primes
{
public:
    primes(uint32_t max);
    primes();
    void push_back(uint32_t temp);
    uint32_t size();
    uint32_t maximum();
    uint32_t& operator[](uint32_t index);
    ~primes();
private:
    uint32_t* arr;
    uint32_t Size;
    uint32_t max_size;
    uint32_t max_value;
};


#endif // PRIMES_H
