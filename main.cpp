#include <QCoreApplication>
#include "AbstractUnitFactory.h"
#include "cppUnitFactory.h"
#include "csharpUnitFactory.h"
#include "javaUnitFactory.h"
#include "Modifiers.h"
#include <iostream>


std::string generateProgramCpp(const AbstractUnitFactory& factory) {
    auto myClass = factory.createClassUnit( "MyClass" );
    myClass->add(factory.createMethodUnit( "testFunc1", "void", MethodModifier::UNDEFINED ), AccessModifier::PUBLIC );
    myClass->add(factory.createMethodUnit( "testFunc2", "void", MethodModifier::STATIC ), AccessModifier::PRIVATE );
    myClass->add(factory.createMethodUnit( "testFunc3", "void", MethodModifier::VIRTUAL | MethodModifier::CONST ), AccessModifier::PUBLIC );
    auto method = factory.createMethodUnit( "testFunc4", "void", MethodModifier::STATIC );
    method->add( factory.createPrintOperatorUnit( R"(Hello, world!\n)" ) );
    myClass->add( method, AccessModifier::PROTECTED );
    return myClass->compile();
}

std::string generateProgramCSharp(const AbstractUnitFactory& factory) {
    auto myClass = factory.createClassUnit( "MyClass" );
    myClass->add(factory.createMethodUnit( "testFunc1", "void", MethodModifier::UNDEFINED ), AccessModifier::PUBLIC );
    myClass->add(factory.createMethodUnit( "testFunc2", "void", MethodModifier::STATIC ), AccessModifier::PRIVATE );
    myClass->add(factory.createMethodUnit( "testFunc3", "void", MethodModifier::VIRTUAL ), AccessModifier::PUBLIC );
    auto method = factory.createMethodUnit( "testFunc4", "void", MethodModifier::STATIC );
    method->add( factory.createPrintOperatorUnit( R"(Hello, world!\n)" ) );
    myClass->add( method, AccessModifier::PROTECTED );
    return myClass->compile();
}

std::string generateProgramJava(const AbstractUnitFactory& factory) {
    auto myClass = factory.createClassUnit( "MyClass" );
    myClass->add(factory.createMethodUnit( "testFunc1", "void", MethodModifier::UNDEFINED ), AccessModifier::PUBLIC );
    myClass->add(factory.createMethodUnit( "testFunc2", "void", MethodModifier::STATIC ), AccessModifier::PRIVATE );
    myClass->add(factory.createMethodUnit( "testFunc3", "void", MethodModifier::UNDEFINED ), AccessModifier::PUBLIC );
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
        CSharpUnitFactory csharpFactory;
        JavaUnitFactory javaFactory;
        std::cout << generateProgramCpp(cppFactory) << std::endl;
        std::cout << generateProgramCSharp(csharpFactory) << std::endl;
        std::cout << generateProgramJava(javaFactory) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "Error: unknown exception\n";
        return 1;
    }
    return 0;
    //return a.exec();
}
