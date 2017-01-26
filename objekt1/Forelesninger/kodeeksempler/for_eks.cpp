#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    
	for (int i = 1; i <= 10; i++){
        cout << i << ":\t";
        for (int j = 1; j <= 10; j++){
            cout << std::right << std::setw(3) << (i * j) << "\t";
        }
        cout << endl;
    }
}







