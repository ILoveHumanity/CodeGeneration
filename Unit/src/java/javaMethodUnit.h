#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include "AbstractMethodUnit.h"
#include <vector>
#include <string>

/// @brief Java метод
class JavaMethodUnit : public AbstractMethodUnit
{
public:
    /// @brief Конструктор.
    /// @param[in] name Имя метода.
    /// @param[in] returnType Тип возвращаемого значения.
    /// @param[in] flags Флаги/модификаторы метода.
    JavaMethodUnit( const std::string& name, const std::string& returnType, MethodModifier flags );

    /// @brief Деструктор
    ~JavaMethodUnit() = default;

    /// @brief Формирует текстовое представление метода.
    /// @param[in] level Уровень отступа.
    /// @return Текст метода.
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // JAVAMETHODUNIT_H
