#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include"primes.h"
#include<stdint.h>
#include<math.h>
#include<iostream>


void Eratosthenes(uint32_t max, primes& cont){
    cont = primes(max);
    bool *arr = new bool[max];
    for(uint32_t i = 2; i < max; i++) arr[i] = true;
    arr[0] = arr[1] = false;
    for(uint32_t i = 2; i < max; i++){
        if(!arr[i] || i*i*1ll > max) continue;
        for(uint32_t j = i*i; j <= max; j += i) arr[j] = false;
    }
    for(uint32_t i = 0; i < max; i++){
        if(arr[i] == true){
            cont.push_back(i);
        }
    }
    delete[] arr;
}

void Modified_search(uint32_t amount, primes& arr){
    arr = primes();
    uint32_t current = 2;
    while(arr.size() < amount){
        bool is_prime = true;
        for(uint32_t i = 0; i < arr.size(); i++){
            if(i > sqrt(current)) break;
            if(current % arr[i] == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            arr.push_back(current);
        }
        current++;
    }
}

#endif // FUNCTIONS_H
