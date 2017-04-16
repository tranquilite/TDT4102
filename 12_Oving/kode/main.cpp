#include<iostream>

#include"SafeArray.h"

int main() {
    SafeArray<int> *S = new SafeArray<int>(2);
    try {
        (*S)[3];
    }
    catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
