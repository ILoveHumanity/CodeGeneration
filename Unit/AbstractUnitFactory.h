#ifndef ABSTRACTUNITFACTORY_H
#define ABSTRACTUNITFACTORY_H

#include <memory>
#include <string>
#include "unit.h"
#include "AbstractClassUnit.h"
#include "AbstractMethodUnit.h"
#include "AbstractPrintOperatorUnit.h"

class AbstractUnitFactory {
public:
    virtual ~AbstractUnitFactory() = default;

    virtual std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const = 0;
    virtual std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const = 0;
    virtual std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const = 0;
};


#endif // ABSTRACTUNITFACTORY_H
