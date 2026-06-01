#include <QCoreApplication>
#include "AbstractUnitFactory.h"
#include "cppUnitFactory.h"
#include "Modifiers.h"
#include <iostream>


std::string generateProgram(const AbstractUnitFactory& factory) {
    auto myClass = factory.createClassUnit( "MyClass" );
    myClass->add(factory.createMethodUnit( "testFunc1", "void", MethodModifier::UNDEFINED ), AccessModifier::PUBLIC );
    myClass->add(factory.createMethodUnit( "testFunc2", "void", MethodModifier::STATIC ), AccessModifier::PRIVATE );
    myClass->add(factory.createMethodUnit( "testFunc3", "void", MethodModifier::VIRTUAL | MethodModifier::CONST ), AccessModifier::PUBLIC );
    auto method = factory.createMethodUnit( "testFunc4", "void", MethodModifier::STATIC );
    method->add( factory.createPrintOperatorUnit( R"(Hello, world!\n)" ) );
    myClass->add( method, AccessModifier::PROTECTED );
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
