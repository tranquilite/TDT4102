#include<map>
#include<iostream>
#include<string>
#include<fstream>

#include"head.h"
#include"3.h"

// TDT4102" -> "Prosedyre- og objektorientert- programmering"

void CourseCatalog::addCourse(std::string kode, std::string emne) {
    //Nødvendig å sjekke at et element ikke er i tabellen før den legges til.
    //updatCourse() er agnostisk til allerede eksisterende elementer, mens
    //addCourse trenger å bry seg.
    auto sok = emner.find(kode);
    if( sok == emner.end() ) {
        emner[kode] = emne;
    } else {
        std::cout << "\n\t" << kode << " allerede i tabell.\n";
    }
}

void CourseCatalog::updateCourse(std::string kode, std::string emne) {
    //Agnostisk til hvorvidt et element allerede eksisterer.
    //Oppdater hvis finnes, skap hvis ikke.
    emner[kode] = emne;
}

void CourseCatalog::removeCourse(std::string kode) {
    auto sok = emner.find(kode);
    if( sok == emner.end() ) {
        std::cout << "\n\t" << kode << " ikke funnet.";
    } else {
        emner.erase(kode);
    }
}

int CourseCatalog::writeCatalogToFile(std::string fileName) const {
    std::ofstream fil;
    fil.open(fileName);

    if(fil.is_open()) {
        CSVOutput(fil);
        return 1;
    } else { //Hvis lukket, skriv varsel
        std::cout << "\n\twriteCatalogToFile - ~is_open()!!\n";
    } //Hvis is_open(), avslutt i if(), hvis ~is_open, avslutt ved logisk slutt med 0
    return 0;
}

int CourseCatalog::readFileToCatalog(std::string fileName) {
    std::fstream fil;
    fil.open(fileName);

    if(fil.is_open()) {
        std::string linje;
        std::string kode;
        std::string emne;

        std::getline(fil, linje);

        while(!fil.eof()) {
            //std::cout << "L63: " << linje << std::endl;
            this->addCourse(linje.substr(0,7), linje.substr(8));
            //std::cout << "L65: " << linje << std::endl;
            std::getline(fil, linje);
        }
    }
    return 0;
}


int CourseCatalog::CSVOutput (std::ostream& stream) const {
    //Note: Returntypen trenger ikke være ostream
    //Denne kan ha uforutsette bivirkninger på stream-objektet den tar inn!

    //Ville egentlig gjøre det til noe som lignet på JSON, men wth. Go CSV
    for(auto& lookup: this->emner) {
        stream << lookup.first << "," << lookup.second << std::endl;
    }
    return 1;
}

void CourseCatalog::testClearCatalogue() { emner.clear(); }

const std::ostream& operator<< (std::ostream& stream, CourseCatalog& C) {
    for(auto& lookup: C.emner) {
        stream << lookup.first << " " << lookup.second << std::endl;
    }
    return stream;
}

