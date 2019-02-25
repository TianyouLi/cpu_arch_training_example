#include <iostream>
#include <string>
#include <cstdlib>


int main(int argc, char* argv[])
{

    int random_mode = std::stoi(argv[1]);
    srand(time(NULL));

    int result = 0;
    for (int i=0; i< 100000000; i++) {
        int code = random_mode ? rand() % 5 : (rand(),i) % 5 ;
        if (code == 1) {
            result += 1;
        } else if (code == 2){
            result += 2;
        } else if (code == 3) {
            result += 3;
        } else if (code == 4) {
            result += 4;
        } else if (code == 5) {
            result += 5;
        } else if (code == 6) {
            result += 6;
        } else if (code == 7) {
            result += 7;
        } else if (code == 8) {
            result += 8;
        } else if (code == 9) {
            result += 9;
        } else {
            result +=5;
        }
    }
    std::cout << result << std::endl;
    return result;
}
