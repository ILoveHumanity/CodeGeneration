#include "CSharpUnitFactory.h"
#include "CSharpClassUnit.h"
#include "CSharpMethodUnit.h"
#include "CSharpPrintOperatorUnit.h"

std::shared_ptr<AbstractClassUnit> CSharpUnitFactory::createClassUnit(const std::string& name) const {
    return std::make_shared<CSharpClassUnit>(name);
}

std::shared_ptr<AbstractMethodUnit> CSharpUnitFactory::createMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags) const {
    return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
}

std::shared_ptr<AbstractPrintOperatorUnit> CSharpUnitFactory::createPrintOperatorUnit(const std::string& text) const {
    return std::make_shared<CSharpPrintOperatorUnit>(text);
}
