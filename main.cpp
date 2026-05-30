#include <QCoreApplication>
#include "AbstractUnitFactory.h"
#include "cppUnitFactory.h"
#include <iostream>
#include "cppClassUnit.h"
#include "cppMethodUnit.h"
#include "cppPrintOperatorUnit.h"

std::string generateProgram(const AbstractUnitFactory& factory) {
    auto myClass = factory.createClassUnit( "MyClass" );
    myClass->add(factory.createMethodUnit( "testFunc1", "void", 0 ), CppClassUnit::PUBLIC);
    myClass->add(factory.createMethodUnit( "testFunc2", "void", CppMethodUnit::STATIC ), CppClassUnit::PRIVATE );
    myClass->add(factory.createMethodUnit( "testFunc3", "void", CppMethodUnit::VIRTUAL | CppMethodUnit::CONST ), CppClassUnit::PUBLIC );
    auto method = factory.createMethodUnit( "testFunc4", "void", CppMethodUnit::STATIC );
    method->add( factory.createPrintOperatorUnit( R"(Hello, world!\n)" ) );
    myClass->add( method, CppClassUnit::PROTECTED );
    return myClass->compile();
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    try {
        CppUnitFactory cppFactory;
        std::cout << generateProgram(cppFactory) << std::endl;
    } catch (...) {
        std::cerr << "Error: unknown exception\n";
        return 1;
    }
    return 0;
    //return a.exec();
}
