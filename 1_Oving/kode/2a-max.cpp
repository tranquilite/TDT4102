#include<iostream>

int max(int, int);

int main() {
    std::cout << "Oppgave a)" << std::endl;
    std::cout << max(5, 6) << std::endl;

    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
    return false;
}
