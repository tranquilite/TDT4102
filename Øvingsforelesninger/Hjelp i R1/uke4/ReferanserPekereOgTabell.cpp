#include <iostream>

using namespace std;

// Her er det viktig at a tas inn som referanse (call-by-reference), fordi vi ønsker
// å endre på a.
void plusEquals(int &a, int b) {
    a += b;
}

// PlusEquals kan også løses med pekere. Dette ser sånn ut:
void plusEquals(int *a, int b) {
    // Her må vi dereferere a, ved å skrive stjerne foran, for å få verdien pekeren peker på.
    *a += b;
}

int arraySum(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

int arraySearch(int array[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == element)
            return i;
    }
    return -1;
}


int main() {
    
    // Oppgave: plusEquals
    
    int A = 3;
    int B = 4;
    plusEquals(A, B);
    cout << A << endl; // Skriver ut 7.
    
    
    // Oppgave: arraySum
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    
    int length = 7; // Her teller jeg manuelt lengden på array-et, 7, og sender denne inn som argument.
    int sum = arraySum(array, length);

    cout << sum << endl; // Skriver ut 28, som er summen av tallene i array.
    
    
    // Oppgave: arraySearch
    int searchElement = 4;
    int index = arraySearch(array, length, searchElement); // Bruker array og length fra oppgaven over.
    
    cout << index << endl; // Skriver ut 3, som er indeksen til tallet 4 i array-et.
    
    
    // Gjennomgang: verdi, referanse og pointer.
    
    
    // * Å opprette verdier, referanser og pekere.
    
    int myValue = 5; // Oppretter en helt vanlig verdi-variabel med verdien 5;
    
    int &myReference = myValue; // myReference er nå en referanse. Denne fungerer her som et synonymt navn på myValue
    
    int *myPointer = &myValue;  // myPointer er nå en pointer. Den er initialisert med adressen til myValue.
                                //Det betyr at myPointer peker på myValue.
    
    
    // * Å endre på verdier, referanser og pekere
    
    myValue = 6; // En helt vanlig endring.
    
    myReference = 7; // Nå endres verdien til 7. Dette påvirker både myValue og myReference (de har samme verdi).
    cout << myValue << endl; // Skriver ut 7.
    
    *myPointer = 8; // Vi derefererer pekeren med stjerne foran myPointer, og får muligheten til å endre verdien det pekes på til 8.
    
    cout << myValue << ", " << myReference << ", " << *myPointer << endl;   // Skriver ut 8, 8, 8.
                                                                            //Vi har her tre måter å aksessere den samme verdien på.
    
    
    // * Rask titt på adressene til disse variablene.
    
    cout << &myValue << endl; // Skriver ut 0x7fff5fbff740 (hos meg). Dette er adressen i minnet myValue ligger i.
    cout << &myReference << endl; // Skriver ut 0x7fff5fbff740 (den samme). myReference er et annet navn på verdien til myValue. De deler adresse
    cout << myPointer << endl; // Skriver her ut innholdet i pekeren. Dette er den samme adressen som over.
    
    cout << &myPointer << endl; // Vi kan også skrive ut pekeren sin adresse. Denne er forskjellig. pointer-en har en egen plass i minne
                                // der den lagrer en verdi som her er lik adressen til myValue og myReference.
    
    
    return 0;
}
