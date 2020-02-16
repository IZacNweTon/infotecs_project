#include <iostream>
#include<primes.h>
#include<string.h>
#include"functions.h"
#include<fstream>


int main(int argc, char* argv[]){
    primes a;
    if(strcmp(argv[1], "search") == 0){
        std::fstream data("dat.txt", std::ios::out);
        switch(argc){
        case 2:
            Eratosthenes(a);
            remember(a, data);
            break;
        case 3:
            if(is_number(argv[2])){
                Eratosthenes(a, stouint32_t(argv[2]));
                remember(a, data);
            }else std::cout << "number is incorrect" << std::endl;
        break;
        case 4:
            if(is_number(argv[3]) && strcmp(argv[2], "all") == 0){
                Modified_search(stouint32_t(argv[3]), a);
                remember(a, data);
            }else std::cout << "unidentified arguments found or number is incorrect" << std::endl;
        break;
        default:
            std::cout << "unidentified arguments found" << std::endl;
        break;
        }
    }else if(strcmp(argv[1], "print") == 0){
        std::fstream data("dat.txt", std::ios::in);
        std::fstream file;
        switch (argc) {
        case 2:
            read(a, data);
            print(a);
            break;
        case 3:
            read(a, data);
            if(FileExists(argv[2])){
                file.open(argv[2], std::ios::out);
                print(a, false, file);
            }else if(is_sequence(argv[2])){
                print(a, true, std::cout, argv[2]);
            }else{
                std::cout << "unidentified arguments found or file does not exist" << std::endl;
            }
            break;
        case 4:
            if(FileExists(argv[2]) && is_sequence(argv[3])){
                read(a, data);
                file.open(argv[2], std::ios::out);
                print(a, false, file, argv[3]);
            }else{
                if(!FileExists(argv[2])) std::cout << "file does not exist" << std::endl;
                else std::cout << "unidentified arguments found" << std::endl;
            }
            break;
        }
    }
}


