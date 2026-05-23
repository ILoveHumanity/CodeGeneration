#include <QCoreApplication>
#include "cppClassUnit.h"
#include "cppMethodUnit.h"
#include "cppPrintOperatorUnit.h"
#include <iostream>


std::string generateProgram() {
    CppClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc1", "void", 0 ),
        CppClassUnit::PUBLIC
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc2", "void", CppMethodUnit::STATIC ),
        CppClassUnit::PRIVATE
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc3", "void", CppMethodUnit::VIRTUAL |
                                                              CppMethodUnit::CONST ),
        CppClassUnit::PUBLIC
        );
    auto method = std::make_shared< CppMethodUnit >( "testFunc4", "void",
                                               CppMethodUnit::STATIC );
    method->add( std::make_shared< CppPrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, CppClassUnit::PROTECTED );
    return myClass.compile();
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    try {
        std::cout << generateProgram() << std::endl;
    } catch (...) {
        std::cerr << "Error: unknown exception\n";
        return 1;
    }
    return 0;
    //return a.exec();
}
