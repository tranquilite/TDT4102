#include<iostream>

#include"head.h"
#include"3.h"

void testEmnekatalog() {
    CourseCatalog T;

    T.addCourse("TDT", "Test");
    std::cout << T;
    std::cout << "\n-------------------" << std::endl;

    T.removeCourse("TDT");

    T.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    T.addCourse("TMA4100", "Matematikk 1");
    T.addCourse("TDT4110", "Informasjonsteknologi - Grunnkurs");
    std::cout << "T etter addCourse() x3:\n";
    std::cout << T;
    std::cout << "\n-------------------" << std::endl;

    T.updateCourse("TDT4102", "C++");
    std::cout << "T etter updateCourse():\n";
    std::cout << T;
    std::cout << "\n-------------------" << std::endl;

    T.writeCatalogToFile("maptest.txt");
    T.testClearCatalogue();

    std::cout <<"T etter clear:\n";
    std::cout << T;
    std::cout << "\n-------------------" << std::endl;

    T.readFileToCatalog("maptest.txt");
    std::cout << "T etter readFileToCatalog():\n";
    std::cout << T;
    std::cout << "\n-------------------" << std::endl;
}
