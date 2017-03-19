#include <iostream>
using namespace std;

int main(){

const int timelonn = 200;
int timer = 0;
int betaling = 0;

cout << "Skriv inn antall timer du har jobbet: ";
cin >> timer;

if (timer > 40){
	betaling = timelonn * 40 + 1.5 * timelonn * (timer-40);
	cout << "Du har jobbet overtid\n";
}else{
	betaling = timelonn*timer;
	cout << "Du ikke har jobbet overtid\n";
}
cout << "\nDu har tjent " << betaling << " denne uka!" <<endl;


}
