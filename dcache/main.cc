#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    unsigned long long size = std::stoull(argv[1]);
    int reversed = std::stoi(argv[2]);
    
    char* mem = new char[size * size];
    if (mem == NULL) {
        return 1;
    }
    
    for (unsigned long long i =0; i <size; i++) {
        for (unsigned long long j =0; j <size; j++) {
            unsigned long long index = reversed ? i + j*size : i*size +j;
            mem[index] += 1; 
        }
    }
    
    delete[] mem;
    return 0;
}
