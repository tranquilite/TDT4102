/*
Oppgåve til øvingsforelesning 15. februar 2017 (TDT4102)

MERK: Vi rakk ikkje å gjennomføre dette i forelesninga, men oppgåveteksten ligg i slidane frå forelesninga.

Den koden som er meint å vere utdelt ligg først i denne fila (linje 11-43). Løysingsforlag er kommentert ut i botnen av fila. Prøv å finne på ei eiga løysing først.

Laga av vitass Sivert Krøvel
*/

#include<iostream>

class ComplexNumber {
private:
	double imag, real;

public:
	ComplexNumber(double r, double i) : imag(i), real(r) {};
	ComplexNumber() : ComplexNumber(0.0, 0.0) {};

	double getReal() const { return real; };
	double getImag() const { return imag; };
};

/*
Implementer operatorar her (LF ligg i botnen av fila)
*/



int main() {
	ComplexNumber c1;
	ComplexNumber c2(4, 7.5);
	ComplexNumber c3(0.5, -3.5);

	//Her testar vi <<-operatoren for utskrift
	//Test også dei andre operatorane du implementerer
	/*std::cout << "c1: " << c1 << std::endl
		<< "c2: " << c2 << std::endl
		<< "c3: " << c3 << std::endl << std::endl
		<< "c2 + c3: " << c2+c3 << std::endl;
	*/
}



/*
LØYSINGSFORSLAG
Implementerer + og -, i tillegg til << operatoren. Her er ikkje implementert som medlemsfunksjonar, men nokre av dei kan fint vere det, dersom du ønsker

Legg merke til bruken av const. Ingen av desse operatorane ønsker å endre på dei komplekse tala vi brukar som operandar
*/















/*
ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return ComplexNumber(lhs.getReal() + rhs.getReal(), lhs.getImag() + rhs.getImag());
}

ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs) {
	return ComplexNumber(lhs.getReal() - rhs.getReal(), lhs.getImag() - rhs.getImag());
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber c) {
	os << c.getReal();
	double imag = c.getImag();
	if (imag < 0) //vi skriv ikkje ut j0
		os << " - j" << -c.getImag();
	else if (imag > 0)
		os << " + j" << c.getImag();

	return os;
}
*/
/*
Hugs å deklarere operatorane på toppen av fila, slik at vi kan bruke dei i main:

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);
std::ostream& operator<<(std::ostream& os, const ComplexNumber c);
*/