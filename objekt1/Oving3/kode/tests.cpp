#ifndef _stream
#include<iostream>
#define _stream
#endif
#include"utilities.h"

using namespace std;

void test_increment_by_value() {
    int v0 = 5, increment = 2, iterations = 10;
    int result = increment_by_value_num_times(v0, increment, iterations);
    cout << "v0: "          <<  v0
         << " increment: "  << increment
         << " iterations: " << iterations
         << " result: "     << result << endl;
}

void test_swap_numbers() {
    const int* tall_liste = new char[40];
    int _midlertidig_liste[40] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                11, 12, 13, 14, 15, 16, 17, 18,
                                19, 20, 21, 22, 23, 24, 25, 26,
                                27, 28, 29, 30, 31, 32, 33, 34,
                                35, 36, 37, 38, 39};
    
    
}
