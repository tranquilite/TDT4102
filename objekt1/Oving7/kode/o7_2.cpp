#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>

using std::cout;
using std::cin;
using std::string;

char sma_bokstaver(char bokstav){
  if(bokstav<='Z' && bokstav>='A')
    return bokstav-('Z'-'z');
  return bokstav;
} 


void tegnstatistikk() {
    int  index[26] = {0};
    int  totes = 0;
    char radix[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                      'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                      's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    string filnavn("Part3_w.txt");
    std::fstream inn_fil;
    inn_fil.open(filnavn);

    while(!inn_fil.eof()) {
        string linje;
        std::getline(inn_fil, linje);
        std::transform(linje.begin(), linje.end(),
                       linje.begin(), sma_bokstaver);
        for(int i=0; i < 26; i++) {
            index[i] += std::count(linje.begin(), linje.end(), radix[i]);
            totes    += std::count(linje.begin(), linje.end(), radix[i]);
            //Woo! Seks funksjonskall/iterasjon
        }
    }

    inn_fil.close();

    cout << "Totalt: " << totes << " bokstaver\n";
    for(int i=0; i < 26; i++) {
        cout << radix[i] << ": " << index[i];
        if((i+1) % 4 == 0) { // +1 for ghetto
            cout << "\n";
        } else {
            cout << "\t";
        }
    }

    cout << "\n";

}
