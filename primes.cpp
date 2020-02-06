#include "primes.h"
#include<iostream>


primes::primes(){
    arr = new uint32_t[100];
    max_size = 100;
    max_value = 0;
    Size = 0;
}

primes::primes(uint32_t max) {
    arr = new uint32_t[100];
    max_size = 100;
    max_value = max;
    Size = 0;
}

primes::~primes(){
    delete[] arr;
    Size = 0;
    max_size = 0;
}

void primes::push_back(uint32_t temp){
    if(Size >= max_size){
        max_size = 1.6 * max_size;
        uint32_t* buf = new uint32_t[max_size];
        for(uint32_t i = 0; i < max_size; i++){
            buf[i] = arr[i];
        }
        delete[] arr;
        arr = buf;
    }
    arr[Size] = temp;
    ++Size;
}

uint32_t primes::maximum(){
    return max_value;
}

uint32_t primes::size(){
    return Size;
}



uint32_t& primes::operator[] (uint32_t index){return *(arr + index);}
