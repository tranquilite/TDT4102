/*
TDT4102 - Prosedyre- og Objektorientert programmering
Øving 1
*/
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

double discriminant(double, double, double);    //prototype
void printRealRoots(double, double, double);    //prototype

double discriminant(double a, double b, double c) {
    double disk;                //initialiser
    disk = pow(b,2) - 4*a*c;    //når vi først har lastet cmath
    return disk;                //returner
}


void printRealRoots(double a, double b, double c) {
    double root1, root2;
    double disk = discriminant(a, b, c);
    if(disk < 0) {                                  // b^2 - 4ac < 0
        cout << "Likningen har ingen løsning\n";    // Nu er det min arbeidslyst
        return;                                     // som forlater skrivebordet
    } else if(disk == 0) {                          //(likeså forlater vi rutinen)
        root1 = ((-1)*b)/2*a;                       //hvis b^2 == 4ac
        cout << "Likningen har én løsning: " << root1 << endl;
    } else if(disk > 0) {
        root1 = ((-1)*b + sqrt(disk))/2*a;
        root2 = ((-1)*b - sqrt(disk))/2*a;
        cout << "Mulig at likningen har to løsninger: " << root1
             << " og " << root2 << endl;
    } else {
        cout << "Dette burde ikke skje.\n\n";     //Fail-deadly
    }    

    return;                                         //se php og die()
}

void solveQuadraticEquation() {
    double a = 1, b = 1, c = 1;
    cout << "Gitt en andregradsuttrykk av formen ax^2 + bc + c, oppgi verdier "
         << "for a, b, og c\n " << "a = ";          // vi antar .. prior
    cin  >> a;                                      // knowledge
    cout << "b = ";
    cin  >> b;
    cout << "c = ";
    cin  >> c;

    printRealRoots(a, b, c);
}

int main() {
    solveQuadraticEquation();
    return 0;
}
