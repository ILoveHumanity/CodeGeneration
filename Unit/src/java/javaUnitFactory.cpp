#include "JavaUnitFactory.h"
#include "JavaClassUnit.h"
#include "JavaMethodUnit.h"
#include "JavaPrintOperatorUnit.h"

std::shared_ptr<AbstractClassUnit> JavaUnitFactory::createClassUnit(const std::string& name) const {
    return std::make_shared<JavaClassUnit>(name);
}

std::shared_ptr<AbstractMethodUnit> JavaUnitFactory::createMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags) const {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<AbstractPrintOperatorUnit> JavaUnitFactory::createPrintOperatorUnit(const std::string& text) const {
    return std::make_shared<JavaPrintOperatorUnit>(text);
}
