#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "AbstractMethodUnit.h"
#include <vector>
#include <string>

/// @brief C# метод
class CSharpMethodUnit : public AbstractMethodUnit
{
public:
    /// @brief Конструктор.
    /// @param[in] name Имя метода.
    /// @param[in] returnType Тип возвращаемого значения.
    /// @param[in] flags Флаги/модификаторы метода.
    CSharpMethodUnit( const std::string& name, const std::string& returnType, MethodModifier flags );

    /// @brief Деструктор
    ~CSharpMethodUnit() = default;

    /// @brief Формирует текстовое представление метода.
    /// @param[in] level Уровень отступа.
    /// @return Текст метода.
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CSHARPMETHODUNIT_H
