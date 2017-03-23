#include<string>
#include<iostream>
#include<fstream>

using namespace std;

/*
Finn ut kor mange replikkar Hamlet har i stykket Hamlet.
Manuskriptet ligg i hamlet.txt
Hamlet sine replikkar er markerte med "Ham." rett før replikken
*/

void checkHamlet(std::string filename)
{
	ifstream fil(filename);
	//åpnar fila
	if (fil.fail()) {
		cout << "could not open file \"" << filename << "\"\n";
		return;
	}
	string word;
	int lines = 0;
	int words = 0;
	while (fil >> word) {
		words++;
		//cleanString(word);
		if (word == "Ham.") {
			lines++;
		}

	}
	fil.close();
	//print results
	cout << "Hamlet has " << lines << " lines in this play.\nThe play has"
		<< words << " words.\n";

}