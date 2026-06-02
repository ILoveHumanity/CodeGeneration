#ifndef ABSTRACTPRINTOPERATORUNIT_H
#define ABSTRACTPRINTOPERATORUNIT_H

#include "unit.h"
#include <string>
#include <memory>

/// @brief Абстрактный базовый класс для представления оператора печати на любом языке
class AbstractPrintOperatorUnit : public Unit
{
public:
    /// @brief Конструктор.
    /// @param[in] text Текст для печати.
    explicit AbstractPrintOperatorUnit(const std::string& text);

    /// @brief Виртуальный деструктор
    virtual ~AbstractPrintOperatorUnit() = default;

    /// @brief Формирует текстовое представление оператора печати.
    /// @param[in] level Уровень отступа.
    /// @return Текст оператора печати.
    virtual std::string compile(unsigned int level = 0) const override = 0;

protected:
    std::string m_text; ///< Текст для печати
};

#endif // ABSTRACTPRINTOPERATORUNIT_H
