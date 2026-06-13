#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include "AbstractPrintOperatorUnit.h"
#include <string>

/// @brief Java оператор печати
class JavaPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    /// @brief Конструктор.
    /// @param[in] text Текст для печати.
    explicit JavaPrintOperatorUnit( const std::string& text );

    /// @brief Деструктор
    ~JavaPrintOperatorUnit() = default;

    /// @brief Формирует текстовое представление оператора печати.
    /// @param[in] level Уровень отступа.
    /// @return Текст оператора печати.
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // JAVAPRINTOPERATORUNIT_H
