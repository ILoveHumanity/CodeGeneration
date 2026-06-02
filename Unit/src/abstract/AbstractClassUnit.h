#ifndef ABSTRACTCLASSUNIT_H
#define ABSTRACTCLASSUNIT_H

#include "unit.h"
#include "Modifiers.h"
#include <string>
#include <memory>

// Абстрактный базовый класс для представления класса на любом языке
class AbstractClassUnit : public Unit
{
public:
    explicit AbstractClassUnit(const std::string& name);

    // Виртуальный деструктор
    virtual ~AbstractClassUnit() = default;

    virtual std::string compile( unsigned int level = 0 ) const = 0;

    using Unit::add;
    virtual void add( const std::shared_ptr< Unit >& unit, AccessModifier flags ) = 0;

protected:
    std::string m_name; // Имя класса
};

#endif // ABSTRACTCLASSUNIT_H
