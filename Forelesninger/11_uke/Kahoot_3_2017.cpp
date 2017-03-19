#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

// ********************************************
//  = K1_ex4()
void K3_ex1()
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

// ********************************************
// = K1_ex6
 void K3_ex2() {
	int j = 0;
	for (short i = 1; i < 10; i++)
		j++;
	cout << j;
}

// ********************************************
// = K2_ex2 

int func(int x, int y) {
	x++; y++;
	return (x*y);
}
void K3_ex3() {
	cout << func(1, 1);
}


//*********************************************************
// = K2_ex8

void K3_ex4() {
	int a = 1;
	int b = 2;
	int *p1 = &a;
	int *p2 = &b;

	p2 = p1;
	cout << *p2;
}


// ********************************************
//  = Juni 2016 1g 
//  
void K3_ex5() {
	map<int, string> mySkis;
	mySkis[100] = "Back country";
	mySkis[102] = "Classic racing";
	mySkis[103] = "Skate racing";
	mySkis[100] = "Old Splitkein";
	cout << mySkis.size() << ", " << mySkis[100];

}


// ********************************************
//  = August 2016 1f, fjernet endl;
//  
void K3_ex6() {
	bool found = true;
	int value = 7;
	if (!found && --value == 0)
		cout << "danger ";
	cout << "value = " << value;
}


// ********************************************
//  August 2016 - 1i forenklet, uten iterator
//  
void K3_ex7() {
	set<int> mySet;
	mySet.insert(10);
	mySet.insert(20);
	mySet.insert(30);
	mySet.insert(10);
	cout <<  mySet.size();
}


// ********************************************
//  August 2016 - 1j forenklet 
//  
void K3_ex8() {
	string s1 = "aaa";
	string s2("bbb");
	string s3;
	s3 = s1 + s2;
	cout << s3 << " " << s3.length() << endl;

}


int main() {
	K3_ex1(); cout << " "; system("Pause");
	K3_ex2(); cout << " "; system("Pause");
	K3_ex3(); cout << " "; system("Pause");
	K3_ex4(); cout << " "; system("Pause");
	K3_ex5(); cout << " "; system("Pause");
	K3_ex6(); cout << " "; system("Pause");
	K3_ex7(); cout << " "; system("Pause");
	K3_ex8(); cout << " "; system("Pause");
}
