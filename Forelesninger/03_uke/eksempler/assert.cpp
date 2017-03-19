#include <iostream>
// #define NDEBUG
#include <cassert>
using namespace std;

int foo(int a, int b)
{
	assert(b != 0); // prøv med og uten denne
	return a / b;
}

int main(void)
{
	int b = 3;
	assert(b == 3);

	foo(3, 2);
	foo(3, 0);
}
