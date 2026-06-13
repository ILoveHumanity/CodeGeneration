#include "cppUnitFactory.h"
#include "cppClassUnit.h"
#include "cppMethodUnit.h"
#include "cppPrintOperatorUnit.h"

std::shared_ptr<AbstractClassUnit> CppUnitFactory::createClassUnit(const std::string& name) const {
    return std::make_shared<CppClassUnit>(name);
}

std::shared_ptr<AbstractMethodUnit> CppUnitFactory::createMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags) const {
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

std::shared_ptr<AbstractPrintOperatorUnit> CppUnitFactory::createPrintOperatorUnit(const std::string& text) const {
    return std::make_shared<CppPrintOperatorUnit>(text);
}
