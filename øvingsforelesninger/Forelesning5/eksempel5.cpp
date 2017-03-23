/*
Dette er programmet som vart demonstrert i øvingsforelesninga Onsdag 15. februar 2017 (TDT4102)

Laga av undass Anna Rekdal
*/

#include <iostream>
#include <string>
using namespace std;

/*
Klassedefinisjonar, fins vanligvis i header-filer
*/

class Fraction {
private:
	int tellar;
	int nemnar;
public:
	Fraction() : tellar(1), nemnar(1) {}
	int getTellar() { return tellar; }
	void setTellar(int tellar);
	int getNemnar() { return nemnar; }
	void setNemnar(int nemnar);
	Fraction(int tel, int nem);
	double toDes();
};


class Me {
private:
	string firstName;
	string lastName;
	Fraction age;
public:
	Me(string first, string last, Fraction age) : firstName(first), lastName(last), age(age) {}
	Me(string first, string last) : Me(first, last, Fraction(22, 1)) {}
	Me() : firstName("Anna"), lastName("Rekdal"), age(Fraction(22, 1)) {}
	string getName() { return firstName + " " + lastName; }
	Fraction getAge() { return age; }
};

/*
Medlemsfunksjonasimplementasjonar, fins vanligvis i cpp-fila tilhørande klassa
*/

void Fraction::setTellar(int tellar) {
	this->tellar = tellar;
}

void Fraction::setNemnar(int nemnar) {
	if (nemnar == 0) {//å dele på 0 er berre tull
		this->nemnar = 1;
	}
	else {
		this->nemnar = nemnar;
	}
}

Fraction::Fraction(int tel, int nem) {
	tellar = tel;
	nemnar = nem;
}

double Fraction::toDes() {
	double a = static_cast<double>(tellar) / static_cast<double> (nemnar);
	return a;
}

class Useless {
private:
	int* a = new int;
public:
	Useless() { *a = 0; }
	void set(int b) { *a = b; }
	int* get() { return a; }
	~Useless() { delete a; }
};


/*
Main-funksjonen
*/

void main() {
	Me me1;
	cout << me1.getName() << endl;
	cout << me1.getAge().toDes() << endl;

	Fraction myAge;
	myAge.setTellar(283);
	myAge.setNemnar(4);

	Me me2("Donald", "Trump", myAge);
	cout << me2.getName() << endl;
	cout << me2.getAge().toDes() << endl;

	Me me3("Kari", "Nordmann");
	cout << me3.getName() << endl;
	cout << me3.getAge().toDes() << endl;


	Useless u;
	cout << *(u.get()) << endl;
	u.set(5);
	cout << *(u.get()) << endl;
	// SPM: Når blir destruktøren kalla?
}

