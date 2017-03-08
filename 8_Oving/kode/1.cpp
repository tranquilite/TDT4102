#include<iostream>
#include<string>
#include<fstream>


using std::cout;
using std::cin;
using std::string;
using std::ofstream;


int ord_til_fil() {
    ofstream fil;
    fil.open("fil.txt");
    if(fil.is_open()) {
        string ord;
        cout << "Tast 'quit' for å slutte\n";
        while(true) {
            ord.clear();
            cin >> ord;
                if(ord.compare("quit") == 0) {
                    fil.close();
                    return 0;
                } else {
                    fil << ord << "\n";
                }
        }
    }

    return 1; // Burde jo ikke egentlig komme hit
}

int lag_fil_linjenummer() {
    string filnavn("test.txt");
    std::fstream inn_fil;
    ofstream ut_fil;
    inn_fil.open(filnavn);
    
    string filnavn2("linjert_");
    filnavn2 += filnavn;
    ut_fil.open(filnavn2);
    
    int i = 1;
    do {
        string linjert_linje;
        linjert_linje += std::to_string(i);
        linjert_linje += "\t";
        string meh;     //ghetto
        std::getline(inn_fil, meh);
        linjert_linje += meh;
        linjert_linje += "\n";
        cout << linjert_linje;
        ut_fil << linjert_linje;
        i++;

    } while(!inn_fil.eof());
    
    inn_fil.close();
    ut_fil.close();
    std::cout<< "\n\nFerdig!\n\n";
    return 0;
}
