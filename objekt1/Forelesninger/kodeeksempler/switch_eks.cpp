


#include <iostream>
using namespace std;

int main(){

int fart = 0;
int fartsgrense = 0;
int bot = 0;
cout << "Hvor fort kjørte du? : ";
cin >> fart;
cout << "Hva var fartsgrensen? : ";
cin >> fartsgrense;

int overskridelse = 0;

if (fart >= fartsgrense){
	overskridelse = fart - fartsgrense;
}


int kategori = overskridelse / 5;

cout << "Botkategori: " << kategori << endl;


switch (kategori){
	case 0:
		cout << "Du holdt deg til fartsgrensen!";
		break;
	case 1:
		cout << "5 kilometer for fort!";
		bot = 500;
		break;
	case 2:
		cout << "10 kilometer for fort!";
		bot = 1000;
		break;
	case 3:
		cout << "15 kilometer for fort!";
		bot = 3000;
		break;
	case 4:
		cout << "Du mister førerkortet!";
		bot = 10000;
		break;
	default:
		cout << "Du må nok sitte inne!";
}



}







