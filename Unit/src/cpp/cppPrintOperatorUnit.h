#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H

#include "AbstractPrintOperatorUnit.h"
#include <string>

/// @brief C++ оператор печати
class CppPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    /// @brief Конструктор.
    /// @param[in] text Текст для печати.
    explicit CppPrintOperatorUnit( const std::string& text );

    /// @brief Деструктор
    ~CppPrintOperatorUnit() = default;

    /// @brief Формирует текстовое представление оператора печати.
    /// @param[in] level Уровень отступа.
    /// @return Текст оператора печати.
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CPPPRINTOPERATORUNIT_H
