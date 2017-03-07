#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<map>

using std::cout;
using std::cin;
using std::string;

//ingen output foreløpig
//kjempegod ide å teste sånn.

//eksisterer allerede i 2.cpp
char sma_bokstaver(char bokstav);

void ordstatistikk() {
    char tegnsetting[] = ",\'\"";
    //string filnavn("Part3_w.txt");
    string filnavn("test.txt");
    std::fstream inn_fil;
    inn_fil.open(filnavn);

    if(inn_fil.is_open()) {
        string linje;
        string ord;
        string ord_lengst;
        std::map<string, int> ord_insidens;
        while(!inn_fil.eof()) {
            int ord_totalt, linjer_totalt, snittlengde;
            std::getline(inn_fil, linje);   //hent linje
            for(int i=0; i < strlen(tegnsetting); i++) { //rens for tegnsetting
                //men nå stripper den newlines òg!
                linje.erase(std::remove(linje.begin(), 
                                        linje.end(), tegnsetting[i]));
                std::transform(linje.begin(), linje.end(),
                                linje.begin(), sma_bokstaver);
            }
            linje += "\n"; // ghetto! Konsekvensen av dårlig tid..
            std::stringstream ss(linje);    //denne må itereres over - men hvoooo..
                                            //hvordan? Se operator>>
            ss >> ord;                      //stream fra streng->ord til term
            cout << "\n" << ord << "\n";
            ss >> ord;
            cout << "\n" << ord << "\n";

            if(ord.length() > ord_lengst.length()) {    //KLOKKA ER 12:57
                ord_lengst.resize(ord.size());
                ord_lengst = ord;
            }
            //shit shit shit shit shit
            //screw it.
            cout << linje;


        }
        cout << "-----\n" << ord_lengst << "\n";
        //okok. Tegnsetting, små bokstaver, lengste ord. HVORFOR NEWLINES?!
    }

    inn_fil.close();
}
