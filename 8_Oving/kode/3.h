#pragma once

#include<iostream>
#include<map>
#include<string>

class CourseCatalog {
    private:
        std::map<std::string, std::string> emner;

        int CSVOutput(std::ostream&) const;

    public:
        void addCourse(std::string, std::string);
        void updateCourse(std::string, std::string);
        void removeCourse(std::string);

        int writeCatalogToFile(std::string fileName) const;
        int readFileToCatalog(std::string fileName);

        void testClearCatalogue();
        //Til forbedring: operator<< skal være i åpent namespace, men det er
        //i noen tilfeller greit at den kan lese ting som er merket private,
        //og droppe get-funksjon.
        //Burde vært merket som friend tidligere, men gjør det fom nå.
        //ellers fin vane å ha operator-overloads i klassedefinisjonen.
        friend const std::ostream& operator<< (std::ostream&, CourseCatalog&);
};
