#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H

#include "AbstractPrintOperatorUnit.h"
#include <string>

/// @brief C# оператор печати
class CSharpPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    /// @brief Конструктор.
    /// @param[in] text Текст для печати.
    explicit CSharpPrintOperatorUnit( const std::string& text );

    /// @brief Деструктор
    ~CSharpPrintOperatorUnit() = default;

    /// @brief Формирует текстовое представление оператора печати.
    /// @param[in] level Уровень отступа.
    /// @return Текст оператора печати.
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CSHARPPRINTOPERATORUNIT_H
