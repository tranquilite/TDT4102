#include<fstream>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<math.h>
#include<cctype>

using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::toupper;

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
    //Skal bytte på to tall, hva skulle jeg gjort?
    int a = *etTall;
    *etTall = *toTall;
    *toTall = a;
}

//Del 2
/*template<typename P_TYPE>
void printArray(P_TYPE arrayToPrint[], int arrayLen) {
    for(int i=0; i < arrayLen; ++i) { //Preincrement fordi zero-index
        cout << arrayToPrint[i] << "  ";
    }
    cout << endl;
}*/
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
            seed = 0x9b3779b1 * 4;
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
                for(int i = 0; i < str; ++i) {
                    seed += int(streng[i]);
                }
            } else {
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

void randomizeArrayWithScope(int arrayToPopulate[], int arrayLen,
                            int upper, int lower) {
    for(int i = 0; i < arrayLen; ++i) {
        arrayToPopulate[i] = randomWithLimits(0, 100, 1);
    }
}

//Del 3

void sortArray(int arrayToSort[], int arrayLen) {
    //Jævla fuckings bubblesort
    //men loop da for faen.
    bool unSorted = true, runOnce = false; //init
    while(unSorted) {
        for(int i=0; i < arrayLen-1; ++i) {
            if(arrayToSort[i] > (arrayToSort[((i+1) % arrayLen)])) {
                runOnce = true;
                swapNumbers(&arrayToSort[i], &arrayToSort[((i+1) % arrayLen)]);
            }
            printArray(arrayToSort, 20);
            if(runOnce == false) { unSorted = false; }
            if(i == arrayLen+1) { i = 0; }
            runOnce = false;
        }
    }
}

int medianValue(int array[], int arrLen) {
    double em = arrLen; //cast to float
    if(fmod(em, 2) == 0) { // ai ai ai begynner å gå tom for tid
        return array[(int(em/2))]+array[(int(em)/2)-1];
    } else {
        return array[(int(em)/2)];
    }
    return 0;
}


//Del 4 - Dette blir bare mer og mer uoversiktlig
void printArray(char arrayToPrint[], int arrayLen) {
    for(int i=0; i < arrayLen; ++i) {
        cout << arrayToPrint[i] << "  ";
    }
    cout << endl;
}

void randomizeCString(char arrayToPopulate[], int arrayLen, int lower, int upper) {   
    for(int i = 0; i < (arrayLen-1); ++i) {
        arrayToPopulate[i] = randomWithLimits(lower, upper, 1);
    }
    arrayToPopulate[arrayLen] = '\0';
}

void readInputToCString(char array[], int arrLen, int lower, int upper) {
    for(int i=0; i < arrLen; ++i) {array[i] = '0';}
    for(int i=0; i < arrLen; i++) {
        char inn;
        cin >> inn;
    
        if(toupper(inn) >= lower and toupper(inn) <= upper)
            { array[i] = toupper(inn); } else { i--;} 
    }

    array[arrLen] = '\0'; //bs
}
