#include<fstream>
#include<ctime>
#include<cstdlib>
#include<iostream>

using std::ifstream;
using std::cout;
using std::endl;

int incrementByNumTimesValue(int startValue, int increment, int numTimes) {
    for(int i=0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

int incrementByNumTimesValue2(int *startValue, int increment, int numTimes) {
    //og vi endrer for det meste at startValue nå derefererer crappet som kom
    //inn som argument, aka adressen av v0 i stacken.
    for(int i=0; i < numTimes; i++) {
        *startValue += increment;
    }
    return *startValue;
}

void swapNumbers(int *etTall, int *toTall) {
    //Pointypointy fordi hvorfor legge mer på stacken når vi allerede har to
    //helt fine rett under som vi kan omrokkere på?
    //Skal bytte på to tall, hva skulle jeg gjort?
    int a = *etTall;
    *etTall = *toTall;
    *toTall = a;
}

//Del 2
void printArray(int arrayToPrint[], int arrayLen) {
    for(int i=0; i < arrayLen; ++i) { //Preincrement fordi zero-index
        cout << arrayToPrint[i] << "  ";
    }
    cout << endl;
}

int randomWithLimits(int lower, int upper) {
    int rekkevidde_diff = (upper - lower);
    srand(time(0));
    return ((rand() % rekkevidde_diff + 1) +lower);
}

int randomWithLimits(int lower, int upper, int mode) {
    unsigned int seed = 0;
    switch(mode){
        case 0:
            seed = time(0);
            break;
        case 1: //RAGE WOLF MODE
            char * streng; //Init peker til seed-streng
            ifstream fil;
            fil.open("/dev/random", std::ios::binary);
            if(fil.is_open()) {
                int str = sizeof(int); //hvem vet. Varierer.
                streng = new char[str]; //Init arr på heap
                fil.read(streng, str); //Les str-symbol fra ios til streng-peker
                fil.close();
                //I guess dette funker halvveis fordi jeg leser binært?
                for(int i = 0; i < str; ++i) {
                    seed += int(streng[i]);
                }
            } else {
                cout << "smeg" << endl;
                srand(0); //Plystrer uskyldig..
            }
            break;
    }
    int rekkevidde_diff = (upper - lower);
    srand(seed);
    return ((rand() % rekkevidde_diff + 1)+lower);
}

void randomizeArray(int arrayToPopulate[], int arrayLen) {
    for(int i = 0; i < arrayLen; ++i) {
        arrayToPopulate[i] = randomWithLimits(0, 100, 1);
    }
}
