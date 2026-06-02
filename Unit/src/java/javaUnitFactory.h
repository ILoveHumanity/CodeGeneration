#ifndef JAVAUNITFACTORY_H
#define JAVAUNITFACTORY_H

#include "AbstractUnitFactory.h"
#include <memory>

class JavaUnitFactory : public AbstractUnitFactory {
public:
    JavaUnitFactory() = default;
    ~JavaUnitFactory() = default;

    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const override;
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags) const override;
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override;
};

#endif // JAVAUNITFACTORY_H
