#ifndef ABSTRACTPRINTOPERATORUNIT_H
#define ABSTRACTPRINTOPERATORUNIT_H

#include "unit.h"
#include <string>
#include <memory>

// Абстрактный базовый класс для представления оператора/выражения печати на любом языке
class AbstractPrintOperatorUnit : public Unit
{
public:
    explicit AbstractPrintOperatorUnit(const std::string& text);

    // Виртуальный деструктор
    virtual ~AbstractPrintOperatorUnit() = default;

    virtual std::string compile(unsigned int level = 0) const override = 0;

protected:
    std::string m_text; // Текст для печати
};

#endif // ABSTRACTPRINTOPERATORUNIT_H
