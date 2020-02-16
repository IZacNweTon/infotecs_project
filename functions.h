#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include"primes.h"
#include<stdint.h>
#include<math.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include <unistd.h>

void Eratosthenes(primes& cont, uint32_t max = 100){
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


void read(primes& a, std::fstream &input){
    uint32_t temp;
    while(input >> temp){
        a.push_back(temp);
    }
}

void remember(primes& a, std::fstream &output){
    for(int i = 0; i < a.size(); i++){
        output << a[i] << std::endl;
    }
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
bool is_palindrome(uint32_t var){
    int cpy = var;
    int temp = 0;
    while( (var / 10) > 0){
        temp = temp * 10 + (var % 10);
        var /= 10;
    }
    temp = temp * 10 + var % 10;
    if(temp == cpy) return true;
    else return false;
}



bool print(primes& arr, bool console = true,std::ostream& output = std::cout, std::string type = "none"){
    char separate;
    if(console) separate = ' ';
    else separate = '\n';
    if(type == "none"){
        for(int i = 0; i < arr.size(); i++){
            output << arr[i] << separate;
        }
    }else if(type == "superprime"){
        int i = 0;
        while(arr[i] <= arr.size()){
            output << arr[arr[i] - 1] << separate;
            i++;
        }
    }else if(type == "palindrome"){
        for(int i = 0; i < arr.size(); i++){
            if(is_palindrome(arr[i])) output << arr[i] << separate;
        }
    } else{
        std::cout << "unknown sequence. try 'palindrome' or 'superptime' " << separate;
        return false;
    }
    std::cout << "successfully written" << separate;
    return true;
}

bool is_sequence(const char* str){
    return (strcmp(str, "superprime") == 0 || strcmp(str, "palindrome") == 0);
}

bool FileExists(const char *fname)
{
    return access(fname, 0) != -1;
}

uint32_t stouint32_t(const char* str){
    if(strlen(str) > 10) return 0;
    if(atoll(str) <= 0) return 0;
    else if(atoll(str) > 4294967295) return 0;
    else return atoll(str);
}

bool is_number(const char* str){
    return (stouint32_t(str) > 0);
}
#endif // FUNCTIONS_H
