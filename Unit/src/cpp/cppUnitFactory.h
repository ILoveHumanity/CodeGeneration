#ifndef CPPUNITFACTORY_H
#define CPPUNITFACTORY_H

#include "AbstractUnitFactory.h"
#include <memory>

class CppUnitFactory : public AbstractUnitFactory {
public:
    CppUnitFactory() = default;
    ~CppUnitFactory() = default;
    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const override;
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override;
};

#endif // CPPUNITFACTORY_H
