#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H

#include "AbstractMethodUnit.h"
#include <vector>
#include <string>

/// @brief C++ метод
class CppMethodUnit : public AbstractMethodUnit
{
public:
    /// @brief Конструктор.
    /// @param[in] name Имя метода.
    /// @param[in] returnType Тип возвращаемого значения.
    /// @param[in] flags Флаги/модификаторы метода.
    CppMethodUnit( const std::string& name, const std::string& returnType, MethodModifier flags );

    /// @brief Деструктор
    ~CppMethodUnit() = default;

    /// @brief Формирует текстовое представление метода.
    /// @param[in] level Уровень отступа.
    /// @return Текст метода.
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CPPMETHODUNIT_H
