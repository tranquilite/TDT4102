#include<string>
using namespace std;

string cleanString(string  str)
{
	string resultat = "";
	for (char c : str) {
		if (isalpha(c)) {
			c = tolower(c);
			resultat += c;
		}
	}
	return resultat;
}