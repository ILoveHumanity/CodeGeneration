#ifndef ABSTRACTMETHODUNIT_H
#define ABSTRACTMETHODUNIT_H

#include "unit.h"
#include "Modifiers.h"
#include <string>
#include <memory>
#include <vector>

// Абстрактный базовый класс для представления метода на любом языке
class AbstractMethodUnit : public Unit
{
public:
    explicit AbstractMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags);

    // Виртуальный деструктор
    virtual ~AbstractMethodUnit() = default;

    virtual std::string compile(unsigned int level = 0) const override = 0;

    void add( const std::shared_ptr< Unit >& unit, Flags flags = 0 ) override;

protected:
    std::string m_name; // Имя метода
    std::string m_returnType; // Тип возврата
    MethodModifier m_flags; // Флаги/модификаторы метода
    std::vector<std::shared_ptr<Unit>> m_body; // Тело метода (вектор выражений/операторов)
};

#endif // ABSTRACTMETHODUNIT_H
