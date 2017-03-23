#include <iostream>
using namespace std;

void K1_ex1()
{
	int a = 3;
	while (a)
	{
		cout << a;
		a = a - 1;
	}
}

void K1_ex2()
{
	int a = 3;
	do
	{
		cout << a;
		a = a - 1;
	} while (a);
}
void K1_ex3()
{
	int a = 3;
	do
	{
		cout << a;
		a = a - 1;
	} while (a > 4);
}

void K1_ex4() 
{
	int a = 20;
	int b = 10;

	if (a > b)
		a;
	else
		b = 66;
	
	cout << a;
	cout << b;
}

void K1_ex5() 
{
	int a = 2;
	switch (a) {
	case 1:
		cout << "one";
		break;
	case 2:
		cout << "two";
	case 3:
		cout << "three";
		break;
	default:
		cout << "unknown";
	}
}
void K1_ex6()
{
	int j = 0;
	for (short i = 1; i < 10; i++)
		j++;
	cout << j;
}

void K1_ex7()
{
	int a = 2;
	for (short i = 0; i < 10; i++) {
		a = a + 3;
		if ((i % 2) == 0) a--;
	}
	cout << a;

}


void test_1(int x) {
	x = x + 1;
	return;
}
void Kahoot_1_8() {
	int a = 0;
	for (int i = 0; i < 10; i++)
		test_1(a);
	cout << a;
}

void test_2(int &x) {
	x = x + 1;
	return;
}
void Kahoot_1_9() {
	int a = 0;
	for (int i = 0; i < 10; i++)
		test_2(a);
	cout << a;
}
 

int test_3(int &x) { 
	x = x + 1; 
	return (20); 
}

void Kahoot_1_10() {
	int a = 0;
	for (int i = 0; i < 10; i++) 
		test_3(a);
	cout << test_3(a);
	cout << " " << a;
}
 


int main() {

	K1_ex1(); system("Pause");
	K1_ex2(); system("Pause");	
	K1_ex3(); system("Pause");
	K1_ex4(); system("Pause");
	K1_ex5(); system("Pause");	
	K1_ex6(); system("Pause");	
	K1_ex7(); system("Pause");
	Kahoot_1_8(); system("Pause");
	Kahoot_1_9(); system("Pause");
	Kahoot_1_10(); system("Pause");
}
